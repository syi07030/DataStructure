#include <stdio.h>
#include <stdlib.h>
void head() {
	printf("====================\n");
	printf("학과:사이버보안전공\n");
	printf("학번:1971090\n");
	printf("성명:한근영\n");
	printf("====================\n");
}

typedef struct QueueNode { //각 노드에 대한 정보를 저장할 구조체
	int data; //데이터 저장할 변수
	struct QueueNode* link; //연결 링크 주소 저장할 포인터 변수
}QueueNode;

typedef struct QueueType { //연결리스트로 구현된 큐에 대한 정보를 저장하는 구조체
	QueueNode* front; //리스트의 첫번재 노드의 주소를 저장할 포인터 변수
	QueueNode* rear; //리스트의 마지막 노드의 주소를 저장할 포인터 변수
}QueueType;

void print_que(QueueNode* front) { //큐를 출력하는 함수
	QueueNode* p = front; //front 포인터 값을 p에 넣고
	while (p != NULL) { //p값이 null이 될 때까지 반복
		if (p->data >= 10) printf(" %d  :", p->data); //출력할 때 모양 좋게 하기 위해 추가
		else printf("  %d  :", p->data); //p노드가 가리키는 data 값 출력
		p = p->link; //p에 p의 link가 가리키는 노드로 업데이트
	}
	printf("\n");
}

void enqueue(QueueType* que, int num) { //큐에 새로운 카드 넣는 함수
	QueueNode* t = (QueueNode*)malloc(sizeof(QueueNode)); //새로운 노드를 동적할당하여 가리키는 포인터 변수 t
	t->data = num; //t의 data에 인자로 받은 num을 넣는다
	t->link = NULL; //t의 link는 아무것도 가리키지 않는다
	if (que->front == NULL && que->rear == NULL) {//큐가 비어있으면
		que->front = que->rear = t; //일단 que의 front와 rear에 모두 t값을 넣는다
	}
	else { //큐가 비어있지 않다면
		que->rear->link = t; //리스트 마지막에 노드 추가
		que->rear = t;
	}
}
void create_que(QueueType*que,int num) { //큐 생성하는 함수
	for (int i = 1; i<=num; i++) { //i를 1부터 num까지 반복
		enqueue(que, i); //enqueue()호출
	}
	print_que(que->front); //큐 출력
}

int count_node(QueueNode* front) { //연결리스트 시작주소를 받아 노드의 개수를 반환하는 함수
	int count = 0;
	QueueNode* p = front;
	while (p != NULL) { //p가 null이 될때까지 반복
		count++; //노드 개수 하나씩 늘리기
		p = p->link; //p는 p의 link가 가리키는 노드로 업데이트
	}
	return count; //노드 개수 반환
}

int dequeue(QueueType*que) { //큐에서 카드 꺼내는 함수
	if (que->front == NULL && que->rear == NULL) { //만약 큐가 비어있으면 다음 출력하고 종료
		printf("Queue is empty");
		exit(1);
	}
	QueueNode* h = que->front; //h에 큐의 헤더 포인터가 가리키는 노드 주소값을 넣는다
	int num = h->data; //꺼낼 카드의 데이터를 num에 임시 저장
	que->front = que->front->link; //제일 위에 있는 카드 버리기
	if (que->front == NULL) que->rear = NULL; //만약 큐가 비어버리면 큐 공백으로 만들기
	free(h); //h 메모리 free 시키기
	return num; //dequeue된 값 반환
}

void re_queue(QueueType*que) { //규칙에 맞춰 작동하는 함수
	int card_data=dequeue(que); //제일 위에 있는 카드 버리고 그 카드의 data값을 저장
	print_que(que->front);
	if (count_node(que->front) > 1) { //노드 개수가 1보다 클때만
		enqueue(que, dequeue(que));//제일 위에 있던 카드를 꺼내서 버리고 그 카드가 저장했던 data값을 다시 큐에 enqueue한다
		print_que(que->front);//다시 큐 출력
	}
}

int main(void) {
	head();

	int n; //사용자가 입력한 수를 저장할 변수
	printf("Input number of cards: ");
	scanf("%d", &n);
	if (n == 0) { //만약 사용자가 0 입력하면 다음 출력하고 종료
		printf("queue empty");
		exit(0);
	}
	QueueType* que = (QueueType*)malloc(sizeof(QueueType)); //구조체 포인터 변수 que 생성
	que->front = NULL; 
	que->rear = NULL; //que 초기화

	create_que(que, n); //큐 생성
	while (count_node(que->front) > 1) { //큐의 노드 개수가 1 이하가 될 때까지 re_queue()반복 호출
		re_queue(que);
	}
	printf("Final element is %d",que->front->data); //마지막 element 무엇인지 출력
}