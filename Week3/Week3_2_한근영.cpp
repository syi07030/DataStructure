#include <stdio.h>
#define ROWS 4 //ROWS���� 4�� ����
#define COLS 3 //COLS���� 3���� ����
void head() {
	printf("====================\n");
	printf("�а�:���̹���������\n");
	printf("�й�:1971090\n");
	printf("����:�ѱٿ�\n");
	printf("====================\n");
}
void matrixInput(int Arr[ROWS][COLS]) { //�迭�� �Է¹޾� �����ϴ� �Լ�
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			scanf("%d", &Arr[i][j]); //�Է¹޾Ƽ� ����
		}
	}
}
void matrixPrint(int Arr[ROWS][COLS]) { //�迭�� ����ϴ� �Լ�
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			if (Arr[i][j] >= 10 || Arr[i][j]<0) { //��� ����� �� ����� �����ϰ� ���߱� ���� �� �ڸ����� �Ѱų� �����̸�
				printf(" %d", Arr[i][j]); //�̿� ���� ���
			}
			else { //���� �ش���� ������ �Ʒ��� ���� ���
				printf("  %d", Arr[i][j]);
			}
		}
		printf("\n");
	}
	printf("\n");
}
void matrixAdd(int Arr1[ROWS][COLS], int Arr2[ROWS][COLS], int Arr3[ROWS][COLS]) { //����� ������ �����ϴ� �Լ�
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			Arr3[i][j] = Arr1[i][j] + Arr2[i][j]; //Arr1�� Arr2�� �ش� �ε��� ���� ���ؼ� Arr3�� ����
		}
	}
}
int main(void) {
	head();
	int A[ROWS][COLS], B[ROWS][COLS], C[ROWS][COLS]; //int�� 2���� �迭 A,B,C ����
	printf("Input values for %dX%d matrix A\n", ROWS, COLS);
	matrixInput(A); //A �Է¹޾Ƽ� ����
	printf("Input values for %dX%d matrix B\n", ROWS, COLS);
	matrixInput(B); //B �Է¹޾Ƽ� ����
	puts("<A>");
	matrixPrint(A); //A ���
	puts("<B>");
	matrixPrint(B); //B ���
	puts("<A+B>");
	matrixAdd(A, B, C); //A�� B�� ���ؼ� C�� ����
	matrixPrint(C); //C ���
	return 0;
}