#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5 //���� ť �ִ� ������

void head() {
	printf("====================\n");
	printf("�а�:���̹���������\n");
	printf("�й�:1971090\n");
	printf("����:�ѱٿ�\n");
	printf("====================\n");
}

typedef struct QueueType { //����ť�� ���� ����ü
	int front; //ť�� �ִ� �� ó�� ���� ��ġ
	int rear; //ť�� �ִ� �� ������ ���� ��ġ
	int data[MAX_QUEUE_SIZE]; //���Ҹ� ������ �迭
}QueueType;

void enqueue(QueueType* que, int n) { //����ť �������� ���� �߰��ϴ� �Լ�
	if ((que->rear + 1) % MAX_QUEUE_SIZE == que->front) printf("queue is full\n"); //���� ����ť�� ������ ������ ���� ���
	else { //����ť�� ������ ���� �ʴٸ�
		que->rear = (que->rear + 1) % MAX_QUEUE_SIZE; //rear ��ġ ����
		que->data[que->rear] = n; //������ rear��ġ�� �� ����
	}
}

int dequeue(QueueType* que) { //����ť �� ó�� ���� ���� �Լ� 
	if (que->front == que->rear) printf("Queue is empty"); //���� ����ť�� ����ִٸ� ���� ���
	else { //������� �ʴٸ�
		que->front = (que->front + 1) % MAX_QUEUE_SIZE; //front ��ġ ����
		return que->data[que->front]; //������ front ��ġ�� �ִ� �� ��ȯ
	}
}

int count_queue(QueueType* que) { //����ť�� �ִ� ������ ������ ��ȯ�ϴ� �Լ�
	return ((que->rear - que->front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE);
}

void printf_queue(QueueType* que) { //����ť�� �ִ� ���ҵ��� ����ϴ� �Լ�
	printf("\nQueue<front:%d, rear:%d> =",que->front,que->rear); //front�� rear ��ġ ���
	if (que->front != que->rear) { //����ť�� ���Ұ� ������
		int i = que->front; //���� front���� ����
		do {
			i = (i + 1) % MAX_QUEUE_SIZE; //front+1, �� �� �տ� �ִ� ���� ��ġ
			printf("%3d :", que->data[i]); //�� ��ġ�� �ִ� ���Ұ� ���
			if (i == que->rear) break; //������Ų ��ġ�� rear�� �����ϴٸ� �ݺ��� ����������
		} while (i != que->front); //�ٽ� front�� ���ƿ� ������ �ݺ�
	}
	printf("\n");
}

int main(void) {
	head();
	int num; //����ڰ� enqueue�� ������ �Է��ϸ� ������ ����
	char ch; //����ڰ� � �Ÿ� ���� �����ϴ� ���ڸ� ������ ����
	QueueType* que = (QueueType*)malloc(sizeof(QueueType)); //que ����ü ������ ���� ���� �޸� �Ҵ�
	que->front = 0; 
	que->rear = 0; //que �ʱ�ȭ

	while (true) {
		printf("\n���ϴ� �۾�<E/e:enqueue, D/d:dequeue, P/p:output, 0:quit>: ");
		scanf("%c", &ch); //���ϴ� �۾� �Է¹޾Ƽ�
		if (ch == 'E' || ch == 'e') { 
			printf("�����Է�: ");
			scanf("%d", &num);
			enqueue(que, num); //�Է¹��� ������ ���Ұ����� �ؼ� ����ť�� �߰�
		}
		else if (ch == 'D' || ch == 'd') {
			printf("%d\n", dequeue(que)); //����ť���� �� ���Ұ� ���
		}
		else if (ch == 'P' || ch == 'p') {
			printf_queue(que); //����ť�� �ִ� ���ҵ� ���
		}
		else if (ch == '0') break; //����ڰ� 0�Է��ϸ� �ݺ��� ����������
		else printf("Wrong Input\n"); //�� ���� �� �Է��ϸ� ���� ���
		scanf("%c", &ch); //���ۿ� �����ִ� ���͸� ���ֱ� ����
	}
	printf("���� ���� ������: %d", count_queue(que)); //���� ���� ���� ���
	printf_queue(que); //����ť�� �ִ� ���ҵ� ���
}