#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#define MAX_SIZE 100 //stack과 문자열 배열 최대 크기를 100으로 지정

void head() {
	printf("====================\n");
	printf("학과:사이버보안전공\n");
	printf("학번:1971090\n");
	printf("성명:한근영\n");
	printf("====================\n");
}

typedef struct Stack { //stack 구조체
	char data[MAX_SIZE]; //데이터를 저장할 사이즈 100의 char형 배열
	int top; //stack의 top 위치를 저장할 정수형 변수
}Stack;

char pop(Stack* s) { //stack의 pop 함수
	if (s->top == -1) { //만약 stack이 비어있으면 다음을 출력하고 비정상 종료
		printf("Stack empty");
		exit(1);
	}
	else { //stack이 비어있지 않다면
		return s->data[(s->top)--]; //인자로 받은 스택 포인터가 가리키는 data 배열의 top위치에 있는 데이터를 반환하고 top 크기 줄이기
	}
}

void push(Stack* s, char n) { //stack의 push 함수
	if (s->top == MAX_SIZE - 1) { //만약 현재 스택이 MAX_SIZE만큼 꽉 차있어서 데이터가 더 들어가지 못하면 다음을 출력
		printf("Overflow");
	}
	else { //stack에 아직 데이터가 더 들어갈 수 있으면
		s->data[++(s->top)] = n; //인자로 받은 스택 포인터가 가리키는 data 배열의 1 증가시킨 top 위치에 인자로 받은 데이터 저장
	}
}

char peek(Stack* s) { //stack의 peek 함수
	if (s->top == -1) { //만약 스택이 비어있으면 다음을 출력하고 비정상 종료
		printf("Stack empty");
		exit(1);
	}
	else return s->data[s->top]; //스택이 비어있지 않다면 s가 가리키는 data 배열의 top 위치에 있는 데이터 값 반환
}

void init_stack(Stack *s) { //스택을 초기화시키는 함수
	if (s->top != -1) { //만약 스택이 비어있지 않다면
		for (int i = 0; i < s->top; i++) {
			s->data[i] = 0; //s가 가리키는 data 배열을 다 0으로 초기화시키고
		}
		s->top = -1; //top 값을 -1로 초기화
	}
}
void result(char st[], Stack *s) { //문자열과 스택 포인터를 인자로 받는 결과값 출력 함수
	push(s,st[0]); //문자열 제일 첫 글자를 스택에 push
	for (int i = 1; i < strlen(st); i++) { //문자열 길이만큼 반복
		if (st[i]==peek(s)) { //만약 현재 문자와 peek 함수의 반환값이 같다면
			push(s, st[i]); //push
		}
		else { //현재 문자와 peek 함수의 반환값이 다르다면
			printf("%d%c", (s->top)+2,pop(s)); //스택에 들어있는 문자 총 개수와 pop()반환값 출력
			init_stack(s); //스택 초기화
			push(s, st[i]); //현재 문자 push
		}
	}
	printf("%d%c\n", (s->top) + 2, pop(s)); //스택에 남아있는 문자 총 개수와 pop() 반환값 출력
	init_stack(s); //스택 초기화
}
int main(void) {
	head();
	Stack s; //구조체 변수 s
	s.top = -1; //s 초기화
	char st[MAX_SIZE]; //문자열 저장할 char형 배열
	while (true) {//반복
		printf("\n반복되는 알파벳으로 구성된 문자열 입력<종료시 0 입력>\n");
		scanf("%s", &st); //사용자로부터 입력받은 문자열 st에 저장
		if (strcmp(st,"0") == 0) break; //만약 st값이 "0"과 동일하면 반복문 빠져나가기
		else { //값이 다르면
			result(st, &s); //result()
		}
	}
}