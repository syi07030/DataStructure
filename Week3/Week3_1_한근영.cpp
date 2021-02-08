#include <stdio.h>
void head() {
	printf("====================\n");
	printf("학과:사이버보안전공\n");
	printf("학번:1971090\n");
	printf("성명:한근영\n");
	printf("====================\n");
}
void func_recursive(char A[]) { //재귀함수, 인자로 문자 배열 주소 받음
	if (*(A + 1) == NULL) { //만약 현재 *A값이 문자열의 마지막이라면
		printf("%c",*A); //역참조연산자를 이용해 현재 문자 값 출력
	}
	else { //만약 현재 *A값이 문자열의 마지막이 아니라면
		func_recursive((A + 1)); //주소값을 하나 증가시킨, 즉 문자 배열의 다음 인덱스 값에 해당되는 주소를 인자로 재귀 호출
		printf("%c", *A); //역참조연산자를 이용해 문자 값 출력
	}
}
int main(void) {
	head();
	char X[100]; //문자 배열
	printf("Input string\n");
	gets_s(X); //입력받은 문자열을 문자배열에 저장
	puts("변경전:");
	puts(X);
	puts("변경후:");
	func_recursive(X); //재귀함수 호출
	return 0;
}