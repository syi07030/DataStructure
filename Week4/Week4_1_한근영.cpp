#include <stdio.h>
#include<malloc.h>
void head() {
	printf("====================\n");
	printf("학과:사이버보안전공\n");
	printf("학번:1971090\n");
	printf("성명:한근영\n");
	printf("====================\n");
}
typedef struct Node{ //사용자가 입력한 값과 연결할 다음 노드의 주소값을 갖고 있는 Node 구조체
	int data;
	struct Node* link;
}Node;

typedef struct ListInfo { //리스트의 전체 사이즈와 헤더 주소값, 노드 삽입을 위한 tail 주소값을 포함한 ListInfo 구조체
	int size;
	Node* head;
	Node* tail;
}ListInfo;

void printList(ListInfo*info) { //리스트 출력함수
	Node* n = info->head; //포인터 n은 인자로 받은 info의 head,즉 헤더 주소값을 가리킨다
	for (int i = 0; i < info->size; i++) { //리스트의 전체 사이즈, 즉 노드 총 개수만큼 반복
		printf("%d  ",n->data); //n이 가리키는 노드의 data 값을 출력
		n = n->link; //n의 주소값을 다음 노드의 주소값으로 업데이트
	}
}

void insertList(int a, ListInfo*info) { //리스트 마지막에 insert하는 함수
	Node* n = (Node*)malloc(sizeof(Node)); //추가할 노드 생성(동적할당)
	n->data = a; //n이 가리키는 노드의 data 값을 인자로 받은 a값으로 대입
	n->link = NULL; //n이 가리키는 노드의 link 주소값을 NULL로 대입
	if (info->tail == NULL) { //만약 리스트에 노드가 아무것도 없다면
		info->head = n; //head 주소값을 n으로
		info->tail = n; //tail 주소값도 마찬가지
	}
	else { //이미 리스트에 노드가 존재한다면
		info->tail->link = n; //tail이 가리키는 노드의 link에 n을 대입함으로써 노드 연결
		info->tail = n; //tail 주소값 업데이트
	}
	info->size++; //리스트의 노드 개수 증가
}

void findList(ListInfo* info) { //최대, 최소 찾는 함수
	Node* n = info->head; //n이 제일 리스트의 제일 처음 노드를 가리키도록 한다
	int max = n->data; //max값을 n의 data 값으로 초기화
	int min = n->data; //min값도 마찬가지
	for (int i = 0; i < info->size; i++) { //리스트의 노드 개수만큼 반복
		if (n->data > max) {//만약 n이 가리키는 노드의 data값이 max보다 크다면
			max = n->data;//max값 업데이트
		}
		if (n->data < min) { //만약 n이 가리키는 노드의 data값이 min보다 작다면
			min = n->data; //min값 업데이트
		}
		n = n->link; //n이 다음 노드를 가리키도록 업데이트
	}
	printf("\nMax: %d   Min: %d", max, min);
}

int main(void) {
	head();
	int n; //사용자가 입력할 정수를 저장할 변수
	ListInfo* list=(ListInfo*)malloc(sizeof(ListInfo)); //리스트에 대한 정보를 저장할 ListInfo 생성(동적할당)
	list->head = NULL;
	list->tail = NULL;
	list->size = NULL; //ListInfo에 있는 멤버 모두 NULL로 초기화

	printf("Input an integer to add <0 to quit>: ");
	scanf("%d", &n); //입력받아서 n에 저장
	while(n!=0) { //n이 0이 아니면 반복
		insertList(n, list); //노드 삽입
		printf("Input an integer to add <0 to quit>: "); //숫자 입력받는 거 반복
		scanf("%d", &n);
	}

	if (list->size > 0) { //만약 리스트가 비어져 있지 않다면
		printf("<List>\n");
		printList(list); //리스트 출력
		findList(list); //최대값, 최소값 출력
	}
	
}