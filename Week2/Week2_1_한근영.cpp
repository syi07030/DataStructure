#include <stdio.h>
void head() {
	printf("====================\n");
	printf("학과:사이버보안전공\n");
	printf("학번:1971090\n");
	printf("성명:한근영\n");
	printf("====================\n");
}

int main(void) {//메인 함수
	head();
	int deci = 0;//입력받을 수
	printf("양의정수 입력:");
	scanf("%d", &deci);//양의 정수 입력받아서 저장
	int binary[100];//이진수 값 저장할 배열
	int quo = deci;
	int i = 0; //이진수 값 출력하기 위해 필요한 지역변수
	while (quo > 0) {//quo값이 양의 정수일 때만 돌아감
		binary[i] = quo % 2; //quo를 2로 나눈 나머지를 저장
		quo/=2;//quo 값 업데이트
		i++;
	}
	printf("십진수 %d의 이진표현:", deci);
	for (int j = i-1; j >= 0; j--) {//반복문 이용해 출력
		printf("%d", binary[j]);
	}
}