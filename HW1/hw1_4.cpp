#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100 //배열과 스택의 최대 크기 100으로 지정

void head() {
	printf("====================\n");
	printf("학과:사이버보안전공\n");
	printf("학번:1971090\n");
	printf("성명:한근영\n");
	printf("====================\n");
}

void use_array(char s[]) { //배열을 이용해 대칭인지 비대칭인지 출력하는 함수
	int ch = 0;//대칭,비대칭 확인하는 변수
	for (int i = 0; i < (strlen(s)/2); i++) { //문자열 전체 길이에서 2로 나눈 몫 전까지 증가시키며 다음을 반복
		if (s[i] != s[strlen(s) - 1-i]) { //대칭이 되는 위치의 문자가 만약 다르면
			ch = 1; //ch값을 1로 변경하고
			break; //반복문 빠져나가기
		}
	}
	if (ch == 0) printf("대칭<배열>\n"); //만약 ch가 그대로 0이면 대칭
	else printf("비대칭<배열>\n"); //아니면 비대칭
}

char stack[MAX_SIZE]; //스택을 전역변수로 선언
int top = -1; //스택의 top

char pop(void) { //스택의 pop
	if (top == -1) { //만약 스택이 비어있으면 다음 출력하고 종료
		printf("Stack empty");
		exit(1);
	}
	else return stack[top--]; //스택이 비어있지 않다면 스택의 top에 있는 문자를 반환하고 top 크기 하나 줄이기
}

void push(char item) { //스택의 push
	if (top == MAX_SIZE - 1) { //만약 스택이 가득차 있으면 다음을 출력하고 종료
		printf("Stack overflow");
		exit(1);
	}
	else stack[++top] = item; //스택이 가득차 있지 않다면 top크기 하나 증가시키고 거기에 인자로 받은 문자 저장
}

void use_stack(char s[]) { //스택 이용해 대칭인지 비대칭인지 확인하는 함수
	int ch = 0;//대칭,비대칭 확인하기 위한 변수
	for (int i = 0; i < (strlen(s) / 2); i++) { //문자열 길이를 2로 나눈 몫 전까지 증가시키며 반복적으로 push
		push(s[i]);
	}
	for (int i = (strlen(s) / 2 - 1); i >= 0; i--) { //pop을 하면서 대칭인지 문자 비교하기
		if (pop() != s[strlen(s) -i-1]) { //만약 문자가 일치하지 않는다면
			ch = 1;//ch값을 1로 변경하고 반복문 빠져나가기
			break;
		}
	}
	if (ch == 0 && top==-1) printf("대칭<스택>\n"); //만약 ch값도 0이고 스택도 비어있다면 대칭
	else { //아니면 비대칭
		printf("비대칭<스택>\n"); 
		if (top !=- 1) { //스택이 비어있지 않는 경우 스택 초기화
			for (int i = 0; i <= top + 1; i++) {
				stack[i] = NULL; //여기 확인하기
			}
			top = -1;
		}
	}
}

int main(void) {
	head();
	char s[MAX_SIZE]; //사용자가 입력할 문자열 저장하기 위한 문자배열
	while (true) {
		printf("\n알파벳으로 구성된 문자열 입력\n");
		scanf("%s", s);
		if (strcmp(s, "0")==0) break; //만약 0을 입력하면 반복문 빠져나가서 종료
		use_array(s); //배열 이용해 대칭인지 확인하고 출력
		use_stack(s); //스택 이용해 대칭인지 확인하고 출력
	}
}