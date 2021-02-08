#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICS 50

void head() {
	printf("====================\n");
	printf("�а�:���̹���������\n");
	printf("�й�:1971090\n");
	printf("����:�ѱٿ�\n");
	printf("====================\n");
}

int visited[MAX_VERTICS];  //�湮�ߴ��� ���θ� �Ǵ��ϱ� ���� �迭

typedef struct GraphType { //�׷����� ���� ����ü
	int n; //vertex�� ��
	int adj_mat[MAX_VERTICS][MAX_VERTICS];
}GraphType;

void init(GraphType* g) { //�׷��� �ʱ�ȭ��Ű�� �Լ�
	int r, c;
	g->n = 0;
	for (r = 0; r < MAX_VERTICS; r++) {
		for (c = 0; c < MAX_VERTICS; c++) {
			g->adj_mat[r][c] = 0; //��� ���Ҹ� 0���� �ʱ�ȭ
		}
	}
}

void insert_vertex(GraphType* g, int v) { //vertex �����ϴ� �Լ�
	if (g->n + 1 > MAX_VERTICS) {
		fprintf(stderr, "�׷���:������ ���� �ʰ�\n"); //���� ���
		return;
	}
	else g->n++; //vertex ���� ����
}

void insert_edge(GraphType* g, int start, int end) { //edge �����ϴ� �Լ�(undirected���� ��Ī�� ���)
	if (start >= g->n || end >= g->n) {
		fprintf(stderr, "�׷���:���� ��ȣ ����\n"); //���� ���
		return;
	}
	g->adj_mat[start][end] = 1; //��Ī ��ġ�� ��� 1�� ����
	g->adj_mat[end][start] = 1;
}

void insert_edge2(GraphType* g, int start, int end) { //edge �����ϴ� �Լ�(directed���� ���Ī�� ���)
	if (start >= g->n || end >= g->n) {
		fprintf(stderr, "�׷���:���� ��ȣ ����\n"); //���� ���
		return;
	}
	g->adj_mat[start][end] = 1; //�ش� ��ġ���� 1�� ����
}

void print_adj_mat(GraphType* g) { //�׷��� ����ϴ� �Լ�
	int r, c;
	for (r = 0; r < g->n; r++) {
		for (c = 0; c < g->n; c++) {
			printf("%2d", g->adj_mat[r][c]); //���ó�� �׷��� ���
		}
		printf("\n");
	}
}

void dfs_mat(GraphType* g, int v) {
	int w;
	visited[v] = true; //dfs ���۵� vertex�� �湮�� ������ ǥ��
	printf("vertex%d  ", v); //�湮�� vertex ���
	for (w = 0; w < g->n; w++) { //�ش� vertex�� row�� �ϳ��� �˻��ؼ�
		if (g->adj_mat[v][w] && !visited[w]) { //���� 1�ε� ���� �湮���� �ʾ�����
			dfs_mat(g, w); //��� ȣ��
		}
	}
}

int stack[MAX_VERTICS]; //���� ����
int top = -1; //top �ʱ�ȭ

int pop(void) { //���� pop �Լ�
	if (top == -1) {
		printf("Stack empty");
		exit(1);
	}
	else return stack[top--]; //top ��ġ�� �ִ� �� ��ȯ �� top �� 1 ���̱�
}

void push(int item) { //���� push �Լ�
	if (top == MAX_VERTICS - 1) {
		printf("Stack empty");
		exit(1);
	}
	else stack[++top] = item; //top ���� 1 ������Ų �� �� ��ġ�� ���ڷ� ���� �� �����ϱ�
}
void dfs_stack(GraphType* g, int v) { //������ �̿��� dfs ���ϱ�
	push(v); //���ڷ� ���� ���� ���ÿ� push
	while (top != -1) { //������ ������� ������ ���� �ݺ�
		v = pop(); //���ÿ��� pop�� ���� v�� ����
		if (!visited[v]) { //���� v�� �湮���� �ʾ�����
			visited[v] = true; //v �湮�Ǿ��ٰ� ǥ��
			printf("vertex%d  ", v); //vertex ����Ʈ�ϱ�
			for (int w = 0; w < g->n; w++) { //v�� ������ ������ ���Ͽ�
				if (g->adj_mat[v][w] && !visited[w]) { //���� ���� �湮���� �ʾҴٸ�
					push(w); //���ÿ� push
				}
			}

		}
	}
}

void init_visited(GraphType* g) { //�湮�Ǿ����� ���� �Ǵ��ϴ� �迭 �ʱ�ȭ
	for (int i = 0; i < MAX_VERTICS; i++) {
		visited[i] = 0; //0���� ��� �ʱ�ȭ
	}
}
int main(void) {
	head();

	GraphType* g; //������ ���� ����
	g = (GraphType*)malloc(sizeof(GraphType)); //�����Ҵ�
	init(g); //�׷��� �ʱ�ȭ
	for (int i = 0; i < 5; i++) {
		insert_vertex(g, i);
	}
	//undirected ��Ī������ ���� �׷���
	insert_edge(g, 0, 1);
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 3);
	insert_edge(g, 1, 4);
	insert_edge(g, 2, 4);

	printf("<Graph Matrix>\n");
	print_adj_mat(g); //�׷��� ��� ���
	printf("<Depth Fisrt Search-recursive>\n");
	dfs_mat(g, 0); //���ȣ�� �̿��� ��� ���
	init_visited(g); //�湮���� �迭 �ʱ�ȭ
	printf("\n<Depth First Search-stack>\n");
	dfs_stack(g, 0); //���� �̿��� ��� ���

	init(g); //�׷��� �ʱ�ȭ
	for (int i = 0; i < 6; i++) {
		insert_vertex(g, i);
	}
	//directed ���Ī ������ ���� �׷���
	insert_edge2(g, 0, 2);
	insert_edge2(g, 0, 4);
	insert_edge2(g, 2, 1);
	insert_edge2(g, 2, 3);
	insert_edge2(g, 1, 5);
	insert_edge2(g, 4, 5);

	init_visited(g);//�湮���� �迭 �ʱ�ȭ
	printf("\n\n<Graph Matrix>\n");
	print_adj_mat(g); //�׷��� ��� ���
	printf("<Depth Fisrt Search-recursive>\n");
	dfs_mat(g, 0); //���ȣ�� �̿��� ��� ���
	init_visited(g); //�湮���� �迭 �ʱ�ȭ
	printf("\n<Depth First Search-stack>\n");
	dfs_stack(g, 0);//���� �̿��� ��� ���

	free(g); //�����Ҵ��� �� free
}