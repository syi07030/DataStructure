#include <stdio.h>
#define ROWS 4 //ROWS값을 4로 고정
#define COLS 3 //COLS값을 3으로 고정
void head() {
	printf("====================\n");
	printf("학과:사이버보안전공\n");
	printf("학번:1971090\n");
	printf("성명:한근영\n");
	printf("====================\n");
}
void matrixInput(int Arr[ROWS][COLS]) { //배열을 입력받아 저장하는 함수
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			scanf("%d", &Arr[i][j]); //입력받아서 저장
		}
	}
}
void matrixPrint(int Arr[ROWS][COLS]) { //배열을 출력하는 함수
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			if (Arr[i][j] >= 10 || Arr[i][j]<0) { //행렬 출력할 때 모양을 일정하게 맞추기 위해 두 자리수가 넘거나 음수이면
				printf(" %d", Arr[i][j]); //이와 같이 출력
			}
			else { //위에 해당되지 않으면 아래와 같이 출력
				printf("  %d", Arr[i][j]);
			}
		}
		printf("\n");
	}
	printf("\n");
}
void matrixAdd(int Arr1[ROWS][COLS], int Arr2[ROWS][COLS], int Arr3[ROWS][COLS]) { //행렬의 덧셈을 수행하는 함수
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			Arr3[i][j] = Arr1[i][j] + Arr2[i][j]; //Arr1과 Arr2의 해당 인덱스 값을 더해서 Arr3에 저장
		}
	}
}
int main(void) {
	head();
	int A[ROWS][COLS], B[ROWS][COLS], C[ROWS][COLS]; //int형 2차원 배열 A,B,C 선언
	printf("Input values for %dX%d matrix A\n", ROWS, COLS);
	matrixInput(A); //A 입력받아서 저장
	printf("Input values for %dX%d matrix B\n", ROWS, COLS);
	matrixInput(B); //B 입력받아서 저장
	puts("<A>");
	matrixPrint(A); //A 출력
	puts("<B>");
	matrixPrint(B); //B 출력
	puts("<A+B>");
	matrixAdd(A, B, C); //A와 B를 더해서 C에 저장
	matrixPrint(C); //C 출력
	return 0;
}