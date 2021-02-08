#include <stdio.h>
#include <stdlib.h>
#define SIZE 10 //입력받아서 저장할 key값들 개수 10개로 고정
#define TABLE_SIZE 11 //hash table 크기 11로 고정

void head() {
	printf("====================\n");
	printf("학과:사이버보안전공\n");
	printf("학번:1971090\n");
	printf("성명:한근영\n");
	printf("====================\n");
}

typedef struct { //key값을 갖는 element 구조체
	int key;
}element;

struct list { //각 노드에 대한 정보를 나타내는 구조체
	element item;
	struct list* link;
};

struct list* hash_table[TABLE_SIZE]; //hash table 생성

int hash_function(int key) { //modulo 연산 결과를 반환하는 hash 함수
	return key % TABLE_SIZE;
}

void hash_chain_add(element item, struct list* ht[]) { //새로운 key를 hash table에 추가하는 함수
	int hash_value = hash_function(item.key); //key에 대한 hash 값 저장
	struct list* ptr;
	struct list* node_before = NULL, * node = ht[hash_value];
	for (; node; node_before = node, node = node->link) { //해당 위치의 노드 검색
		if (node->item.key == item.key) { //만약 같은 값이 있다면 다음과 같이 출력
			fprintf(stderr, "%d is already stored\n", item.key);
			return;
		}
	}
	ptr = (struct list*)malloc(sizeof(struct list)); //해당 key값이 저장되어 있지 않다면 동적할당을 통해 노드 생성
	ptr->item = item; //새로운 노드에 key값 저장
	ptr->link = NULL; //새로운 노드 링크 설정
	if (node_before) node_before->link = ptr; //만약 앞에 또다른 노드가 있다면 그 노드 다음 위치로 추가
	else ht[hash_value] = ptr; //해당 위치에 아무런 노드도 없다면 첫 노드로 연결
}

void hash_chain_delete(element item, struct list* ht[]) { //해당 key값을 hash table에서 삭제하는 함수
	struct list* rm; //삭제할 노드를 저장할 포인터
	struct list* pre=NULL; //삭제하기 전의 노드를 가리킬 포인터
	int hash_value = hash_function(item.key); //key에 대한 hash 값 저장
	for (struct list*node = ht[hash_value]; node; node = node->link) { //해당 위치의 노드 검색
		if (node->item.key == item.key) { //만약 같은 값이 있는 노드를 찾으면
			rm = node; //rm에 해당 노드 주소 저장
			if (pre==NULL) { //만약 그 노드가 첫 노드라면
				ht[hash_value]= node->link; //node의 다음 노드를 첫 위치로
			}
			else { //만약 해당 노드가 첫 노드가 아니라면
				pre->link = node->link; //node 다음 노드를 node 앞 노드 바로 다음으로
			}
			free(rm); //삭제할 노드 memory 반환
			return;
		}
		pre = node; //pre node 주소 저장
	}
	fprintf(stderr, "%d is not in the table\n", item.key); //만약 해당 key가 없으면 출력
}

void hash_chain_search(element item, struct list* ht[]) { //key가 hash table 어느 인덱스에 위치하는지 찾는 함수
	struct list* node;
	int hash_value = hash_function(item.key); //key에 대한 hash 값 저장
	for (node = ht[hash_value]; node; node = node->link) { //해당 위치의 노드 검색
		if (node->item.key == item.key) { //만약 같은 key값을 갖는 노드를 찾으면
			fprintf(stderr, "%d is found at index %d\n", item.key, hash_value); //어느 인덱스에 있는지 출력
			return;
		}
	}
	fprintf(stderr, "%d is not in the table\n", item.key); //같은 key값 갖는 노드 없으면 없다고 출력
}

void hash_chain_print(struct list* ht[]) { //hash table 출력하는 함수
	struct list* node; 
	int i;
	printf("\n==============================\n");
	for (i = 0; i < TABLE_SIZE; i++) { //전체 table size만큼 반복해서 출력
		printf("[%d]", i);
		for (node = ht[i]; node; node = node->link) { //해당 위치의 노드 link가 null을 가리킬 때까지 반복해서 출력
			printf(" - %3d", node->item.key);
		}
		printf("\n");
	}
	printf("==============================\n");
}

int main(void) {
	head();

	int data[SIZE]; //사용자가 입력할 key 값들을 저장할 리스트
	printf("Input %d keys to add\n", SIZE);
	for (int i = 0; i < SIZE; i++) { //사용자로부터 key 값들 10개 입력받기
		scanf("%d", &data[i]);
	}
	element e;
	for (int i = 0; i < SIZE; i++) { //입력받은 key값들을 hash table에 add
		e.key = data[i];
		hash_chain_add(e, hash_table);
	}
	hash_chain_print(hash_table); //hash table 출력

	while (true) { //다음을 반복
		int ch;// 사용자가 선택할 operation 번호
		printf("\nChoose operation (1.insert  2.delete  3.search  4.print  5.exit):");
		scanf("%d", &ch); //어떤 operation할지 입력받기
		switch (ch) { //ch값에 따라
			element n;
		case 1: //1이라면
			printf("input data to add:");
			scanf("%d", &(n.key)); //hash table에 삽입할 key값을 입력받고
			hash_chain_add(n, hash_table); //해당 element를 hash table에 삽입
			break;
		case 2: //2라면
			printf("input data to be delete:");
			scanf("%d", &(n.key)); //hash table에서 삭제할 key값을 입력받고
			hash_chain_delete(n, hash_table); //해당 element를 hash table에서 삭제
			break;
		case 3: //3이라면
			printf("input data to search:");
			scanf("%d", &(n.key)); //hash table에서 위치를 찾을 key값을 입력받고
			hash_chain_search(n, hash_table); //해당 위치 찾아서 출력
			break;
		case 4: //4라면
			hash_chain_print(hash_table); //hash table 출력
			break;
		case 5: //5라면
			printf("\nProgram finished");
			exit(0); //프로그램 종료
		default: //그 외의 숫자라면 다음을 출력하고 다시 반복
			printf("Wrong input");
		}
	}
}