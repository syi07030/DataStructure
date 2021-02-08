#include <stdio.h>
#include <stdlib.h>
void head() {
	printf("====================\n");
	printf("학과:사이버보안전공\n");
	printf("학번:1971090\n");
	printf("성명:한근영\n");
	printf("====================\n");
}

typedef struct ListNode { //이중원형연결리스트의 각 노드에 대한 구조체
	int data; //노드에 저장할 데이터 변수
	struct ListNode* llink; //왼쪽 노드를 가리키는 링크
	struct ListNode* rlink; //오른쪽 노드를 가리키는 링크
}ListNode;

void add_last(ListNode*head,int num) { //리스트 끝에 노드 삽입하는 함수
	ListNode* node = (ListNode*)malloc(sizeof(ListNode)); //새로운 노드 동적 할당
	if (node == NULL) { //만약 할당이 제대로 안 된다면 아래 출력하고 종료
		printf("memory allocation error\n");
		exit(1);
	}
	node->data = num;
	node->llink = head->llink;
	node->rlink = head;
	head->llink->rlink = node;
	head->llink = node; //리스트 끝에 노드 삽입하고 헤더 노드와 이전에 마지막에 위치했던 노드와 각각 이중 연결시키기
}

void print_right(ListNode* head) { //올바른 순서로 리스트 출력하는 함수
	ListNode* node = head->rlink; //헤더 노드의 오른쪽 노드부터 시작
	while (node != head->llink) { //헤더 노드의 왼쪽 노드로 올때까지 반복
		printf("  %d  <->", node->data); //노드의 data값 출력
		node = node->rlink; //node가 가리키는 노드 위치 업데이트
	}
	printf("  %d", node->data); //마지막 헤더 노드의 왼쪽 노드의 데이터값 출력
}

void print_reverse(ListNode* head) { //역순으로 리스트 출력하는 함수
	ListNode* node = head->llink; //헤더 노드의 왼쪽 노드부터 시작
	while (node != head->rlink) { //헤더 노드의 오른쪽 노드로 올때까지 반복
		printf("  %d  <->", node->data); //노드의 data값 출력
		node = node->llink; //node가 가리키는 노드 위치 업데이트
	}
	printf("  %d", node->data); //마지막 헤더 노드의 오른쪽 노드의 데이터값 출력
}
int main(void) {
	head();
	ListNode* head = (ListNode*)malloc(sizeof(ListNode)); //헤더 노드 생성
	head->rlink = head; 
	head->llink = head;//헤더 노드 초기화

	int n; //사용자가 입력할 숫자 저장할 변수
	printf("Input data in dual linkedlist<0 to quit>\n");
	while (true) {
		scanf("%d", &n);
		if (n == 0) break;
		else add_last(head, n); //리스트 마지막에 노드 추가
	}
	print_right(head); //올바른 순서로 리스트 출력
	printf("\nPrint the list in reverse order\n");
	print_reverse(head); //역순으로 리스트 출력
}