#include <stdio.h>
void head() {
	printf("====================\n");
	printf("�а�:���̹���������\n");
	printf("�й�:1971090\n");
	printf("����:�ѱٿ�\n");
	printf("====================\n");
}

int main(void) {//���� �Լ�
	head();
	int deci = 0;//�Է¹��� ��
	printf("�������� �Է�:");
	scanf("%d", &deci);//���� ���� �Է¹޾Ƽ� ����
	int binary[100];//������ �� ������ �迭
	int quo = deci;
	int i = 0; //������ �� ����ϱ� ���� �ʿ��� ��������
	while (quo > 0) {//quo���� ���� ������ ���� ���ư�
		binary[i] = quo % 2; //quo�� 2�� ���� �������� ����
		quo/=2;//quo �� ������Ʈ
		i++;
	}
	printf("������ %d�� ����ǥ��:", deci);
	for (int j = i-1; j >= 0; j--) {//�ݺ��� �̿��� ���
		printf("%d", binary[j]);
	}
}