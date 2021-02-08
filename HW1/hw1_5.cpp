#include <stdio.h>
#include <stdlib.h>
void head() {
	printf("====================\n");
	printf("�а�:���̹���������\n");
	printf("�й�:1971090\n");
	printf("����:�ѱٿ�\n");
	printf("====================\n");
}

typedef struct QueueNode { //�� ��忡 ���� ������ ������ ����ü
	int data; //������ ������ ����
	struct QueueNode* link; //���� ��ũ �ּ� ������ ������ ����
}QueueNode;

typedef struct QueueType { //���Ḯ��Ʈ�� ������ ť�� ���� ������ �����ϴ� ����ü
	QueueNode* front; //����Ʈ�� ù���� ����� �ּҸ� ������ ������ ����
	QueueNode* rear; //����Ʈ�� ������ ����� �ּҸ� ������ ������ ����
}QueueType;

void print_que(QueueNode* front) { //ť�� ����ϴ� �Լ�
	QueueNode* p = front; //front ������ ���� p�� �ְ�
	while (p != NULL) { //p���� null�� �� ������ �ݺ�
		if (p->data >= 10) printf(" %d  :", p->data); //����� �� ��� ���� �ϱ� ���� �߰�
		else printf("  %d  :", p->data); //p��尡 ����Ű�� data �� ���
		p = p->link; //p�� p�� link�� ����Ű�� ���� ������Ʈ
	}
	printf("\n");
}

void enqueue(QueueType* que, int num) { //ť�� ���ο� ī�� �ִ� �Լ�
	QueueNode* t = (QueueNode*)malloc(sizeof(QueueNode)); //���ο� ��带 �����Ҵ��Ͽ� ����Ű�� ������ ���� t
	t->data = num; //t�� data�� ���ڷ� ���� num�� �ִ´�
	t->link = NULL; //t�� link�� �ƹ��͵� ����Ű�� �ʴ´�
	if (que->front == NULL && que->rear == NULL) {//ť�� ���������
		que->front = que->rear = t; //�ϴ� que�� front�� rear�� ��� t���� �ִ´�
	}
	else { //ť�� ������� �ʴٸ�
		que->rear->link = t; //����Ʈ �������� ��� �߰�
		que->rear = t;
	}
}
void create_que(QueueType*que,int num) { //ť �����ϴ� �Լ�
	for (int i = 1; i<=num; i++) { //i�� 1���� num���� �ݺ�
		enqueue(que, i); //enqueue()ȣ��
	}
	print_que(que->front); //ť ���
}

int count_node(QueueNode* front) { //���Ḯ��Ʈ �����ּҸ� �޾� ����� ������ ��ȯ�ϴ� �Լ�
	int count = 0;
	QueueNode* p = front;
	while (p != NULL) { //p�� null�� �ɶ����� �ݺ�
		count++; //��� ���� �ϳ��� �ø���
		p = p->link; //p�� p�� link�� ����Ű�� ���� ������Ʈ
	}
	return count; //��� ���� ��ȯ
}

int dequeue(QueueType*que) { //ť���� ī�� ������ �Լ�
	if (que->front == NULL && que->rear == NULL) { //���� ť�� ��������� ���� ����ϰ� ����
		printf("Queue is empty");
		exit(1);
	}
	QueueNode* h = que->front; //h�� ť�� ��� �����Ͱ� ����Ű�� ��� �ּҰ��� �ִ´�
	int num = h->data; //���� ī���� �����͸� num�� �ӽ� ����
	que->front = que->front->link; //���� ���� �ִ� ī�� ������
	if (que->front == NULL) que->rear = NULL; //���� ť�� �������� ť �������� �����
	free(h); //h �޸� free ��Ű��
	return num; //dequeue�� �� ��ȯ
}

void re_queue(QueueType*que) { //��Ģ�� ���� �۵��ϴ� �Լ�
	int card_data=dequeue(que); //���� ���� �ִ� ī�� ������ �� ī���� data���� ����
	print_que(que->front);
	if (count_node(que->front) > 1) { //��� ������ 1���� Ŭ����
		enqueue(que, dequeue(que));//���� ���� �ִ� ī�带 ������ ������ �� ī�尡 �����ߴ� data���� �ٽ� ť�� enqueue�Ѵ�
		print_que(que->front);//�ٽ� ť ���
	}
}

int main(void) {
	head();

	int n; //����ڰ� �Է��� ���� ������ ����
	printf("Input number of cards: ");
	scanf("%d", &n);
	if (n == 0) { //���� ����ڰ� 0 �Է��ϸ� ���� ����ϰ� ����
		printf("queue empty");
		exit(0);
	}
	QueueType* que = (QueueType*)malloc(sizeof(QueueType)); //����ü ������ ���� que ����
	que->front = NULL; 
	que->rear = NULL; //que �ʱ�ȭ

	create_que(que, n); //ť ����
	while (count_node(que->front) > 1) { //ť�� ��� ������ 1 ���ϰ� �� ������ re_queue()�ݺ� ȣ��
		re_queue(que);
	}
	printf("Final element is %d",que->front->data); //������ element �������� ���
}