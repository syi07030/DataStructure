#include <stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100 //stack �ִ� ũ�⸦ 100���� ����

void head() {
	printf("====================\n");
	printf("�а�:���̹���������\n");
	printf("�й�:1971090\n");
	printf("����:�ѱٿ�\n");
	printf("====================\n");
}

typedef struct Stack { //stack ����ü
	int data[MAX_SIZE]; //�����͸� ������ ������ 100�� ������ �迭
	int top; //stack�� top ��ġ�� ������ ������ ����
}Stack;

int pop(Stack* s) { //stack�� pop �Լ�
	if (s->top == -1) { //���� stack�� ��������� ������ ����ϰ� ������ ����
		printf("Stack empty");
		exit(1);
	}
	else { //stack�� ������� �ʴٸ�
		return s->data[(s->top)--]; //���ڷ� ���� ���� �����Ͱ� ����Ű�� data �迭�� top��ġ�� �ִ� �����͸� ��ȯ�ϰ� top ũ�� ���̱�
	}
}

void push(Stack* s, int n) { //stack�� push �Լ�
	if (s->top == MAX_SIZE - 1) { //���� ���� ������ MAX_SIZE��ŭ �� ���־ �����Ͱ� �� ���� ���ϸ� ������ ���
		printf("Overflow");
	}
	else { //stack�� ���� �����Ͱ� �� �� �� ������
		s->data[++(s->top)] = n; //���ڷ� ���� ���� �����Ͱ� ����Ű�� data �迭�� 1 ������Ų top ��ġ�� ���ڷ� ���� ������ ����
	}
}
void toBinary(Stack *s, int n) { //���� �����Ϳ� �������� ���ڷ� �޾� �������� ��ȯ�� ����� ����ϴ� �Լ�
	int r; //2�� ���� ������ ������ ����
	while (n / 2 >=1) { //n�� 2�� ���� ���� 0�� �Ǳ� ������ �ݺ�
		r = n % 2; //r�� n�� 2�� ���� ������ �� ����
		push(s, r); //r���� ���ڷ� ���� ���� �����Ͱ� ����Ű�� ���ÿ� push
		n = n / 2; //n�� n�� 2�� ���� �� ���� ����
	}
	push(s, n); //���� �ݺ��� ���� �� n�� push
	printf("������ ǥ��: ");
	while (s->top > -1) { //s�� ����Ű�� top�� ���� -1�� �Ǳ� ������, �� ������ �� ���°� �Ǳ� ������
		printf("%d",pop(s)); //���ÿ��� pop�� ���� ���
	}
	printf("\n");
}
int main(void) {
	head();
	Stack s; //����ü ���� s
	s.top = -1; //top���� -1�� �����ν� s �ʱ�ȭ
	int num; //����ڰ� �Է��� ���� �����ϴ� ����
	while(true){ //�ݺ�
		printf("\n������ �Է�<����: 0 ���� �Է�>\n");
		scanf("%d", &num); //�Է��� �� num�� ����
		if (num <= 0) break; //���� num�� 0 ���ϸ� �ݺ��� ������
		else toBinary(&s, num); //num�� 0���� ũ�� toBinary() ����(���ڷ� ����ü ���� s�� �ּҰ��� �Է¹��� ������ ��)
	}
}