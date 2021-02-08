#include <stdio.h>
#include<stdlib.h>
#include<math.h>

void head() {
	printf("====================\n");
	printf("학과:사이버보안전공\n");
	printf("학번:1971090\n");
	printf("성명:한근영\n");
	printf("====================\n");
}

typedef struct ListNode { //단순연결리스트의 각 노드에 대한 구조체
	int coef; //계수를 저장할 변수
	int exponent; //차수를 저장할 변수
	struct ListNode* link; //다음 노드를 가리키는 link 주소값 저장할 변수
}ListNode;

typedef struct ListType { //리스트에 대한 정보를 저장하는 구조체
	int size; //리스트 전체 사이즈를 저장하는 변수
	ListNode* head; //가장 앞에 있는 노드를 가리키는 포인터 변수
	ListNode* tail; //가장 뒤에 있는 노드를 가리키는 포인터 변수
};

void add_node(ListType* poly, int co, int ex) { //노드를 생성하고 연결해 다항식 전체를 저장하는 함수
	ListNode* tmp = (ListNode*)malloc(sizeof(ListNode));
	if (tmp == NULL) { //제대로 메모리 동적할당이 안 되면 다음을 출력하고 종료
		printf("memeory allocation error\n");
		exit(1);
	}
	tmp->coef = co; //인자로 받은 계수값 노드에 저장
	tmp->exponent = ex; //인자로 받은 차수값 노드에 저장
	tmp->link = NULL; //노드의 링크 값은 null로 초기화
	if (poly->size == 0) { //만약 리스트가 비어있다면
		poly->head = poly->tail = tmp; //head 포인터와 tail 포인터 모두 tmp
	}
	else { //리스트가 비어있지 않다면
		poly->tail->link = tmp;
		poly->tail = tmp; //리스트 마지막에 노드 추가
	}
	poly->size++; //리스트 사이즈 값 1씩 증가
}

void print_poly(ListType* poly) { //다항식 출력하는 함수
	printf("<Polynomial>\n");
	ListNode* node = poly->head; //head가 가리키는 노드부터 시작
	for (int i = 0; i < poly->size-1; i++) {
		printf("%dx^%d + ", node->coef, node->exponent); //계수와 차수 출력
		node = node->link; //node가 가리키는 노드 위치 업데이트
	}
	printf("%dx^%d\n",node->coef,node->exponent); //마지막 노드의 계수와 차수 출력
}

void cal_poly(ListType* poly, int x) { //인자로 x값 받아서 다항식 계산하는 함수
	int sum = 0;
	ListNode* node = poly->head; //head가 가리키는 노드부터 시작
	for (int i = 0; i < poly->size; i++) {
		sum += (node->coef) * int(pow(x, node->exponent)); //값 계산해서 sum에 더하기
		node=node->link; //node가 가리키는 노드 위치 업데이트
	}
	printf("Result of polynomial with x: %d", sum); //결과값 출력
}

int main(void) {
	head();
	ListType* poly = (ListType*)malloc(sizeof(ListType));
	poly->head = NULL;
	poly->tail = NULL;
	poly->size = 0; //poly 초기화
	int coef; //사용자로부터 계수 입력받을 변수
	int exponent;//사용자로부터 차수 입력받을 변수
	int x; //사용자로부터 x값 입력받을 변수
	printf("Input coef and exponent of polynomial<마지막항: exponent를 0으로 입력>\n");
	while (true) {
		scanf("%d %d", &coef, &exponent);
		add_node(poly, coef, exponent); //다항식 연결리스트 만들기
		if (exponent == 0) break; //만약 차수값이 0이면 반복문 빠져나오기
	}
	print_poly(poly); //다항식 출력
	printf("\nInput the value x: ");
	scanf("%d", &x);
	cal_poly(poly, x); //x값 다항식에 넣어서 계산하고 출력
}