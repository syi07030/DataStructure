#include <stdio.h>
void head() {
	printf("====================\n");
	printf("�а�:���̹���������\n");
	printf("�й�:1971090\n");
	printf("����:�ѱٿ�\n");
	printf("====================\n");
}
void iter(int i) { //�ݺ��Լ�
	for (int j = i; j >= 0; j--) { //�ݺ��� ������ ���
		printf("%d ", j);
	}
}
void recur(int i) { //����Լ�
	printf("%d ", i);
	if (i > 0) {
		recur(i - 1); //��� ȣ��
	}
}

int main(void) {
	head();
	int n = 0;
	printf("���� ���� �Է�:");
	scanf("%d", &n);//���� ���� �Է¹ޱ�
	printf("�ݺ��Լ� ȣ��:");
	iter(n);//�ݺ��Լ� ȣ��
	printf("\n����Լ� ȣ��:");
	recur(n);//����Լ� ȣ��
}