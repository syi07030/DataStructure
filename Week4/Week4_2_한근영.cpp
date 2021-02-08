#include <stdio.h>
#include<malloc.h>
void head() {
	printf("====================\n");
	printf("�а�:���̹���������\n");
	printf("�й�:1971090\n");
	printf("����:�ѱٿ�\n");
	printf("====================\n");
}
typedef struct Node { //����ڰ� �Է��� ���� ������ ���� ����� �ּҰ��� ���� �ִ� Node ����ü
	int data;
	struct Node* llink;
	struct Node* rlink;
}Node;

void printList(Node* head) { //����Ʈ ����Լ�
	Node* n = head->rlink; //������ n�� ���ڷ� ���� head�� ������ ��ũ �ּҰ��� ����Ų��
	while (n != head) { //n�� head�� ������ �ݺ�
		printf("%d  ", n->data); //n�� ����Ű�� ����� data ���� ���
		n = n->rlink; //n�� �ּҰ��� ������ ����� �ּҰ����� ������Ʈ
	}
}

void insertList(int a, Node* pn) { //����Ʈ�� ��� insert�ϴ� �Լ�
	Node* n = (Node*)malloc(sizeof(Node)); //�߰��� ��� ����(�����Ҵ�)
	n->data = a; //n�� ����Ű�� ����� data ���� ���ڷ� ���� a������ ����
	pn->rlink->llink = n; //��������� ������ ��ũ�� ����Ű�� ����� ���� ��ũ�� n���� ����
	n->llink = pn; //n�� ���� ��ũ�� ������� �ּҰ�����
	n->rlink = pn->rlink; //n�� ������ ��ũ�� ��������� ������ ��ũ�� ����Ű�� ������ ����
	pn->rlink = n; //��������� ������ ��ũ�� n�� �ּҰ�����
}

void deleteList(int a, Node* head) { //����Ʈ���� ��� delete�ϴ� �Լ�
	Node* n = head->rlink; //n�� head�� rlink�� ����Ű�� �ּҰ�
	int ch = 0; //ã�� ���ڰ� ����Ʈ�� �����ϴ��� ���ο� ���� ����
	while (n!= head) { //n�� head�� �� ������
		if (n->data == a) { //���� ã�� ���ڰ� ����Ʈ ���� ������
			printf("%d is found and deleted",a);
			n->llink->rlink = n->rlink; //������ ����� ���� ����� rlink���� n�� rlink������
			n->rlink->llink = n->llink; //������ ����� ������ ����� llink���� n�� llink������
			free(n); //��� n�� �Ҵ�� �޸� free
			ch = 1;
			break;
		}
		n = n->rlink; //n ���� n�� ������ ��� �ּҰ�����
	}
	if (ch == 0) { //���� ã�� ���ڰ� ����Ʈ�� �������� �ʴٸ� ������ ���
		printf("%d is not in the list",a);
	}
}

int main(void) {
	head();
	int n; //����ڰ� �Է��� ������ ������ ����
	Node* head = (Node*)malloc(sizeof(Node)); //��� ��� ����(�����Ҵ�)
	head->rlink = head; //��� ��� �ʱ�ȭ
	head->llink = head; //��� ��� �ʱ�ȭ

	printf("Input an integer to add <0 to quit>: ");
	scanf("%d", &n); //�Է¹޾Ƽ� n�� ����
	while (n != 0) { //n�� 0�� ������ �ݺ�
		insertList(n, head); //��� ����Ʈ�� ����
		printf("Input an integer to add <0 to quit>: ");
		scanf("%d", &n);
	}

	if (head != NULL) { //���� ����Ʈ�� ������� �ʴٸ�
		printf("<List>\n");
		printList(head); //����Ʈ ���
		printf("\nInput a number to search and delete: ");
		scanf("%d", &n); //ã�Ƽ� ������ ���� �Է¹ޱ�
		deleteList(n, head); //�ش� ���� ã�Ƽ� �����ϱ�
		printf("\n<List>\n");
		printList(head); //����Ʈ ���
	}
	
}