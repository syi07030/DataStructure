#include <stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100 //stack 최대 크기를 100으로 지정

void head() {
	printf("====================\n");
	printf("학과:사이버보안전공\n");
	printf("학번:1971090\n");
	printf("성명:한근영\n");
	printf("====================\n");
}

typedef struct Stack { //stack 구조체
	int data[MAX_SIZE]; //데이터를 저장할 사이즈 100의 정수형 배열
	int top; //stack의 top 위치를 저장할 정수형 변수
}Stack;

int pop(Stack* s) { //stack의 pop 함수
	if (s->top == -1) { //만약 stack이 비어있으면 다음을 출력하고 비정상 종료
		printf("Stack empty");
		exit(1);
	}
	else { //stack이 비어있지 않다면
		return s->data[(s->top)--]; //인자로 받은 스택 포인터가 가리키는 data 배열의 top위치에 있는 데이터를 반환하고 top 크기 줄이기
	}
}

void push(Stack* s, int n) { //stack의 push 함수
	if (s->top == MAX_SIZE - 1) { //만약 현재 스택이 MAX_SIZE만큼 꽉 차있어서 데이터가 더 들어가지 못하면 다음을 출력
		printf("Overflow");
	}
	else { //stack에 아직 데이터가 더 들어갈 수 있으면
		s->data[++(s->top)] = n; //인자로 받은 스택 포인터가 가리키는 data 배열의 1 증가시킨 top 위치에 인자로 받은 데이터 저장
	}
}
void toBinary(Stack *s, int n) { //스택 포인터와 십진수를 인자로 받아 이진수로 반환한 결과를 출력하는 함수
	int r; //2로 나눈 나머지 저장할 변수
	while (n / 2 >=1) { //n을 2로 나눈 몫이 0이 되기 전까지 반복
		r = n % 2; //r에 n을 2로 나눈 나머지 값 저장
		push(s, r); //r값을 인자로 받은 스택 포인터가 가리키는 스택에 push
		n = n / 2; //n에 n을 2로 나눈 몫 값을 저장
	}
	push(s, n); //위의 반복이 끝난 후 n을 push
	printf("이진수 표현: ");
	while (s->top > -1) { //s가 가리키는 top의 값이 -1이 되기 전까지, 즉 스택이 빈 상태가 되기 전까지
		printf("%d",pop(s)); //스택에서 pop한 값을 출력
	}
	printf("\n");
}
int main(void) {
	head();
	Stack s; //구조체 변수 s
	s.top = -1; //top값을 -1로 함으로써 s 초기화
	int num; //사용자가 입력한 값을 저장하는 변수
	while(true){ //반복
		printf("\n십진수 입력<종료: 0 이하 입력>\n");
		scanf("%d", &num); //입력한 값 num에 저장
		if (num <= 0) break; //만약 num이 0 이하면 반복문 나가기
		else toBinary(&s, num); //num이 0보다 크면 toBinary() 실행(인자로 구조체 변수 s의 주소값과 입력받은 십진수 값)
	}
}