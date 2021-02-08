#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100 //�迭�� ������ �ִ� ũ�� 100���� ����

void head() {
	printf("====================\n");
	printf("�а�:���̹���������\n");
	printf("�й�:1971090\n");
	printf("����:�ѱٿ�\n");
	printf("====================\n");
}

void use_array(char s[]) { //�迭�� �̿��� ��Ī���� ���Ī���� ����ϴ� �Լ�
	int ch = 0;//��Ī,���Ī Ȯ���ϴ� ����
	for (int i = 0; i < (strlen(s)/2); i++) { //���ڿ� ��ü ���̿��� 2�� ���� �� ������ ������Ű�� ������ �ݺ�
		if (s[i] != s[strlen(s) - 1-i]) { //��Ī�� �Ǵ� ��ġ�� ���ڰ� ���� �ٸ���
			ch = 1; //ch���� 1�� �����ϰ�
			break; //�ݺ��� ����������
		}
	}
	if (ch == 0) printf("��Ī<�迭>\n"); //���� ch�� �״�� 0�̸� ��Ī
	else printf("���Ī<�迭>\n"); //�ƴϸ� ���Ī
}

char stack[MAX_SIZE]; //������ ���������� ����
int top = -1; //������ top

char pop(void) { //������ pop
	if (top == -1) { //���� ������ ��������� ���� ����ϰ� ����
		printf("Stack empty");
		exit(1);
	}
	else return stack[top--]; //������ ������� �ʴٸ� ������ top�� �ִ� ���ڸ� ��ȯ�ϰ� top ũ�� �ϳ� ���̱�
}

void push(char item) { //������ push
	if (top == MAX_SIZE - 1) { //���� ������ ������ ������ ������ ����ϰ� ����
		printf("Stack overflow");
		exit(1);
	}
	else stack[++top] = item; //������ ������ ���� �ʴٸ� topũ�� �ϳ� ������Ű�� �ű⿡ ���ڷ� ���� ���� ����
}

void use_stack(char s[]) { //���� �̿��� ��Ī���� ���Ī���� Ȯ���ϴ� �Լ�
	int ch = 0;//��Ī,���Ī Ȯ���ϱ� ���� ����
	for (int i = 0; i < (strlen(s) / 2); i++) { //���ڿ� ���̸� 2�� ���� �� ������ ������Ű�� �ݺ������� push
		push(s[i]);
	}
	for (int i = (strlen(s) / 2 - 1); i >= 0; i--) { //pop�� �ϸ鼭 ��Ī���� ���� ���ϱ�
		if (pop() != s[strlen(s) -i-1]) { //���� ���ڰ� ��ġ���� �ʴ´ٸ�
			ch = 1;//ch���� 1�� �����ϰ� �ݺ��� ����������
			break;
		}
	}
	if (ch == 0 && top==-1) printf("��Ī<����>\n"); //���� ch���� 0�̰� ���õ� ����ִٸ� ��Ī
	else { //�ƴϸ� ���Ī
		printf("���Ī<����>\n"); 
		if (top !=- 1) { //������ ������� �ʴ� ��� ���� �ʱ�ȭ
			for (int i = 0; i <= top + 1; i++) {
				stack[i] = NULL; //���� Ȯ���ϱ�
			}
			top = -1;
		}
	}
}

int main(void) {
	head();
	char s[MAX_SIZE]; //����ڰ� �Է��� ���ڿ� �����ϱ� ���� ���ڹ迭
	while (true) {
		printf("\n���ĺ����� ������ ���ڿ� �Է�\n");
		scanf("%s", s);
		if (strcmp(s, "0")==0) break; //���� 0�� �Է��ϸ� �ݺ��� ���������� ����
		use_array(s); //�迭 �̿��� ��Ī���� Ȯ���ϰ� ���
		use_stack(s); //���� �̿��� ��Ī���� Ȯ���ϰ� ���
	}
}