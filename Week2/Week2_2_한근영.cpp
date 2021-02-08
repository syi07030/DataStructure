#include <stdio.h>
void head() {
	printf("====================\n");
	printf("학과:사이버보안전공\n");
	printf("학번:1971090\n");
	printf("성명:한근영\n");
	printf("====================\n");
}
void iter(int i) { //반복함수
	for (int j = i; j >= 0; j--) { //반복문 돌려서 출력
		printf("%d ", j);
	}
}
void recur(int i) { //재귀함수
	printf("%d ", i);
	if (i > 0) {
		recur(i - 1); //재귀 호출
	}
}

int main(void) {
	head();
	int n = 0;
	printf("양의 정수 입력:");
	scanf("%d", &n);//양의 정수 입력받기
	printf("반복함수 호출:");
	iter(n);//반복함수 호출
	printf("\n재귀함수 호출:");
	recur(n);//재귀함수 호출
}