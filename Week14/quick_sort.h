#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t)) //x�� y�� ����� ���� ���� �ٲٴ� ��ũ��

int partition(int* list, int left, int right) { //pivot ã�� �� pivot�� ���� �¿�� �����ϴ� �Լ�
	int pivot = list[left]; //pivot�� ����
	int temp, low, high;
	low = left; //left���� ����(�ϳ��� ����)
	high = right + 1; //right+1���� ����(�ϳ��� ����)
	do {
		do {
			low++;
		} while (list[low] < pivot); //left ���� ��Һ��� ������Ű�鼭 pivot ������ ū �� ���� ������ �ݺ�
		do {
			high--;
		} while (list[high] > pivot); //right���� �ٿ����鼭 pivot ������ ���� �� ���� ������ �ݺ�
		if (low < high) SWAP(list[low], list[high], temp); //���� high�� low���� ũ�� list[low]���� list[high]�� switch
	} while (low < high); //low�� high���� ������ �ݺ�
	SWAP(list[left], list[high], temp); //pivot���� �����
	return high;//pivot ��ġ ��ȯ
}

void quick_sort(int* list, int left, int right) { //quick_sort ��������� �ϴ� �Լ�
	if (left < right) {
		int p = partition(list, left, right); //partition ȣ���ؼ� pivot ã��
		quick_sort(list, left, p - 1); //pivot �ٷ� �ձ��� ����� ȣ��� ����
		quick_sort(list, p + 1, right); //pivot �ٷ� �ں��� ����� ȣ��� ����
	}
}