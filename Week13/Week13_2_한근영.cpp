#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define BUCKETS 10 //��Ŷ ������ 10��
#define MAX_SIZE 10 //����Ʈ ũ��

void head() {
	printf("====================\n");
	printf("�а�:���̹���������\n");
	printf("�й�:1971090\n");
	printf("����:�ѱٿ�\n");
	printf("====================\n");
}

typedef struct { //queue�� ���� ������ �����ϴ� ����ü
	int front;
	int rear;
	int data[MAX_SIZE];
}QueueType;

void init_queue(QueueType* q) { //queue�� �ʱ�ȭ��Ű�� �Լ�
	q->front = -1;
	q->rear = -1;
}

bool is_empty(QueueType* q) { //queue�� ����ִ��� ���θ� ����ϴ� �Լ�
	return(q->front==q->rear);
}

void enqueue(QueueType* q, int item) { //enqueue �Լ�
	if (q->rear == BUCKETS - 1) { //���� queue�� �������ִٸ�
		printf("queue is full");
		return;
	}
	else q->data[++q->rear] = item; //���� queue�� ���������� �ʴٸ� rear�� ������Ű�� item ����
}

int dequeue(QueueType* q) { //dequeue �Լ�
	if (is_empty(q)) { //���� queue�� ����ִٸ�
		printf("queue is empty");
		return -1;
	}
	else return q->data[++(q->front)]; //���� ������� �ʴٸ� front�� ������Ų �� �ű⿡ ����� data �� ��ȯ
}

void print_queue(QueueType* q) { //queue ����ϴ� �Լ�
	for (int i = q->front+1; i <= q->rear; i++) { //front+1���� rear���� �Ʒ��� ���� ���
		printf("%3d |", q->data[i]); 
	}
	printf("\n");
}

void print_bucket(QueueType*q,int i) { //�� bucket�� ����ϴ� �Լ�
	printf("[%d]", i ); //�� �� bucket���� ���
	print_queue(q); //�ش� ��Ŷ�� queue data ���
}

void radix_sort(int list[], int n, int DIGITS) { //radix sort �Լ�
	int i, b, d, factor = 1;
	QueueType queues[BUCKETS]; //10����ŭ�� bucket queue ����
	for (b = 0; b < BUCKETS; b++) { //��� bucket �ʱ�ȭ��Ű��
		init_queue(&queues[b]);
	}
	for (d = 0; d < DIGITS; d++) { //DIGITS��ŭ �ݺ�(�ڸ����� ���� �ͺ��� ���� ������)
		for (i = 0; i < n; i++) { //�����͸� �ڸ����� ���� ������ queue�� enqueue
			enqueue(&queues[(list[i] / factor) % 10], list[i]);
		}
		for (i = 0; i < BUCKETS; i++) { //�� bucket queue�� �ִ� ������ ���
			print_bucket(&queues[i],i);
		}
		i = 0; //i �ʱ�ȭ
		for (b = 0; b < BUCKETS; b++) { //bucket ������� 
			while (!is_empty(&queues[b])) {
				list[i++] = dequeue(&queues[b]); //data���� ������� dequeue�Ͽ� list�� ���� 
			}
			init_queue(&queues[b]); //data �� ���� bucket queue�� �ٽ� �ʱ�ȭ
		}
		factor *= 10; //�� ���� ���� �ڸ����� �̵�
		printf("\n");
	}
}

int main(void) {
	head();
	int DIGITS;
	srand(time(NULL)); //seed�� �ٲٱ�
	printf("�ڸ����Է�(1~4): ");
	scanf("%d", &DIGITS); //�ڸ��� �Է¹޾Ƽ� ����
	int list[MAX_SIZE]; //����Ʈ ����
	for (int i = 0; i < MAX_SIZE; i++) { //����Ʈ�� �ش� DIGITS ���� �ȿ� �ش��ϴ� ���� �� ����
		list[i] = rand() % int(pow(10,DIGITS));
	}
	printf("\n<Before sorting>\n");
	for (int i = 0; i < MAX_SIZE; i++) { //���ĵǱ� ���� ����Ʈ data ���
		printf("%d ",list[i]);
	}
	printf("\n\n");
	radix_sort(list, MAX_SIZE, DIGITS); //radix sorting
	printf("<After Radix Sorting>\n");
	for (int i = 0; i < MAX_SIZE; i++) { //���ĵǰ� �� ���� ����Ʈ data ���
		printf("%d ", list[i]);
	}
}