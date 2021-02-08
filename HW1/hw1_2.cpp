#include <stdio.h>
#include <stdlib.h>
void head() {
	printf("====================\n");
	printf("�а�:���̹���������\n");
	printf("�й�:1971090\n");
	printf("����:�ѱٿ�\n");
	printf("====================\n");
}

typedef struct ListNode { //���߿������Ḯ��Ʈ�� �� ��忡 ���� ����ü
	int data; //��忡 ������ ������ ����
	struct ListNode* llink; //���� ��带 ����Ű�� ��ũ
	struct ListNode* rlink; //������ ��带 ����Ű�� ��ũ
}ListNode;

void add_last(ListNode*head,int num) { //����Ʈ ���� ��� �����ϴ� �Լ�
	ListNode* node = (ListNode*)malloc(sizeof(ListNode)); //���ο� ��� ���� �Ҵ�
	if (node == NULL) { //���� �Ҵ��� ����� �� �ȴٸ� �Ʒ� ����ϰ� ����
		printf("memory allocation error\n");
		exit(1);
	}
	node->data = num;
	node->llink = head->llink;
	node->rlink = head;
	head->llink->rlink = node;
	head->llink = node; //����Ʈ ���� ��� �����ϰ� ��� ���� ������ �������� ��ġ�ߴ� ���� ���� ���� �����Ű��
}

void print_right(ListNode* head) { //�ùٸ� ������ ����Ʈ ����ϴ� �Լ�
	ListNode* node = head->rlink; //��� ����� ������ ������ ����
	while (node != head->llink) { //��� ����� ���� ���� �ö����� �ݺ�
		printf("  %d  <->", node->data); //����� data�� ���
		node = node->rlink; //node�� ����Ű�� ��� ��ġ ������Ʈ
	}
	printf("  %d", node->data); //������ ��� ����� ���� ����� �����Ͱ� ���
}

void print_reverse(ListNode* head) { //�������� ����Ʈ ����ϴ� �Լ�
	ListNode* node = head->llink; //��� ����� ���� ������ ����
	while (node != head->rlink) { //��� ����� ������ ���� �ö����� �ݺ�
		printf("  %d  <->", node->data); //����� data�� ���
		node = node->llink; //node�� ����Ű�� ��� ��ġ ������Ʈ
	}
	printf("  %d", node->data); //������ ��� ����� ������ ����� �����Ͱ� ���
}
int main(void) {
	head();
	ListNode* head = (ListNode*)malloc(sizeof(ListNode)); //��� ��� ����
	head->rlink = head; 
	head->llink = head;//��� ��� �ʱ�ȭ

	int n; //����ڰ� �Է��� ���� ������ ����
	printf("Input data in dual linkedlist<0 to quit>\n");
	while (true) {
		scanf("%d", &n);
		if (n == 0) break;
		else add_last(head, n); //����Ʈ �������� ��� �߰�
	}
	print_right(head); //�ùٸ� ������ ����Ʈ ���
	printf("\nPrint the list in reverse order\n");
	print_reverse(head); //�������� ����Ʈ ���
}