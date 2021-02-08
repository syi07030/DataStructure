#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "quick_sort.h"
#define SIZE 100 //리스트 사이즈 100으로 고정

void head() {
	printf("====================\n");
	printf("학과:사이버보안전공\n");
	printf("학번:1971090\n");
	printf("성명:한근영\n");
	printf("====================\n");
}

typedef struct { //인덱스 테이블 구조체
	int key; //key값 저장
	int index; //index값 저장
}itable;

int list[SIZE]; //list 전역변수로 선언

int seq_search(int key, int low, int high, int interval) { //순차탐색
	int location=-1;
	for (int i = low*interval; i <= high*interval; i++) { //인자로 받은 low*interval에서 high*interval까지 반복
		if (list[i] == key) //만약 list 해당 인덱스에 저장된 값이 key와 같다면
			location= i; //location에 해당 인덱스 저장
	}
	return location; //location 반환
}

int index_search(int key, int n, itable *index_list, int INDEX_SIZE, int interval) { //색인순차탐색
	int i, low, high;
	if (key<list[0] || key>list[n - 1]) return -1; //범위 밖인 경우 종료
	for (i = 0; i < INDEX_SIZE; i++) {
		if (index_list[i].key <= key && index_list[i + 1].key > key) break; //해당키가 포함된 위치 찾기
	}
	if (i == INDEX_SIZE) { //마지막 index구간에 key가 포함된 경우
		low = index_list[i-1].index;
		high = n;
	}
	else { //특정 index i~i+1 사이에 key가 포함된 경우
		low = index_list[i].index;
		high = index_list[i + 1].index;
	}
	printf("index location: %d", low); //key가 위치할 것으로 추정되는 index location 출력
	return seq_search(key, low, high,interval); //순차탐색으로 어디에 위치하는지 인덱스 값 반환
}
int main(void) {
	head();
	srand(time(NULL)); //seed값 달라지도록 설정
	int key=0, res=0, interval=0;
	for (int i = 0; i < SIZE; i++) { //0~999 사이의 난수 100개 생성
		list[i] = rand() % 1000;
	}
	for (int i = 0; i < SIZE; i++) { //리스트 출력
		if (i % 10 == 0) putchar('\n');
		printf("%4d", list[i]);
	}
	printf("\n\n<정렬결과>\n");
	quick_sort(list, 0, SIZE); //quick sort로 정렬
	for (int i = 0; i < SIZE; i++) { //정렬한 리스트 출력
		if (i % 10 == 0) putchar('\n');
		printf("%4d", list[i]);
	}
	printf("\n\nInput index interval(1~100):");
	scanf("%d", &interval); //사용자로부터 index interval 입력받기
	int index_size;
	//index_size 설정하기
	if (100 % interval == 0) index_size = 100 / interval;
	else index_size = (int)(100 / interval) + 1;
	itable* index_list=(itable*)malloc(sizeof(itable)*index_size); //index_list 포인터 생성(동적할당)
	for (int i = 0; i < index_size; i++) { //index table 채워넣기
		index_list[i].index = i;
		index_list[i].key = list[interval*i];
	}
	printf("\n<Index table>\n");
	for (int i = 0; i < index_size; i++) { //index table 출력
		printf("%3d: %3d\n", index_list[i].index, index_list[i].key);
	}
	printf("\n\nInput key to search:");
	scanf("%d", &key); //탐색하고자 하는 key값 입력받기
	printf("\n<indexed_search 결과>\n");
	res = index_search(key, SIZE, index_list, index_size, interval); //key값이 있는 index 테이블 위치 출력, list에서의 인덱스 값 res에 저장
	if (res != -1) printf("\n%d is found in position %d.\n", key, res); //찾은 위치 출력
	else printf("\nsearch failed.\n"); //없을 경우
	free(index_list);
}