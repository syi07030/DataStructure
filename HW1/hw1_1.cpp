#include <stdio.h>
#include<stdlib.h>
#include<math.h>

void head() {
	printf("====================\n");
	printf("�а�:���̹���������\n");
	printf("�й�:1971090\n");
	printf("����:�ѱٿ�\n");
	printf("====================\n");
}

typedef struct ListNode { //�ܼ����Ḯ��Ʈ�� �� ��忡 ���� ����ü
	int coef; //����� ������ ����
	int exponent; //������ ������ ����
	struct ListNode* link; //���� ��带 ����Ű�� link �ּҰ� ������ ����
}ListNode;

typedef struct ListType { //����Ʈ�� ���� ������ �����ϴ� ����ü
	int size; //����Ʈ ��ü ����� �����ϴ� ����
	ListNode* head; //���� �տ� �ִ� ��带 ����Ű�� ������ ����
	ListNode* tail; //���� �ڿ� �ִ� ��带 ����Ű�� ������ ����
};

void add_node(ListType* poly, int co, int ex) { //��带 �����ϰ� ������ ���׽� ��ü�� �����ϴ� �Լ�
	ListNode* tmp = (ListNode*)malloc(sizeof(ListNode));
	if (tmp == NULL) { //����� �޸� �����Ҵ��� �� �Ǹ� ������ ����ϰ� ����
		printf("memeory allocation error\n");
		exit(1);
	}
	tmp->coef = co; //���ڷ� ���� ����� ��忡 ����
	tmp->exponent = ex; //���ڷ� ���� ������ ��忡 ����
	tmp->link = NULL; //����� ��ũ ���� null�� �ʱ�ȭ
	if (poly->size == 0) { //���� ����Ʈ�� ����ִٸ�
		poly->head = poly->tail = tmp; //head �����Ϳ� tail ������ ��� tmp
	}
	else { //����Ʈ�� ������� �ʴٸ�
		poly->tail->link = tmp;
		poly->tail = tmp; //����Ʈ �������� ��� �߰�
	}
	poly->size++; //����Ʈ ������ �� 1�� ����
}

void print_poly(ListType* poly) { //���׽� ����ϴ� �Լ�
	printf("<Polynomial>\n");
	ListNode* node = poly->head; //head�� ����Ű�� ������ ����
	for (int i = 0; i < poly->size-1; i++) {
		printf("%dx^%d + ", node->coef, node->exponent); //����� ���� ���
		node = node->link; //node�� ����Ű�� ��� ��ġ ������Ʈ
	}
	printf("%dx^%d\n",node->coef,node->exponent); //������ ����� ����� ���� ���
}

void cal_poly(ListType* poly, int x) { //���ڷ� x�� �޾Ƽ� ���׽� ����ϴ� �Լ�
	int sum = 0;
	ListNode* node = poly->head; //head�� ����Ű�� ������ ����
	for (int i = 0; i < poly->size; i++) {
		sum += (node->coef) * int(pow(x, node->exponent)); //�� ����ؼ� sum�� ���ϱ�
		node=node->link; //node�� ����Ű�� ��� ��ġ ������Ʈ
	}
	printf("Result of polynomial with x: %d", sum); //����� ���
}

int main(void) {
	head();
	ListType* poly = (ListType*)malloc(sizeof(ListType));
	poly->head = NULL;
	poly->tail = NULL;
	poly->size = 0; //poly �ʱ�ȭ
	int coef; //����ڷκ��� ��� �Է¹��� ����
	int exponent;//����ڷκ��� ���� �Է¹��� ����
	int x; //����ڷκ��� x�� �Է¹��� ����
	printf("Input coef and exponent of polynomial<��������: exponent�� 0���� �Է�>\n");
	while (true) {
		scanf("%d %d", &coef, &exponent);
		add_node(poly, coef, exponent); //���׽� ���Ḯ��Ʈ �����
		if (exponent == 0) break; //���� �������� 0�̸� �ݺ��� ����������
	}
	print_poly(poly); //���׽� ���
	printf("\nInput the value x: ");
	scanf("%d", &x);
	cal_poly(poly, x); //x�� ���׽Ŀ� �־ ����ϰ� ���
}