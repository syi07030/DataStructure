#include <stdio.h>
#include <stdlib.h>
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t)) //x�� y���� �ٲٴ� ��ũ��

void head() {
	printf("====================\n");
	printf("�а�:���̹���������\n");
	printf("�й�:1971090\n");
	printf("����:�ѱٿ�\n");
	printf("====================\n");
}

void print_list(int* list, int n) { //����Ʈ�� ����ϴ� �Լ�
	for (int i = 0; i < n; i++) {
		printf("  %d ", list[i]);
	}
}
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

void quick_sort(int* list, int left, int right, int n) { //quick_sort ��������� �ϴ� �Լ�
	if (left < right) {
		int p = partition(list, left, right); //partition ȣ���ؼ� pivot ã��
		printf("\npivot: %d", list[p]); //pivot�� ���
		quick_sort(list, left, p - 1, n); //pivot �ٷ� �ձ��� ����� ȣ��� ����
		quick_sort(list, p + 1, right, n); //pivot �ٷ� �ں��� ����� ȣ��� ����
	}
}

int median_three(int *list, int left, int right) { //ù��°, ������, �߰��� ��ġ�� �� �� median���� ���� �ε����� ã�� �Լ�
	int a = list[left]; //ù��° ��ġ�� ��
	int b = list[(left+right)/2]; //�߰��� ��ġ�� ��
	int c = list[right]; //�������� ��ġ�� ��
	if (a > b) {
		if (b > c) return ((left + right) / 2); //�߰��� ��ġ�� �� �ε��� ��ȯ
		else {
			if (c > a) return left; //ù��° ��ġ�� �� �ε��� ��ȯ
			else return right;//�������� ��ġ�� �� �ε��� ��ȯ
		}
	}
	else {
		if (a > c) return left; //ù��° ��ġ�� �� �ε��� ��ȯ
		else {
			if (c > b) return ((left + right) / 2); //�߰��� ��ġ�� �� �ε��� ��ȯ
			else return right; //�������� ��ġ�� �� �ε��� ��ȯ
		}
	}
}

int partition_medianthree(int* list, int left, int right) { //median �� ���� pivot ã�� �� pivot�� ���� �¿�� �����ϴ� �Լ�
	int pivot = list[median_three(list, left, right)]; //pivot�� ����
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
	SWAP(pivot, list[high], temp); //pivot���� �����
	return high;//pivot ��ġ ��ȯ
}

void quick_sort_medianthree(int* list, int left, int right, int n) { //median �� ���� pivot�� �������� quick sort�ϴ� �Լ�
	if (left < right) {
		int p = partition_medianthree(list, left, right); //partition_medianthree ȣ���ؼ� pivot ã��
		printf("\npivot: %d", list[p]); //pivot�� ���
		quick_sort_medianthree(list, left, p - 1, n); //pivot �ٷ� �ձ��� ����� ȣ��� ����
		quick_sort_medianthree(list, p + 1, right, n); //pivot �ٷ� �ں��� ����� ȣ��� ����
	}
}

int main(void) {
	head();
	int i, n;
	printf("Input size of list<1~50>: ");
	scanf("%d", &n); //����Ʈ ������ ����ڷκ��� �Է¹ޱ�
	int* list = (int*)malloc(sizeof(int) * n); //�����Ҵ����� �迭 ����
	int* list_medianthree = (int*)malloc(sizeof(int) * n); //�����Ҵ����� �迭 ����
	printf("Input %d numbers in the list\n", n);
	for (i = 0; i < n; i++) { //����ڷκ��� ���� �� �Է¹ޱ�
		scanf("%d", &list[i]);
		list_medianthree[i] = list[i]; //���� ���� ������ �Ȱ��� �� ������ ����
	}
	printf("\n<<���� ���� ����>>\n");
	print_list(list, n); //���ĵǱ� �� ����Ʈ ���
	printf("\n\n<Quick Soritng>");
	quick_sort(list, 0, n - 1, n); //quick ����
	printf("\n<Result>\n");
	print_list(list, n);//���ĵ� �� ����Ʈ ���
	printf("\n\n<Quick Sorting<Median of three>>");
	quick_sort_medianthree(list_medianthree, 0, n - 1, n); //median pivot�������� ����
	printf("\n<Result>\n");
	print_list(list, n); //���ĵ� �� ����Ʈ ���
	printf("\n");
	free(list);
	free(list_medianthree);
	return 0;
}