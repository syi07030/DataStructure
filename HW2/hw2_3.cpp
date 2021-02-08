#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000L

void head() {
	printf("====================\n");
	printf("학과:사이버보안전공\n");
	printf("학번:1971090\n");
	printf("성명:한근영\n");
	printf("====================\n");
}

typedef struct GraphNode { //각 노드에 대한 구조체
	int vertex; //정점
	int weight; //가중치
	struct GraphNode* link; //edge
}GraphNode;

typedef struct GraphType {
	int n; //정점의 개수
	GraphNode* adj_list[MAX_VERTICES];
}GraphType;

int found[MAX_VERTICES]; //선택된 vertex의 집합
int distance[MAX_VERTICES]; //spanning tree내의 vertex에서 각 vertex까지의 distance

int choose(int distance[], int n, int found[]) {//sp집합으로부터 가장 짧은 distance를 갖는 vertex 반환
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for (i = 0; i < n; i++) {
		if (distance[i] < min && !found[i]) {
			min = distance[i]; //아직 선택 안 된 최소거리 vertex 찾기
			minpos = i;
		}
	}
	return minpos;
}

void print_status(GraphType* g) { //단계별로 상황 출력해주는 함수
	static int step = 1;
	printf("STEP %d: \n", step++);
	printf("  distance: "); //새롭게 업데이트한 distance값 출력
	for (int i = 0; i < g->n; i++) {
		if (distance[i] == INF) printf(" * "); //무한대 값을 갖는 경우
		else printf("%2d ", distance[i]);
	}
	printf("\n");
	printf("  found: "); //찾은 정점과 아직 못 찾은 정점 1과 0으로 출력
	for (int i = 0; i < g->n; i++) {
		printf("%2d ", found[i]);
	}
	printf("\n\n");
}

void shortest_path(GraphType* g, int start) { //dijkstra 최단경로 찾는 함수
	int i, u, w;
	for (i = 0; i < g->n; i++) {
		found[i] = FALSE; //빈 vertex 집합으로 초기화
		for (GraphNode* node = g->adj_list[start]; node != NULL; node = node->link) { //start vertex와 연결된 노드를 살펴보면서
			if (node->vertex == i) {
				distance[i] = node->weight; //distance에 start vertex로부터의 weight 저장
				break;
			}
			else if(node->link==NULL) distance[i] = INF; //없을 경우 직접적으로 연결 안 된 것이므로 무한대로 초기화
		}
	}
	found[start] = TRUE; //시작 vertex 방문 표시
	distance[start] = 0;
	for (i = 0; i < g->n; i++) { //start 제외하고 나머지 n-1개 vertex만 체크
		print_status(g); //현재 상태 출력
		u = choose(distance, g->n, found); //남은 vertex 중 distance가 가장 짧은 vertex
		found[u] = TRUE; //해당 vertex u를 집합에 추가
		
		for (w = 0; w < g->n; w++) { 
			if (!found[w]) { //선택 안 된 모든 vertex w에 대하여
				GraphNode* cmp = g->adj_list[u]->link;
				for (cmp; cmp != NULL; cmp = cmp->link) {
					if (cmp->vertex == w) break;
				}
				if (cmp!=NULL && (distance[u] + cmp->weight < distance[w])) //원래의 distance값보다 u를 거쳐서 w로 가는 거리가 짧으면
					distance[w] = distance[u] + cmp->weight; //새로운 distance값으로 업데이트
			}
		}
	}
}

void init(GraphType* g) { //GraphType 초기화하는 함수
	g->n = 0; //정점 개수 초기화
	for (int i = 0; i < MAX_VERTICES; i++) {
		g->adj_list[i] = NULL;
	}
}

void insert_vertex(GraphType* g, int v) { //정점 삽입하는 함수
	GraphNode* node = (GraphNode*)malloc(sizeof(GraphNode)); //새로운 노드 생성
	node->vertex = v; //vertex 값 저장
	node->link = NULL;
	node->weight = 0; //가중치는 0으로
	g->adj_list[v] = node;
	g->n++; //정점 개수 증가
}

void insert_edge(GraphType* g, int start, int end, int w) { //edge 삽입하는 함수
	GraphNode* node = (GraphNode*)malloc(sizeof(GraphNode)); //새로운 노드 생성
	node->vertex = end; //간선의 end vertex값을 저장
	node->link = NULL;
	node->weight = w; //가중치 값 저장
	if(g->adj_list[start]->link==NULL) g->adj_list[start]->link = node; //만약 정점과 연결된 첫 edge라면 바로 연결
	else { //여러 edge들 중 하나라면
		GraphNode* pre = g->adj_list[start];
		GraphNode* i;
		for (i = g->adj_list[start]->link; i != NULL; i = i->link) { //적절한 위치를 찾아서 노드 삽입
			if (i->vertex < node->vertex) {
				node->link = i;
				pre->link = node;
				return;
			}
			pre = i;
		}
		pre->link = node; //pre 위치 값 업데이트
	}	
}

void print_graph(GraphType* g) { //전체적 그래프 출력하는 함수
	for (int i = 0; i < g->n; i++) {
		printf("vertex %d ", i); //각 vertex에 대하여 출력
		GraphNode* j = g->adj_list[i]->link;
		while (j!=NULL) {
			printf("  -> %d<%d>", j->vertex, j->weight); //vertex에 연결된 또다른 vertex들을 가중치값과 함께 출력
			j = j->link;
		}
		printf("\n");
	}
}


int main(void) {
	head();

	GraphType* g; //그래프 g
	g = (GraphType*)malloc(sizeof(GraphType));
	init(g); //g 초기화
	for (int i = 0; i < 7; i++) {
		insert_vertex(g, i); //7개의 vertex 추가
	}
	//edge 정보 삽입
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

	printf("<Graph 형태>\n");
	print_graph(g); //graph 형태 출력
	int start;
	printf("\n시작 vertex 번호:");
	scanf("%d", &start); //시작 vertex 번호 입력받기
	printf("\n<Shortest Path from vertex %d>\n", start);
	shortest_path(g, start); //dijkstra 최단경로 찾아서 출력
	free(g); 
	return 0;
}
