#include <stdio.h>
void head() {
	printf("====================\n");
	printf("�а�:���̹���������\n");
	printf("�й�:1971090\n");
	printf("����:�ѱٿ�\n");
	printf("====================\n");
}
double iter(double a) {//�ݺ��Լ�
	double sum = 0.0;//�� ���ؼ� ��ȯ�� ��
	for (int i = 1; i <= a; i++) {//�ݺ������� sum�� ���ϱ�
		sum += (double)1 / i;
	}
	return sum;//sum�� ��ȯ
}
double recur(double b) {//����Լ�
	if (b == 1) {//a�� 1�� �� 1 ��ȯ
		return 1;
	}
	else {//a�� 1�� �ƴϸ� ��� ȣ��
		return (double)1 / b + recur(b - 1);
	}
}
int main(void) {
	head();
	double n;
	printf("���� ���� �Է�:");
	scanf("%lf", &n); //�Է� �޾Ƽ� n�� ����
	while (n > 0) {//0 ������ �� �Է½� �ݺ�����
		printf("Result from iterative : %.2lf\n", iter(n)); //�ݺ��Լ� ���
		printf("Result from recursive : %.2lf\n", recur(n));//����Լ� ���
		printf("���� ���� �Է�:");//�Է� �ݺ�
		scanf("%lf", &n);
	}
}