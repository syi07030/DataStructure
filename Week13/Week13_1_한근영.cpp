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

void print_list(int* list,int n) { //����Ʈ�� ����ϴ� �Լ�
	for (int i = 0; i < n; i++) {
		printf("%d ", list[i]);
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
		printf("\n*pivot: %d\n", list[p]); //pivot�� ���
		print_list(list,n); //pivot �¿�� ���ĵ� ����Ʈ ���
		printf("\nleft size: %d   right size: %d", p-left,right-p); //left, right size ���
		quick_sort(list, left, p - 1,n); //pivot �ٷ� �ձ��� ����� ȣ��� ����
		quick_sort(list, p + 1, right,n); //pivot �ٷ� �ں��� ����� ȣ��� ����
	}
}

int main(void) {
	head();
	int i, n;
	printf("Input size of list<1~10>: "); 
	scanf("%d", &n); //����Ʈ ������ ����ڷκ��� �Է¹ޱ�
	int* list = (int*)malloc(sizeof(int) * n); //�����Ҵ����� �迭 ����
	printf("Input %d numbers in the list\n",n);
	for (i = 0; i < n; i++) { //����ڷκ��� ���� �� �Է¹ޱ�
		scanf("%d", &list[i]);
	}
	printf("\n<Before Sorting>\n");
	print_list(list,n); //���ĵǱ� �� ����Ʈ ���
	quick_sort(list, 0, n - 1,n); //quick ����
	printf("\n\n<After quick sorting>\n");
	print_list(list, n);//���ĵ� �� ����Ʈ ���
	printf("\n");
	free(list);
	return 0;
}