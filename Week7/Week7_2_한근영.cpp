#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5 //원형 큐 최대 사이즈

void head() {
	printf("====================\n");
	printf("학과:사이버보안전공\n");
	printf("학번:1971090\n");
	printf("성명:한근영\n");
	printf("====================\n");
}

typedef struct QueueType { //원형큐에 대한 구조체
	int front; //큐에 있는 맨 처음 원소 위치
	int rear; //큐에 있는 맨 마지막 원소 위치
	int data[MAX_QUEUE_SIZE]; //원소를 저장할 배열
}QueueType;

void enqueue(QueueType* que, int n) { //원형큐 마지막에 원소 추가하는 함수
	if ((que->rear + 1) % MAX_QUEUE_SIZE == que->front) printf("queue is full\n"); //만약 원형큐가 가득차 있으면 다음 출력
	else { //원형큐가 가득차 있지 않다면
		que->rear = (que->rear + 1) % MAX_QUEUE_SIZE; //rear 위치 증가
		que->data[que->rear] = n; //증가된 rear위치에 값 대입
	}
}

int dequeue(QueueType* que) { //원형큐 맨 처음 원소 빼는 함수 
	if (que->front == que->rear) printf("Queue is empty"); //만약 원형큐가 비어있다면 다음 출력
	else { //비어있지 않다면
		que->front = (que->front + 1) % MAX_QUEUE_SIZE; //front 위치 증가
		return que->data[que->front]; //증가된 front 위치에 있는 값 반환
	}
}

int count_queue(QueueType* que) { //원형큐에 있는 원소의 개수를 반환하는 함수
	return ((que->rear - que->front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE);
}

void printf_queue(QueueType* que) { //원형큐에 있는 원소들을 출력하는 함수
	printf("\nQueue<front:%d, rear:%d> =",que->front,que->rear); //front와 rear 위치 출력
	if (que->front != que->rear) { //원형큐에 원소가 있으면
		int i = que->front; //현재 front부터 시작
		do {
			i = (i + 1) % MAX_QUEUE_SIZE; //front+1, 즉 맨 앞에 있는 원소 위치
			printf("%3d :", que->data[i]); //그 위치에 있는 원소값 출력
			if (i == que->rear) break; //증가시킨 위치가 rear와 동일하다면 반복문 빠져나가기
		} while (i != que->front); //다시 front로 돌아올 때까지 반복
	}
	printf("\n");
}

int main(void) {
	head();
	int num; //사용자가 enqueue할 정수를 입력하면 저장할 변수
	char ch; //사용자가 어떤 거를 할지 선택하는 문자를 저장할 변수
	QueueType* que = (QueueType*)malloc(sizeof(QueueType)); //que 구조체 포인터 변수 동적 메모리 할당
	que->front = 0; 
	que->rear = 0; //que 초기화

	while (true) {
		printf("\n원하는 작업<E/e:enqueue, D/d:dequeue, P/p:output, 0:quit>: ");
		scanf("%c", &ch); //원하는 작업 입력받아서
		if (ch == 'E' || ch == 'e') { 
			printf("정수입력: ");
			scanf("%d", &num);
			enqueue(que, num); //입력받은 정수를 원소값으로 해서 원형큐에 추가
		}
		else if (ch == 'D' || ch == 'd') {
			printf("%d\n", dequeue(que)); //원형큐에서 뺀 원소값 출력
		}
		else if (ch == 'P' || ch == 'p') {
			printf_queue(que); //원형큐에 있는 원소들 출력
		}
		else if (ch == '0') break; //사용자가 0입력하면 반복문 빠져나가기
		else printf("Wrong Input\n"); //그 외의 것 입력하면 다음 출력
		scanf("%c", &ch); //버퍼에 남아있는 엔터를 없애기 위함
	}
	printf("현재 원소 갯수는: %d", count_queue(que)); //현재 원소 개수 출력
	printf_queue(que); //원형큐에 있는 원소들 출력
}