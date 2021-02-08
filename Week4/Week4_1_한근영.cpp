#include <stdio.h>
#include<malloc.h>
void head() {
	printf("====================\n");
	printf("�а�:���̹���������\n");
	printf("�й�:1971090\n");
	printf("����:�ѱٿ�\n");
	printf("====================\n");
}
typedef struct Node{ //����ڰ� �Է��� ���� ������ ���� ����� �ּҰ��� ���� �ִ� Node ����ü
	int data;
	struct Node* link;
}Node;

typedef struct ListInfo { //����Ʈ�� ��ü ������� ��� �ּҰ�, ��� ������ ���� tail �ּҰ��� ������ ListInfo ����ü
	int size;
	Node* head;
	Node* tail;
}ListInfo;

void printList(ListInfo*info) { //����Ʈ ����Լ�
	Node* n = info->head; //������ n�� ���ڷ� ���� info�� head,�� ��� �ּҰ��� ����Ų��
	for (int i = 0; i < info->size; i++) { //����Ʈ�� ��ü ������, �� ��� �� ������ŭ �ݺ�
		printf("%d  ",n->data); //n�� ����Ű�� ����� data ���� ���
		n = n->link; //n�� �ּҰ��� ���� ����� �ּҰ����� ������Ʈ
	}
}

void insertList(int a, ListInfo*info) { //����Ʈ �������� insert�ϴ� �Լ�
	Node* n = (Node*)malloc(sizeof(Node)); //�߰��� ��� ����(�����Ҵ�)
	n->data = a; //n�� ����Ű�� ����� data ���� ���ڷ� ���� a������ ����
	n->link = NULL; //n�� ����Ű�� ����� link �ּҰ��� NULL�� ����
	if (info->tail == NULL) { //���� ����Ʈ�� ��尡 �ƹ��͵� ���ٸ�
		info->head = n; //head �ּҰ��� n����
		info->tail = n; //tail �ּҰ��� ��������
	}
	else { //�̹� ����Ʈ�� ��尡 �����Ѵٸ�
		info->tail->link = n; //tail�� ����Ű�� ����� link�� n�� ���������ν� ��� ����
		info->tail = n; //tail �ּҰ� ������Ʈ
	}
	info->size++; //����Ʈ�� ��� ���� ����
}

void findList(ListInfo* info) { //�ִ�, �ּ� ã�� �Լ�
	Node* n = info->head; //n�� ���� ����Ʈ�� ���� ó�� ��带 ����Ű���� �Ѵ�
	int max = n->data; //max���� n�� data ������ �ʱ�ȭ
	int min = n->data; //min���� ��������
	for (int i = 0; i < info->size; i++) { //����Ʈ�� ��� ������ŭ �ݺ�
		if (n->data > max) {//���� n�� ����Ű�� ����� data���� max���� ũ�ٸ�
			max = n->data;//max�� ������Ʈ
		}
		if (n->data < min) { //���� n�� ����Ű�� ����� data���� min���� �۴ٸ�
			min = n->data; //min�� ������Ʈ
		}
		n = n->link; //n�� ���� ��带 ����Ű���� ������Ʈ
	}
	printf("\nMax: %d   Min: %d", max, min);
}

int main(void) {
	head();
	int n; //����ڰ� �Է��� ������ ������ ����
	ListInfo* list=(ListInfo*)malloc(sizeof(ListInfo)); //����Ʈ�� ���� ������ ������ ListInfo ����(�����Ҵ�)
	list->head = NULL;
	list->tail = NULL;
	list->size = NULL; //ListInfo�� �ִ� ��� ��� NULL�� �ʱ�ȭ

	printf("Input an integer to add <0 to quit>: ");
	scanf("%d", &n); //�Է¹޾Ƽ� n�� ����
	while(n!=0) { //n�� 0�� �ƴϸ� �ݺ�
		insertList(n, list); //��� ����
		printf("Input an integer to add <0 to quit>: "); //���� �Է¹޴� �� �ݺ�
		scanf("%d", &n);
	}

	if (list->size > 0) { //���� ����Ʈ�� ����� ���� �ʴٸ�
		printf("<List>\n");
		printList(list); //����Ʈ ���
		findList(list); //�ִ밪, �ּҰ� ���
	}
	
}