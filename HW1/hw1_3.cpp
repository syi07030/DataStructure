#include <stdio.h>
#include <stdlib.h>
void head() {
	printf("====================\n");
	printf("학과:사이버보안전공\n");
	printf("학번:1971090\n");
	printf("성명:한근영\n");
	printf("====================\n");
}

typedef struct ListNode { //단순연결리스트 각각의 노드에 대한 구조체
	int data; //노드가 저장하고 있는 데이터값
	struct ListNode* link; //노드가 다음 노드를 가리키는 링크 주소값
}ListNode;

ListNode* insert_first(ListNode* head, int val) { //리스트의 맨 앞에 노드를 삽입하는 함수
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = val; //새로운 노드의 data값에 인자로 받은 val 저장
	p->link = head; //새로운 노드의 링크는 head로 업데이트
	head = p; //head는 p를 가리키도록 한다
	return head;
}

ListNode* insert(ListNode* head, ListNode* pre, int val) { //노드를 삽입할 위치를 인자로 받는 노드 삽입 함수
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = val; //새로운 노드의 data값에 인자로 받은 val 저장
	p->link = pre->link; //새로운 노드의 link는 pre의 link가 가리키는 주소값으로 업데이트
	pre->link = p; //pre가 가리키는 link값은 p
	return head;
}

ListNode* insert_sort(ListNode* head, int num) { //리스트의 올바른 위치에 노드를 삽입하는 함수
	ListNode* p = head; 
	ListNode* tmp = NULL; //새로운 노드를 삽입할 위치를 저장해두기 위한 포인터 변수
	if (head == NULL || head->data>num) return insert_first(head, num); //만약 리스트가 비어있거나 삽입할 위치가 맨 앞이라면 insert_first()호출
	else { //그 외의 경우라면
		while (p != NULL) { //p가 null이 될 때까지 아래 반복
			if (p->data <= num) { //만약 p가 가리키는 데이터가 인자로 받은 num보다 작거나 같으면
				tmp = p; //tmp에는 현재의 p 주소값을 저장하고
				p = p->link; //p는 p의 link가 가리키는 노드로 업데이트
			}
			else { //p가 가리키는 데이터가 인자로 받은 num보다 크다면
				return insert(head, tmp, num); //tmp 위치 다음에 insert
				break;
			}
		}
		if (tmp->data < num) return insert(head, tmp,num); //위의 반복문을 다 돌렸음에도 tmp의 data보다 num이 크면 맨 마지막에 노드 삽입
	}
}

void print_list(ListNode* head) { //리스트 출력하는 함수
	ListNode* p = head;
	while (p != NULL) {
		printf("  %d ->", p->data);
		p = p->link;
	}
	printf("  NULL\n");
}
int main(void) {
	head();
	ListNode* head = NULL; //단순열결리스트를 가리킬 헤드 포인터 초기화
	int num; //사용자가 입력할 숫자를 저장할 변수
	printf("Input data to insert to linkedlist<0 to quit>\n");
	while (true) { 
		scanf("%d", &num);
		if (num == 0) break; //만약 0입력하면 반복문 빠져나가기
		else {
			head = insert_sort(head, num); //insert_sort()호출
			print_list(head); //리스트 프린트
		}
	}
	print_list(head); //리스트 프린트
	printf("Program finished.");
}