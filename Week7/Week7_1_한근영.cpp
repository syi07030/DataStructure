#include <stdio.h>
#include <stdlib.h>
void head() {
	printf("====================\n");
	printf("학과:사이버보안전공\n");
	printf("학번:1971090\n");
	printf("성명:한근영\n");
	printf("====================\n");
}

typedef struct QueueNode { //큐 연결리스트의 각 노드에 대한 구조체
	int data; //데이터 값 저장할 변수
	struct QueueNode* link; //다음 노드 가리킬 링크 주소
}QueueNode;

typedef struct QueueType { //큐 연결리스트에 대한 구조체
	QueueNode* front; //맨 앞 노드를 가리키는 front
	QueueNode* rear; //맨 뒤 노드를 가리키는 rear
}QueueType;

void enqueue(QueueType* que, int n) { //큐 마지막에 노드 넣는 함수
	QueueNode* tmp = (QueueNode*)malloc(sizeof(QueueNode)); //노드 메모리 할당
	tmp->data = n; //할당한 노드에 인자로 받은 값을 데이터로 저장
	tmp->link = NULL; //링크는 null로 초기화
	if (que->front == NULL) que->front = que->rear = tmp; //만약 큐가 비어있다면 front와 rear모두 tmp 가리키도록
	else { //비어있지 않다면
		que->rear->link = tmp; 
		que->rear = tmp; //que의 마지막 노드로 tmp 추가
	}
}

int dequeue(QueueType* que) { //큐에서 가장 앞에 있는 노드를 없애고 그 노드의 데이터 값을 반환하는 함수
	if (que->front == NULL) { //큐가 비어있다면 다음 출력하고 종료
		printf("Queue is empty");
		exit(1);
	}
	QueueNode* node = que->front; //node에 front가 가리키는 노드 주소 저장
	int num = node->data; //node의 data 값 저장
	que->front = que->front->link; //큐 맨 앞에 있던 노드를 빼고 그 다음 노드를 front 노드로
	if (que->front == NULL) que->rear = NULL; //만약 큐가 비어버리면 que의 rear값도 null로 저장
	free(node); //node 메모리 반환
	return num; //원래 큐 제일 앞에 있었던 노드의 data값 반환
}

int peek(QueueType* que) { //큐 맨 앞에 있는 노드의 data값을 반환해주는 함수
	if (que->front == NULL) { ///만약 큐가 비어있다면 다음 출력하고 종료
		printf("Queue is empty");
		exit(1);
	}
	return que->front->data; //큐 맨 앞에 있는 노드의 데이터 값 반환
}

int main(void) {
	head();
	QueueType* que = (QueueType*)malloc(sizeof(QueueType)); //구조체 포인터 변수 que 메모리 동적 할당
	que->front = NULL;
	que->rear = NULL; //que 초기화

	enqueue(que, 0); 
	enqueue(que, 1); //피보나치 0, 1번째 값 먼저 큐에 넣기
	
	int num; //사용자가 입력할 값 저장
	printf("Input a fibonacci location: ");
	scanf("%d", &num);

	for(int i=0;i<num+1;i++) {
		if (que->front == que->rear) { //만약 큐에 노드 하나만 있다면
			printf("  %d", dequeue(que)); //dequeue하고 값 출력
			exit(0);
		}
		int pre_pre_data = dequeue(que); //큐 맨 앞에 있는 노드를 dequeue하고 그 노드의 data값 저장
		printf("  %d", pre_pre_data); //dequeue한 노드의 데이터 값 출력
		int pre_data = peek(que); //큐 맨 앞에 있는 노드의 데이터 값 저장
		enqueue(que, pre_pre_data+pre_data); //원래 큐에 있던 두 개 노드의 데이터 값들의 합을 데이터 값으로 갖는 노드 생성해서 큐에 넣기
		
	}
}