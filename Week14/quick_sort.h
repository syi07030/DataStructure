#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t)) //x와 y에 저장된 값을 서로 바꾸는 매크로

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

void quick_sort(int* list, int left, int right) { //quick_sort 재귀적으로 하는 함수
	if (left < right) {
		int p = partition(list, left, right); //partition 호출해서 pivot 찾기
		quick_sort(list, left, p - 1); //pivot 바로 앞까지 재귀적 호출로 정렬
		quick_sort(list, p + 1, right); //pivot 바로 뒤부터 재귀적 호출로 정렬
	}
}