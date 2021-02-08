#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000L

void head() {
	printf("====================\n");
	printf("�а�:���̹���������\n");
	printf("�й�:1971090\n");
	printf("����:�ѱٿ�\n");
	printf("====================\n");
}

typedef struct GraphNode { //�� ��忡 ���� ����ü
	int vertex; //����
	int weight; //����ġ
	struct GraphNode* link; //edge
}GraphNode;

typedef struct GraphType {
	int n; //������ ����
	GraphNode* adj_list[MAX_VERTICES];
}GraphType;

int found[MAX_VERTICES]; //���õ� vertex�� ����
int distance[MAX_VERTICES]; //spanning tree���� vertex���� �� vertex������ distance

int choose(int distance[], int n, int found[]) {//sp�������κ��� ���� ª�� distance�� ���� vertex ��ȯ
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for (i = 0; i < n; i++) {
		if (distance[i] < min && !found[i]) {
			min = distance[i]; //���� ���� �� �� �ּҰŸ� vertex ã��
			minpos = i;
		}
	}
	return minpos;
}

void print_status(GraphType* g) { //�ܰ躰�� ��Ȳ ������ִ� �Լ�
	static int step = 1;
	printf("STEP %d: \n", step++);
	printf("  distance: "); //���Ӱ� ������Ʈ�� distance�� ���
	for (int i = 0; i < g->n; i++) {
		if (distance[i] == INF) printf(" * "); //���Ѵ� ���� ���� ���
		else printf("%2d ", distance[i]);
	}
	printf("\n");
	printf("  found: "); //ã�� ������ ���� �� ã�� ���� 1�� 0���� ���
	for (int i = 0; i < g->n; i++) {
		printf("%2d ", found[i]);
	}
	printf("\n\n");
}

void shortest_path(GraphType* g, int start) { //dijkstra �ִܰ�� ã�� �Լ�
	int i, u, w;
	for (i = 0; i < g->n; i++) {
		found[i] = FALSE; //�� vertex �������� �ʱ�ȭ
		for (GraphNode* node = g->adj_list[start]; node != NULL; node = node->link) { //start vertex�� ����� ��带 ���캸�鼭
			if (node->vertex == i) {
				distance[i] = node->weight; //distance�� start vertex�κ����� weight ����
				break;
			}
			else if(node->link==NULL) distance[i] = INF; //���� ��� ���������� ���� �� �� ���̹Ƿ� ���Ѵ�� �ʱ�ȭ
		}
	}
	found[start] = TRUE; //���� vertex �湮 ǥ��
	distance[start] = 0;
	for (i = 0; i < g->n; i++) { //start �����ϰ� ������ n-1�� vertex�� üũ
		print_status(g); //���� ���� ���
		u = choose(distance, g->n, found); //���� vertex �� distance�� ���� ª�� vertex
		found[u] = TRUE; //�ش� vertex u�� ���տ� �߰�
		
		for (w = 0; w < g->n; w++) { 
			if (!found[w]) { //���� �� �� ��� vertex w�� ���Ͽ�
				GraphNode* cmp = g->adj_list[u]->link;
				for (cmp; cmp != NULL; cmp = cmp->link) {
					if (cmp->vertex == w) break;
				}
				if (cmp!=NULL && (distance[u] + cmp->weight < distance[w])) //������ distance������ u�� ���ļ� w�� ���� �Ÿ��� ª����
					distance[w] = distance[u] + cmp->weight; //���ο� distance������ ������Ʈ
			}
		}
	}
}

void init(GraphType* g) { //GraphType �ʱ�ȭ�ϴ� �Լ�
	g->n = 0; //���� ���� �ʱ�ȭ
	for (int i = 0; i < MAX_VERTICES; i++) {
		g->adj_list[i] = NULL;
	}
}

void insert_vertex(GraphType* g, int v) { //���� �����ϴ� �Լ�
	GraphNode* node = (GraphNode*)malloc(sizeof(GraphNode)); //���ο� ��� ����
	node->vertex = v; //vertex �� ����
	node->link = NULL;
	node->weight = 0; //����ġ�� 0����
	g->adj_list[v] = node;
	g->n++; //���� ���� ����
}

void insert_edge(GraphType* g, int start, int end, int w) { //edge �����ϴ� �Լ�
	GraphNode* node = (GraphNode*)malloc(sizeof(GraphNode)); //���ο� ��� ����
	node->vertex = end; //������ end vertex���� ����
	node->link = NULL;
	node->weight = w; //����ġ �� ����
	if(g->adj_list[start]->link==NULL) g->adj_list[start]->link = node; //���� ������ ����� ù edge��� �ٷ� ����
	else { //���� edge�� �� �ϳ����
		GraphNode* pre = g->adj_list[start];
		GraphNode* i;
		for (i = g->adj_list[start]->link; i != NULL; i = i->link) { //������ ��ġ�� ã�Ƽ� ��� ����
			if (i->vertex < node->vertex) {
				node->link = i;
				pre->link = node;
				return;
			}
			pre = i;
		}
		pre->link = node; //pre ��ġ �� ������Ʈ
	}	
}

void print_graph(GraphType* g) { //��ü�� �׷��� ����ϴ� �Լ�
	for (int i = 0; i < g->n; i++) {
		printf("vertex %d ", i); //�� vertex�� ���Ͽ� ���
		GraphNode* j = g->adj_list[i]->link;
		while (j!=NULL) {
			printf("  -> %d<%d>", j->vertex, j->weight); //vertex�� ����� �Ǵٸ� vertex���� ����ġ���� �Բ� ���
			j = j->link;
		}
		printf("\n");
	}
}


int main(void) {
	head();

	GraphType* g; //�׷��� g
	g = (GraphType*)malloc(sizeof(GraphType));
	init(g); //g �ʱ�ȭ
	for (int i = 0; i < 7; i++) {
		insert_vertex(g, i); //7���� vertex �߰�
	}
	//edge ���� ����
	insert_edge(g, 0, 1, 7);
	insert_edge(g, 0, 4, 3);
	insert_edge(g, 0, 5, 10);
	insert_edge(g, 1, 0, 7);
	insert_edge(g, 1, 2, 4);
	insert_edge(g, 1, 3, 10);
	insert_edge(g, 1, 4, 2);
	insert_edge(g, 1, 5, 6);
	insert_edge(g, 2, 1, 4);
	insert_edge(g, 2, 3, 2);
	insert_edge(g, 3, 1, 10);
	insert_edge(g, 3, 2, 2);
	insert_edge(g, 3, 4, 11);
	insert_edge(g, 3, 5, 9);
	insert_edge(g, 3, 6, 4);
	insert_edge(g, 4, 0, 3);
	insert_edge(g, 4, 1, 2);
	insert_edge(g, 4, 3, 11);
	insert_edge(g, 4, 6, 5);
	insert_edge(g, 5, 0, 10);
	insert_edge(g, 5, 1, 6);
	insert_edge(g, 5, 3, 9);
	insert_edge(g, 6, 3, 4);
	insert_edge(g, 6, 4, 5);

	printf("<Graph ����>\n");
	print_graph(g); //graph ���� ���
	int start;
	printf("\n���� vertex ��ȣ:");
	scanf("%d", &start); //���� vertex ��ȣ �Է¹ޱ�
	printf("\n<Shortest Path from vertex %d>\n", start);
	shortest_path(g, start); //dijkstra �ִܰ�� ã�Ƽ� ���
	free(g); 
	return 0;
}
