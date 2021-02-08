#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICS 50

void head() {
	printf("====================\n");
	printf("학과:사이버보안전공\n");
	printf("학번:1971090\n");
	printf("성명:한근영\n");
	printf("====================\n");
}

int visited[MAX_VERTICS];  //방문했는지 여부를 판단하기 위한 배열

typedef struct GraphType { //그래프에 대한 구조체
	int n; //vertex의 수
	int adj_mat[MAX_VERTICS][MAX_VERTICS];
}GraphType;

void init(GraphType* g) { //그래프 초기화시키는 함수
	int r, c;
	g->n = 0;
	for (r = 0; r < MAX_VERTICS; r++) {
		for (c = 0; c < MAX_VERTICS; c++) {
			g->adj_mat[r][c] = 0; //모든 원소를 0으로 초기화
		}
	}
}

void insert_vertex(GraphType* g, int v) { //vertex 삽입하는 함수
	if (g->n + 1 > MAX_VERTICS) {
		fprintf(stderr, "그래프:정점의 개수 초과\n"); //오류 출력
		return;
	}
	else g->n++; //vertex 개수 증가
}

void insert_edge(GraphType* g, int start, int end) { //edge 삽입하는 함수(undirected여서 대칭일 경우)
	if (start >= g->n || end >= g->n) {
		fprintf(stderr, "그래프:정점 번호 오류\n"); //오류 출력
		return;
	}
	g->adj_mat[start][end] = 1; //대칭 위치에 모두 1로 저장
	g->adj_mat[end][start] = 1;
}

void insert_edge2(GraphType* g, int start, int end) { //edge 삽입하는 함수(directed여서 비대칭일 경우)
	if (start >= g->n || end >= g->n) {
		fprintf(stderr, "그래프:정점 번호 오류\n"); //오류 출력
		return;
	}
	g->adj_mat[start][end] = 1; //해당 위치에만 1로 저장
}

void print_adj_mat(GraphType* g) { //그래프 출력하는 함수
	int r, c;
	for (r = 0; r < g->n; r++) {
		for (c = 0; c < g->n; c++) {
			printf("%2d", g->adj_mat[r][c]); //행렬처럼 그래프 출력
		}
		printf("\n");
	}
}

void dfs_mat(GraphType* g, int v) {
	int w;
	visited[v] = true; //dfs 시작된 vertex는 방문한 것으로 표시
	printf("vertex%d  ", v); //방문한 vertex 출력
	for (w = 0; w < g->n; w++) { //해당 vertex의 row를 하나씩 검사해서
		if (g->adj_mat[v][w] && !visited[w]) { //값이 1인데 아직 방문하지 않았으면
			dfs_mat(g, w); //재귀 호출
		}
	}
}

int stack[MAX_VERTICS]; //스택 생성
int top = -1; //top 초기화

int pop(void) { //스택 pop 함수
	if (top == -1) {
		printf("Stack empty");
		exit(1);
	}
	else return stack[top--]; //top 위치에 있는 값 반환 후 top 값 1 줄이기
}

void push(int item) { //스택 push 함수
	if (top == MAX_VERTICS - 1) {
		printf("Stack empty");
		exit(1);
	}
	else stack[++top] = item; //top 값을 1 증가시킨 후 그 위치에 인자로 받은 값 저장하기
}
void dfs_stack(GraphType* g, int v) { //스택을 이용해 dfs 구하기
	push(v); //인자로 받은 값을 스택에 push
	while (top != -1) { //스택이 비어있지 않으면 다음 반복
		v = pop(); //스택에서 pop한 값을 v에 저장
		if (!visited[v]) { //만약 v가 방문되지 않았으면
			visited[v] = true; //v 방문되었다고 표시
			printf("vertex%d  ", v); //vertex 프린트하기
			for (int w = 0; w < g->n; w++) { //v에 인접한 정점에 대하여
				if (g->adj_mat[v][w] && !visited[w]) { //만약 아직 방문되지 않았다면
					push(w); //스택에 push
				}
			}

		}
	}
}

void init_visited(GraphType* g) { //방문되었는지 여부 판단하는 배열 초기화
	for (int i = 0; i < MAX_VERTICS; i++) {
		visited[i] = 0; //0으로 모두 초기화
	}
}
int main(void) {
	head();

	GraphType* g; //포인터 변수 생성
	g = (GraphType*)malloc(sizeof(GraphType)); //동적할당
	init(g); //그래프 초기화
	for (int i = 0; i < 5; i++) {
		insert_vertex(g, i);
	}
	//undirected 대칭구조를 갖는 그래프
	insert_edge(g, 0, 1);
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 3);
	insert_edge(g, 1, 4);
	insert_edge(g, 2, 4);

	printf("<Graph Matrix>\n");
	print_adj_mat(g); //그래프 행렬 출력
	printf("<Depth Fisrt Search-recursive>\n");
	dfs_mat(g, 0); //재귀호출 이용한 결과 출력
	init_visited(g); //방문여부 배열 초기화
	printf("\n<Depth First Search-stack>\n");
	dfs_stack(g, 0); //스택 이용한 결과 출력

	init(g); //그래프 초기화
	for (int i = 0; i < 6; i++) {
		insert_vertex(g, i);
	}
	//directed 비대칭 구조를 갖는 그래프
	insert_edge2(g, 0, 2);
	insert_edge2(g, 0, 4);
	insert_edge2(g, 2, 1);
	insert_edge2(g, 2, 3);
	insert_edge2(g, 1, 5);
	insert_edge2(g, 4, 5);

	init_visited(g);//방문여부 배열 초기화
	printf("\n\n<Graph Matrix>\n");
	print_adj_mat(g); //그래프 행렬 출력
	printf("<Depth Fisrt Search-recursive>\n");
	dfs_mat(g, 0); //재귀호출 이용한 결과 출력
	init_visited(g); //방문여부 배열 초기화
	printf("\n<Depth First Search-stack>\n");
	dfs_stack(g, 0);//스택 이용한 결과 출력

	free(g); //동적할당한 거 free
}