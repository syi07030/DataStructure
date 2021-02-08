#include <stdio.h>
#include <stdlib.h>
void head() {
	printf("====================\n");
	printf("�а�:���̹���������\n");
	printf("�й�:1971090\n");
	printf("����:�ѱٿ�\n");
	printf("====================\n");
}

typedef struct QueueNode { //ť ���Ḯ��Ʈ�� �� ��忡 ���� ����ü
	int data; //������ �� ������ ����
	struct QueueNode* link; //���� ��� ����ų ��ũ �ּ�
}QueueNode;

typedef struct QueueType { //ť ���Ḯ��Ʈ�� ���� ����ü
	QueueNode* front; //�� �� ��带 ����Ű�� front
	QueueNode* rear; //�� �� ��带 ����Ű�� rear
}QueueType;

void enqueue(QueueType* que, int n) { //ť �������� ��� �ִ� �Լ�
	QueueNode* tmp = (QueueNode*)malloc(sizeof(QueueNode)); //��� �޸� �Ҵ�
	tmp->data = n; //�Ҵ��� ��忡 ���ڷ� ���� ���� �����ͷ� ����
	tmp->link = NULL; //��ũ�� null�� �ʱ�ȭ
	if (que->front == NULL) que->front = que->rear = tmp; //���� ť�� ����ִٸ� front�� rear��� tmp ����Ű����
	else { //������� �ʴٸ�
		que->rear->link = tmp; 
		que->rear = tmp; //que�� ������ ���� tmp �߰�
	}
}

int dequeue(QueueType* que) { //ť���� ���� �տ� �ִ� ��带 ���ְ� �� ����� ������ ���� ��ȯ�ϴ� �Լ�
	if (que->front == NULL) { //ť�� ����ִٸ� ���� ����ϰ� ����
		printf("Queue is empty");
		exit(1);
	}
	QueueNode* node = que->front; //node�� front�� ����Ű�� ��� �ּ� ����
	int num = node->data; //node�� data �� ����
	que->front = que->front->link; //ť �� �տ� �ִ� ��带 ���� �� ���� ��带 front ����
	if (que->front == NULL) que->rear = NULL; //���� ť�� �������� que�� rear���� null�� ����
	free(node); //node �޸� ��ȯ
	return num; //���� ť ���� �տ� �־��� ����� data�� ��ȯ
}

int peek(QueueType* que) { //ť �� �տ� �ִ� ����� data���� ��ȯ���ִ� �Լ�
	if (que->front == NULL) { ///���� ť�� ����ִٸ� ���� ����ϰ� ����
		printf("Queue is empty");
		exit(1);
	}
	return que->front->data; //ť �� �տ� �ִ� ����� ������ �� ��ȯ
}

int main(void) {
	head();
	QueueType* que = (QueueType*)malloc(sizeof(QueueType)); //����ü ������ ���� que �޸� ���� �Ҵ�
	que->front = NULL;
	que->rear = NULL; //que �ʱ�ȭ

	enqueue(que, 0); 
	enqueue(que, 1); //�Ǻ���ġ 0, 1��° �� ���� ť�� �ֱ�
	
	int num; //����ڰ� �Է��� �� ����
	printf("Input a fibonacci location: ");
	scanf("%d", &num);

	for(int i=0;i<num+1;i++) {
		if (que->front == que->rear) { //���� ť�� ��� �ϳ��� �ִٸ�
			printf("  %d", dequeue(que)); //dequeue�ϰ� �� ���
			exit(0);
		}
		int pre_pre_data = dequeue(que); //ť �� �տ� �ִ� ��带 dequeue�ϰ� �� ����� data�� ����
		printf("  %d", pre_pre_data); //dequeue�� ����� ������ �� ���
		int pre_data = peek(que); //ť �� �տ� �ִ� ����� ������ �� ����
		enqueue(que, pre_pre_data+pre_data); //���� ť�� �ִ� �� �� ����� ������ ������ ���� ������ ������ ���� ��� �����ؼ� ť�� �ֱ�
		
	}
}