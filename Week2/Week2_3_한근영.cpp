#include <stdio.h>
void head() {
	printf("====================\n");
	printf("학과:사이버보안전공\n");
	printf("학번:1971090\n");
	printf("성명:한근영\n");
	printf("====================\n");
}
double iter(double a) {//반복함수
	double sum = 0.0;//다 더해서 반환할 값
	for (int i = 1; i <= a; i++) {//반복문으로 sum값 구하기
		sum += (double)1 / i;
	}
	return sum;//sum값 반환
}
double recur(double b) {//재귀함수
	if (b == 1) {//a가 1일 때 1 반환
		return 1;
	}
	else {//a가 1이 아니면 재귀 호출
		return (double)1 / b + recur(b - 1);
	}
}
int main(void) {
	head();
	double n;
	printf("양의 정수 입력:");
	scanf("%lf", &n); //입력 받아서 n에 저장
	while (n > 0) {//0 이하의 값 입력시 반복종료
		printf("Result from iterative : %.2lf\n", iter(n)); //반복함수 결과
		printf("Result from recursive : %.2lf\n", recur(n));//재귀함수 결과
		printf("양의 정수 입력:");//입력 반복
		scanf("%lf", &n);
	}
}