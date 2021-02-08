#include <stdio.h>
#include <stdlib.h>
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t)) //x와 y값을 바꾸는 매크로

void head() {
	printf("====================\n");
	printf("학과:사이버보안전공\n");
	printf("학번:1971090\n");
	printf("성명:한근영\n");
	printf("====================\n");
}

void print_list(int* list, int n) { //리스트를 출력하는 함수
	for (int i = 0; i < n; i++) {
		printf("  %d ", list[i]);
	}
}
int partition(int* list, int left, int right) { //pivot 찾고 그 pivot에 대해 좌우로 정렬하는 함수
	int pivot = list[left]; //pivot값 저장
	int temp, low, high;
	low = left; //left부터 시작(하나씩 증가)
	high = right + 1; //right+1부터 시작(하나씩 감소)
	do {
		do {
			low++;
		} while (list[low] < pivot); //left 다음 요소부터 증가시키면서 pivot 값보다 큰 값 나올 때까지 반복
		do {
			high--;
		} while (list[high] > pivot); //right부터 줄여가면서 pivot 값보다 작은 값 나올 때까지 반복
		if (low < high) SWAP(list[low], list[high], temp); //만약 high가 low보다 크면 list[low]값과 list[high]값 switch
	} while (low < high); //low가 high보다 작으면 반복
	SWAP(list[left], list[high], temp); //pivot값을 가운데로
	return high;//pivot 위치 반환
}

void quick_sort(int* list, int left, int right, int n) { //quick_sort 재귀적으로 하는 함수
	if (left < right) {
		int p = partition(list, left, right); //partition 호출해서 pivot 찾기
		printf("\npivot: %d", list[p]); //pivot값 출력
		quick_sort(list, left, p - 1, n); //pivot 바로 앞까지 재귀적 호출로 정렬
		quick_sort(list, p + 1, right, n); //pivot 바로 뒤부터 재귀적 호출로 정렬
	}
}

int median_three(int *list, int left, int right) { //첫번째, 마지막, 중간에 위치한 수 중 median값을 갖는 인덱스를 찾는 함수
	int a = list[left]; //첫번째 위치한 수
	int b = list[(left+right)/2]; //중간에 위치한 수
	int c = list[right]; //마지막에 위치한 수
	if (a > b) {
		if (b > c) return ((left + right) / 2); //중간에 위치한 수 인덱스 반환
		else {
			if (c > a) return left; //첫번째 위치한 수 인덱스 반환
			else return right;//마지막에 위치한 수 인덱스 반환
		}
	}
	else {
		if (a > c) return left; //첫번째 위치한 수 인덱스 반환
		else {
			if (c > b) return ((left + right) / 2); //중간에 위치한 수 인덱스 반환
			else return right; //마지막에 위치한 수 인덱스 반환
		}
	}
}

int partition_medianthree(int* list, int left, int right) { //median 값 갖는 pivot 찾고 그 pivot에 대해 좌우로 정렬하는 함수
	int pivot = list[median_three(list, left, right)]; //pivot값 저장
	int temp, low, high;
	low = left; //left부터 시작(하나씩 증가)
	high = right + 1; //right+1부터 시작(하나씩 감소)
	do {
		do {
			low++;
		} while (list[low] < pivot); //left 다음 요소부터 증가시키면서 pivot 값보다 큰 값 나올 때까지 반복
		do {
			high--;
		} while (list[high] > pivot); //right부터 줄여가면서 pivot 값보다 작은 값 나올 때까지 반복
		if (low < high) SWAP(list[low], list[high], temp); //만약 high가 low보다 크면 list[low]값과 list[high]값 switch
	} while (low < high); //low가 high보다 작으면 반복
	SWAP(pivot, list[high], temp); //pivot값을 가운데로
	return high;//pivot 위치 반환
}

void quick_sort_medianthree(int* list, int left, int right, int n) { //median 값 갖는 pivot을 기준으로 quick sort하는 함수
	if (left < right) {
		int p = partition_medianthree(list, left, right); //partition_medianthree 호출해서 pivot 찾기
		printf("\npivot: %d", list[p]); //pivot값 출력
		quick_sort_medianthree(list, left, p - 1, n); //pivot 바로 앞까지 재귀적 호출로 정렬
		quick_sort_medianthree(list, p + 1, right, n); //pivot 바로 뒤부터 재귀적 호출로 정렬
	}
}

int main(void) {
	head();
	int i, n;
	printf("Input size of list<1~50>: ");
	scanf("%d", &n); //리스트 사이즈 사용자로부터 입력받기
	int* list = (int*)malloc(sizeof(int) * n); //동적할당으로 배열 생성
	int* list_medianthree = (int*)malloc(sizeof(int) * n); //동적할당으로 배열 생성
	printf("Input %d numbers in the list\n", n);
	for (i = 0; i < n; i++) { //사용자로부터 원소 값 입력받기
		scanf("%d", &list[i]);
		list_medianthree[i] = list[i]; //정렬 이전 상태의 똑같은 값 갖도록 저장
	}
	printf("\n<<정렬 이전 상태>>\n");
	print_list(list, n); //정렬되기 전 리스트 출력
	printf("\n\n<Quick Soritng>");
	quick_sort(list, 0, n - 1, n); //quick 정렬
	printf("\n<Result>\n");
	print_list(list, n);//정렬된 후 리스트 출력
	printf("\n\n<Quick Sorting<Median of three>>");
	quick_sort_medianthree(list_medianthree, 0, n - 1, n); //median pivot기준으로 정렬
	printf("\n<Result>\n");
	print_list(list, n); //정렬된 후 리스트 출력
	printf("\n");
	free(list);
	free(list_medianthree);
	return 0;
}