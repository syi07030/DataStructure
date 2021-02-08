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

typedef struct { //element에 대한 구조체
	int key;
}element;
typedef struct { //HeapType에 대한 구조체
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

void init(HeapType* h) { //heap 초기화 시키는 함수
	h->heap_size = 0;
}

int find_index(HeapType* h, element n) { //element 노드 인덱스 반환하는 함수
	for (int i = 1; i <= h->heap_size; i++) {
		if (h->heap[i].key == n.key) { //만약 해당 노드의 key값과 인자로 받은 element의 key값이 일치하면
			return i; //해당 인덱스 반환
		}
	}
}

bool same_value(HeapType* h, int value) { //해당 값이 heap에 존재하는지 판단하는 함수
	for (int i = 1; i <= h->heap_size; i++) {
		if (h->heap[i].key == value) { //만약 해당 노드의 key값과 인자로 받은 value값이 같다면
			return true; //true 반환
		}
	}
	return false; //없으면 false 반환
}

void insert_heap(HeapType* h, element item) { //새로운 노드 추가하는 함수
	if (same_value(h,item.key) == true) { //만약 똑같은 key값을 갖는 노드가 이미 존재하면 다음 출력
		printf("same value exists\n");
	}
	else { //똑같은 key값을 갖는 노드가 존재하지 않는다면
		int i;
		i = ++(h->heap_size); //노드 추가 후 증가된 말단노드 인덱스 대입
		while ((i != 1) && (item.key > h->heap[i / 2].key)) { //트리를 거슬러 올라가면서 부모 노드 key값과 비교
			h->heap[i] = h->heap[i / 2]; //추가된 노드 key값보다 작은 경우 부모노드를 내림
			i /= 2; //그 부모로 위치 이동
		}
		h->heap[i] = item; //최종 결정된 위치에 새로운 노드 삽입
	}
}

element delete_item(HeapType* h, element e) { //element 노드 삭제하고 heap 재구성하는 함수
	int parent = find_index(h,e), child = parent*2; //인자로 받은 e의 key값을 갖는 노드의 위치를 찾아서 parent로, child는 그 자식
	element item = h->heap[1];
	element temp = h->heap[h->heap_size--];
	while (child <= h->heap_size) { //최대 말단까지 트리를 내려가면서 자식노드 key값과 temp key값 비교
		if ((child < h->heap_size) && (h->heap[child].key < h->heap[child + 1].key)) child++; //자식 노드가 2개일 경우 더 큰값 찾기
		if (temp.key >= h->heap[child].key) break; //자식노드보다 신규노드 key값이 더 크면 반복 종료, 위치 확정
		h->heap[parent] = h->heap[child]; //자식노드 key값보다 더 크면 부모 노드에 자식 노드 복사
		parent = child; //부모 인덱스를 자식 인덱스로 변경
		child *= 2; //그 아래 자식 노드로 위치 이동
	}
	h->heap[parent] = temp; //확정위치에 신규노드 삽입
	return item;
}

void print_heap(HeapType* max_h) { //heap 출력하는 함수
	for (int i = 1; i <= max_h->heap_size; i++) {
		printf("%d ", max_h->heap[i]);
	}
	printf("\n");
}

int main(void) {
	head();

	HeapType* max_heap = (HeapType*)malloc(sizeof(HeapType)); //heap 생성(동적할당)
	init(max_heap); //heap 초기화
	char ch;
	while (true) { //반복
		char ch;
		printf("Input Operation I(Insert)  D(Delete)  P(Print)  X(Exit): "); //어떤 operation할지 입력받기
		scanf(" %c", &ch);
		switch (ch) { //입력받은 값에 따라
		case 'I':
			element v;
			printf("Input value to insert: "); //추가할 key값 입력받기
			scanf("%d", &v);
			insert_heap(max_heap, v); //heap에 새로운 노드 추가
			break;
		case 'D':
			element d;
			printf("Input value to delete: "); //삭제할 key값 입력받기
			scanf("%d", &d);
			delete_item(max_heap,d); //해당 key값 갖는 노드 삭제
			break;
		case 'P':
			print_heap(max_heap); //heap 프린트
			break;
		case 'X':
			exit(0); //프로그램 종료
		default:
			printf("Wrong Input\n"); //다음을 출력하고 다시 반복
			break;
		}
	}
}