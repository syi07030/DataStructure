#include <stdio.h>
#include <stdlib.h>
void head() {
	printf("====================\n");
	printf("�а�:���̹���������\n");
	printf("�й�:1971090\n");
	printf("����:�ѱٿ�\n");
	printf("====================\n");
}

typedef struct ListNode { //�ܼ����Ḯ��Ʈ ������ ��忡 ���� ����ü
	int data; //��尡 �����ϰ� �ִ� �����Ͱ�
	struct ListNode* link; //��尡 ���� ��带 ����Ű�� ��ũ �ּҰ�
}ListNode;

ListNode* insert_first(ListNode* head, int val) { //����Ʈ�� �� �տ� ��带 �����ϴ� �Լ�
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = val; //���ο� ����� data���� ���ڷ� ���� val ����
	p->link = head; //���ο� ����� ��ũ�� head�� ������Ʈ
	head = p; //head�� p�� ����Ű���� �Ѵ�
	return head;
}

ListNode* insert(ListNode* head, ListNode* pre, int val) { //��带 ������ ��ġ�� ���ڷ� �޴� ��� ���� �Լ�
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = val; //���ο� ����� data���� ���ڷ� ���� val ����
	p->link = pre->link; //���ο� ����� link�� pre�� link�� ����Ű�� �ּҰ����� ������Ʈ
	pre->link = p; //pre�� ����Ű�� link���� p
	return head;
}

ListNode* insert_sort(ListNode* head, int num) { //����Ʈ�� �ùٸ� ��ġ�� ��带 �����ϴ� �Լ�
	ListNode* p = head; 
	ListNode* tmp = NULL; //���ο� ��带 ������ ��ġ�� �����صα� ���� ������ ����
	if (head == NULL || head->data>num) return insert_first(head, num); //���� ����Ʈ�� ����ְų� ������ ��ġ�� �� ���̶�� insert_first()ȣ��
	else { //�� ���� �����
		while (p != NULL) { //p�� null�� �� ������ �Ʒ� �ݺ�
			if (p->data <= num) { //���� p�� ����Ű�� �����Ͱ� ���ڷ� ���� num���� �۰ų� ������
				tmp = p; //tmp���� ������ p �ּҰ��� �����ϰ�
				p = p->link; //p�� p�� link�� ����Ű�� ���� ������Ʈ
			}
			else { //p�� ����Ű�� �����Ͱ� ���ڷ� ���� num���� ũ�ٸ�
				return insert(head, tmp, num); //tmp ��ġ ������ insert
				break;
			}
		}
		if (tmp->data < num) return insert(head, tmp,num); //���� �ݺ����� �� ���������� tmp�� data���� num�� ũ�� �� �������� ��� ����
	}
}

void print_list(ListNode* head) { //����Ʈ ����ϴ� �Լ�
	ListNode* p = head;
	while (p != NULL) {
		printf("  %d ->", p->data);
		p = p->link;
	}
	printf("  NULL\n");
}
int main(void) {
	head();
	ListNode* head = NULL; //�ܼ����Ḯ��Ʈ�� ����ų ��� ������ �ʱ�ȭ
	int num; //����ڰ� �Է��� ���ڸ� ������ ����
	printf("Input data to insert to linkedlist<0 to quit>\n");
	while (true) { 
		scanf("%d", &num);
		if (num == 0) break; //���� 0�Է��ϸ� �ݺ��� ����������
		else {
			head = insert_sort(head, num); //insert_sort()ȣ��
			print_list(head); //����Ʈ ����Ʈ
		}
	}
	print_list(head); //����Ʈ ����Ʈ
	printf("Program finished.");
}