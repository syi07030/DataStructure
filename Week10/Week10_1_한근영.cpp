#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200
void head() {
	printf("====================\n");
	printf("학과:사이버보안전공\n");
	printf("학번:1971090\n");
	printf("성명:한근영\n");
	printf("====================\n");
}

typedef struct { //element 구조체
	int key;
}element;
typedef struct { //HeapType 구조체, heap 노드 위치와 사이즈에 대한 정보
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

void init(HeapType* h) { //Heap 초기화 시키는 함수
	h->heap_size = 0;
}

void insert_max_heap(HeapType* h, element item) { //max Heap에 새로운 노드 삽입하는 함수
	int i;
	i = ++(h->heap_size); //노드 추가 후 증가된 말단 노드 인덱스를 i에 저장
	while ((i != 1) && (item.key > h->heap[i / 2].key)) { //트리를 거슬러 올라가면서 부모 노드 key와 비교
		h->heap[i] = h->heap[i / 2]; //추가된 key보다 작은 경우 부모노드를 내리고
		i /= 2; //인덱스를 그 부모로 위치 이동시킴
	}
	h->heap[i] = item; //최종 결정된 위치에 새로운 노드 삽입
}

element delete_max_heap(HeapType* h) { //max Heap에서 루트 노드 삭제하는 함수
	int parent = 1, child = 2; //두 번째 노드부터 루트 노드와 비교시작
	element item = h->heap[1]; //삭제되는 노드
	element temp = h->heap[h->heap_size--]; //말단노드를 temp에 저장
	while (child <= h->heap_size) { //가장 말단 노드까지 내려가면서 자식노드 key값과 temp key값 비교
		if ((child < h->heap_size) && (h->heap[child].key < h->heap[child + 1].key)) child++; //만약 자식 노드가 2개일 경우 둘 중 큰 값을 찾고 subtree 선택
		if (temp.key >= h->heap[child].key) break; //만약 자식노드보다 신규노드 key가 크면 위치 확정되어 반복 빠져나옴
		h->heap[parent] = h->heap[child]; //자식노드 key가 더 크면 부모 노드에 자식 노드 복사
		parent = child; //부모 인덱스를 자식 인덱스로
		child *= 2; //자식 노드는 그 아래 자식 노드로 위치 이동
	}
	h->heap[parent] = temp; //확정위치에 신규노드 삽입
	return item; //삭제된 노드 반환
}

void insert_min_heap(HeapType* h, element item) { //min Heap에서 새로운 노드 삽입하는 함수
	int i;
	i=++(h->heap_size); //노드 추가 후 증가된 말단노드 인덱스 저장
	while ((i != 1) && (item.key < h->heap[i / 2].key)) { //트리를 거슬러 올라가면서 부모 노드 key값과 비교
		h->heap[i] = h->heap[i / 2]; //추가된 노드 key값보다 큰 경우 부모 노드를 내리고
		i /= 2; //인덱스 새로운 위치인 부모로 이동
	}
	h->heap[i] = item; //최종 결정된 위치에 새로운 노드 삽입
}

element delete_min_heap(HeapType* h) { //min Heap에서 루트 노드 삭제하는 함수
	int parent = 1, child = 2; //두번째 노드부터 루트 노드와 비교 시작
	element item = h->heap[1]; //삭제되는 노드 저장
	element temp = h->heap[(h->heap_size)--]; //말단노드를 temp에 대입
	while (child <= h->heap_size) { //최대 말단 노드까지 트리 내려가면서 자식노드 key값과 temp key값 비교
		if ((child < h->heap_size) && (h->heap[child].key > h->heap[child + 1].key)) child++; //자식 노드가 두 개면 둘 중 작은 값 찾기
		if (temp.key < h->heap[child].key) break; //자식보다 신규노드 key값이 작으면 위치 확정, 반복문 나오기
		h->heap[parent] = h->heap[child]; //자식노드 key가 더 작으며ㅕㄴ 부모 노드에 자식 노드 복사
		parent = child; //부모 인덱스를 자식 인덱스로 변경
		child *= 2; //그 아래 자식 노드 위치로 이동
	}
	h->heap[parent] = temp; //확정위치에 신규노드 삽입
	return item; //삭제된 노드 반환
}

void print_heap(HeapType* max_h,HeapType*min_h) { //heap 출력하는 함수
	printf("<Max Heap>\n");
	for (int i = 1; i <= max_h->heap_size; i++) { //max heap 출력
		printf("%d ", max_h->heap[i]);
	}
	printf("\n<Min Heap>\n");
	for (int i = 1; i <= min_h->heap_size; i++) { //min heap 출력
		printf("%d ", min_h->heap[i]);
	}
	printf("\n");
}

int main(void) {
	head();

	HeapType* min_heap = (HeapType*)malloc(sizeof(HeapType)); //min heap 생성(동적할당)
	HeapType* max_heap = (HeapType*)malloc(sizeof(HeapType));//max heap 생성(동적할당)
	init(min_heap); //min heap 초기화
	init(max_heap);//max heap 초기화
	char ch;
	while (true) {//반복
		char ch;
		printf("Input Operation I(Insert)  D(Delete)  X(Exit): ");
		scanf(" %c", &ch); //어떤 operation을 할지 입력받기
		switch (ch) { //입력받은 값에 따라
		case 'I':
			element v;
			printf("Input value to insert: "); //삽입할 값을 입력받기
			scanf("%d", &v);
			insert_max_heap(max_heap, v); //새로운 노드 max heap에 추가
			insert_min_heap(min_heap, v); //새로운 노드 min heap에 추가
			print_heap(max_heap, min_heap); //각각 프린트
			break;
		case 'D':
			delete_max_heap(max_heap); //max heap에서 루트 노드 삭제
			delete_min_heap(min_heap); //min heap에서 루트 노드 삭제
			print_heap(max_heap, min_heap); //각각 프린트
			break;
		case 'X':
			exit(0); //프로그램 종료
		default:
			printf("Wrong Input\n"); //다음을 프린트하고 다시 반복
			break;
		}
	}
}