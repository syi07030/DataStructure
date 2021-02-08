#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define BUCKETS 10 //버킷 개수는 10개
#define MAX_SIZE 10 //리스트 크기

void head() {
	printf("====================\n");
	printf("학과:사이버보안전공\n");
	printf("학번:1971090\n");
	printf("성명:한근영\n");
	printf("====================\n");
}

typedef struct { //queue에 대한 정보를 저장하는 구조체
	int front;
	int rear;
	int data[MAX_SIZE];
}QueueType;

void init_queue(QueueType* q) { //queue를 초기화시키는 함수
	q->front = -1;
	q->rear = -1;
}

bool is_empty(QueueType* q) { //queue가 비어있는지 여부를 출력하는 함수
	return(q->front==q->rear);
}

void enqueue(QueueType* q, int item) { //enqueue 함수
	if (q->rear == BUCKETS - 1) { //만약 queue가 가득차있다면
		printf("queue is full");
		return;
	}
	else q->data[++q->rear] = item; //만약 queue가 가득차있지 않다면 rear를 증가시키고 item 저장
}

int dequeue(QueueType* q) { //dequeue 함수
	if (is_empty(q)) { //만약 queue가 비어있다면
		printf("queue is empty");
		return -1;
	}
	else return q->data[++(q->front)]; //만약 비어있지 않다면 front값 증가시킨 후 거기에 저장된 data 값 반환
}

void print_queue(QueueType* q) { //queue 출력하는 함수
	for (int i = q->front+1; i <= q->rear; i++) { //front+1부터 rear까지 아래와 같이 출력
		printf("%3d |", q->data[i]); 
	}
	printf("\n");
}

void print_bucket(QueueType*q,int i) { //각 bucket을 출력하는 함수
	printf("[%d]", i ); //몇 번 bucket인지 출력
	print_queue(q); //해당 버킷의 queue data 출력
}

void radix_sort(int list[], int n, int DIGITS) { //radix sort 함수
	int i, b, d, factor = 1;
	QueueType queues[BUCKETS]; //10개만큼의 bucket queue 생성
	for (b = 0; b < BUCKETS; b++) { //모든 bucket 초기화시키기
		init_queue(&queues[b]);
	}
	for (d = 0; d < DIGITS; d++) { //DIGITS만큼 반복(자릿수가 낮은 것부터 높은 순으로)
		for (i = 0; i < n; i++) { //데이터를 자리수에 따라 적절한 queue에 enqueue
			enqueue(&queues[(list[i] / factor) % 10], list[i]);
		}
		for (i = 0; i < BUCKETS; i++) { //각 bucket queue에 있는 데이터 출력
			print_bucket(&queues[i],i);
		}
		i = 0; //i 초기화
		for (b = 0; b < BUCKETS; b++) { //bucket 순서대로 
			while (!is_empty(&queues[b])) {
				list[i++] = dequeue(&queues[b]); //data들을 순서대로 dequeue하여 list에 저장 
			}
			init_queue(&queues[b]); //data 다 꺼낸 bucket queue는 다시 초기화
		}
		factor *= 10; //그 다음 높은 자리수로 이동
		printf("\n");
	}
}

int main(void) {
	head();
	int DIGITS;
	srand(time(NULL)); //seed값 바꾸기
	printf("자리수입력(1~4): ");
	scanf("%d", &DIGITS); //자리수 입력받아서 저장
	int list[MAX_SIZE]; //리스트 생성
	for (int i = 0; i < MAX_SIZE; i++) { //리스트에 해당 DIGITS 범위 안에 해당하는 랜덤 수 저장
		list[i] = rand() % int(pow(10,DIGITS));
	}
	printf("\n<Before sorting>\n");
	for (int i = 0; i < MAX_SIZE; i++) { //정렬되기 전의 리스트 data 출력
		printf("%d ",list[i]);
	}
	printf("\n\n");
	radix_sort(list, MAX_SIZE, DIGITS); //radix sorting
	printf("<After Radix Sorting>\n");
	for (int i = 0; i < MAX_SIZE; i++) { //정렬되고 난 후의 리스트 data 출력
		printf("%d ", list[i]);
	}
}