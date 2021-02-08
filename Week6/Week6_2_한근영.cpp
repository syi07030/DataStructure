#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#define MAX_SIZE 100 //stack�� ���ڿ� �迭 �ִ� ũ�⸦ 100���� ����

void head() {
	printf("====================\n");
	printf("�а�:���̹���������\n");
	printf("�й�:1971090\n");
	printf("����:�ѱٿ�\n");
	printf("====================\n");
}

typedef struct Stack { //stack ����ü
	char data[MAX_SIZE]; //�����͸� ������ ������ 100�� char�� �迭
	int top; //stack�� top ��ġ�� ������ ������ ����
}Stack;

char pop(Stack* s) { //stack�� pop �Լ�
	if (s->top == -1) { //���� stack�� ��������� ������ ����ϰ� ������ ����
		printf("Stack empty");
		exit(1);
	}
	else { //stack�� ������� �ʴٸ�
		return s->data[(s->top)--]; //���ڷ� ���� ���� �����Ͱ� ����Ű�� data �迭�� top��ġ�� �ִ� �����͸� ��ȯ�ϰ� top ũ�� ���̱�
	}
}

void push(Stack* s, char n) { //stack�� push �Լ�
	if (s->top == MAX_SIZE - 1) { //���� ���� ������ MAX_SIZE��ŭ �� ���־ �����Ͱ� �� ���� ���ϸ� ������ ���
		printf("Overflow");
	}
	else { //stack�� ���� �����Ͱ� �� �� �� ������
		s->data[++(s->top)] = n; //���ڷ� ���� ���� �����Ͱ� ����Ű�� data �迭�� 1 ������Ų top ��ġ�� ���ڷ� ���� ������ ����
	}
}

char peek(Stack* s) { //stack�� peek �Լ�
	if (s->top == -1) { //���� ������ ��������� ������ ����ϰ� ������ ����
		printf("Stack empty");
		exit(1);
	}
	else return s->data[s->top]; //������ ������� �ʴٸ� s�� ����Ű�� data �迭�� top ��ġ�� �ִ� ������ �� ��ȯ
}

void init_stack(Stack *s) { //������ �ʱ�ȭ��Ű�� �Լ�
	if (s->top != -1) { //���� ������ ������� �ʴٸ�
		for (int i = 0; i < s->top; i++) {
			s->data[i] = 0; //s�� ����Ű�� data �迭�� �� 0���� �ʱ�ȭ��Ű��
		}
		s->top = -1; //top ���� -1�� �ʱ�ȭ
	}
}
void result(char st[], Stack *s) { //���ڿ��� ���� �����͸� ���ڷ� �޴� ����� ��� �Լ�
	push(s,st[0]); //���ڿ� ���� ù ���ڸ� ���ÿ� push
	for (int i = 1; i < strlen(st); i++) { //���ڿ� ���̸�ŭ �ݺ�
		if (st[i]==peek(s)) { //���� ���� ���ڿ� peek �Լ��� ��ȯ���� ���ٸ�
			push(s, st[i]); //push
		}
		else { //���� ���ڿ� peek �Լ��� ��ȯ���� �ٸ��ٸ�
			printf("%d%c", (s->top)+2,pop(s)); //���ÿ� ����ִ� ���� �� ������ pop()��ȯ�� ���
			init_stack(s); //���� �ʱ�ȭ
			push(s, st[i]); //���� ���� push
		}
	}
	printf("%d%c\n", (s->top) + 2, pop(s)); //���ÿ� �����ִ� ���� �� ������ pop() ��ȯ�� ���
	init_stack(s); //���� �ʱ�ȭ
}
int main(void) {
	head();
	Stack s; //����ü ���� s
	s.top = -1; //s �ʱ�ȭ
	char st[MAX_SIZE]; //���ڿ� ������ char�� �迭
	while (true) {//�ݺ�
		printf("\n�ݺ��Ǵ� ���ĺ����� ������ ���ڿ� �Է�<����� 0 �Է�>\n");
		scanf("%s", &st); //����ڷκ��� �Է¹��� ���ڿ� st�� ����
		if (strcmp(st,"0") == 0) break; //���� st���� "0"�� �����ϸ� �ݺ��� ����������
		else { //���� �ٸ���
			result(st, &s); //result()
		}
	}
}