#include <stdio.h>
#include<malloc.h>
void head() {
	printf("====================\n");
	printf("학과:사이버보안전공\n");
	printf("학번:1971090\n");
	printf("성명:한근영\n");
	printf("====================\n");
}
typedef struct Node { //사용자가 입력한 값과 연결할 양쪽 노드의 주소값을 갖고 있는 Node 구조체
	int data;
	struct Node* llink;
	struct Node* rlink;
}Node;

void printList(Node* head) { //리스트 출력함수
	Node* n = head->rlink; //포인터 n은 인자로 받은 head의 오른쪽 링크 주소값을 가지킨다
	while (n != head) { //n이 head일 때까지 반복
		printf("%d  ", n->data); //n이 가리키는 노드의 data 값을 출력
		n = n->rlink; //n의 주소값을 오른쪽 노드의 주소값으로 업데이트
	}
}

void insertList(int a, Node* pn) { //리스트에 노드 insert하는 함수
	Node* n = (Node*)malloc(sizeof(Node)); //추가할 노드 생성(동적할당)
	n->data = a; //n이 가리키는 노드의 data 값을 인자로 받은 a값으로 대입
	pn->rlink->llink = n; //기존노드의 오른쪽 링크가 가리키는 노드의 왼쪽 링크는 n으로 대입
	n->llink = pn; //n의 왼쪽 링크는 기존노드 주소값으로
	n->rlink = pn->rlink; //n의 오른쪽 링크는 기존노드의 오른쪽 링크가 가리키는 값으로 대입
	pn->rlink = n; //기존노드의 오른쪽 링크는 n의 주소값으로
}

void deleteList(int a, Node* head) { //리스트에서 노드 delete하는 함수
	Node* n = head->rlink; //n은 head의 rlink가 가리키는 주소값
	int ch = 0; //찾는 숫자가 리스트에 존재하는지 여부에 대한 변수
	while (n!= head) { //n이 head가 될 때까지
		if (n->data == a) { //만약 찾는 숫자가 리스트 내에 있으면
			printf("%d is found and deleted",a);
			n->llink->rlink = n->rlink; //삭제할 노드의 왼쪽 노드의 rlink값을 n의 rlink값으로
			n->rlink->llink = n->llink; //삭제할 노드의 오른쪽 노드의 llink값을 n의 llink값으로
			free(n); //노드 n에 할당된 메모리 free
			ch = 1;
			break;
		}
		n = n->rlink; //n 값을 n의 오른쪽 노드 주소값으로
	}
	if (ch == 0) { //만약 찾는 숫자가 리스트에 존재하지 않다면 다음을 출력
		printf("%d is not in the list",a);
	}
}

int main(void) {
	head();
	int n; //사용자가 입력할 정수를 저장할 변수
	Node* head = (Node*)malloc(sizeof(Node)); //헤더 노드 생성(동적할당)
	head->rlink = head; //헤더 노드 초기화
	head->llink = head; //헤더 노드 초기화

	printf("Input an integer to add <0 to quit>: ");
	scanf("%d", &n); //입력받아서 n에 저장
	while (n != 0) { //n이 0일 때까지 반복
		insertList(n, head); //노드 리스트에 삽입
		printf("Input an integer to add <0 to quit>: ");
		scanf("%d", &n);
	}

	if (head != NULL) { //만약 리스트가 비어있지 않다면
		printf("<List>\n");
		printList(head); //리스트 출력
		printf("\nInput a number to search and delete: ");
		scanf("%d", &n); //찾아서 삭제할 숫자 입력받기
		deleteList(n, head); //해당 숫자 찾아서 삭제하기
		printf("\n<List>\n");
		printList(head); //리스트 출력
	}
	
}