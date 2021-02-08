#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "quick_sort.h"
#define SIZE 100 //����Ʈ ������ 100���� ����

void head() {
	printf("====================\n");
	printf("�а�:���̹���������\n");
	printf("�й�:1971090\n");
	printf("����:�ѱٿ�\n");
	printf("====================\n");
}

typedef struct { //�ε��� ���̺� ����ü
	int key; //key�� ����
	int index; //index�� ����
}itable;

int list[SIZE]; //list ���������� ����

int seq_search(int key, int low, int high, int interval) { //����Ž��
	int location=-1;
	for (int i = low*interval; i <= high*interval; i++) { //���ڷ� ���� low*interval���� high*interval���� �ݺ�
		if (list[i] == key) //���� list �ش� �ε����� ����� ���� key�� ���ٸ�
			location= i; //location�� �ش� �ε��� ����
	}
	return location; //location ��ȯ
}

int index_search(int key, int n, itable *index_list, int INDEX_SIZE, int interval) { //���μ���Ž��
	int i, low, high;
	if (key<list[0] || key>list[n - 1]) return -1; //���� ���� ��� ����
	for (i = 0; i < INDEX_SIZE; i++) {
		if (index_list[i].key <= key && index_list[i + 1].key > key) break; //�ش�Ű�� ���Ե� ��ġ ã��
	}
	if (i == INDEX_SIZE) { //������ index������ key�� ���Ե� ���
		low = index_list[i-1].index;
		high = n;
	}
	else { //Ư�� index i~i+1 ���̿� key�� ���Ե� ���
		low = index_list[i].index;
		high = index_list[i + 1].index;
	}
	printf("index location: %d", low); //key�� ��ġ�� ������ �����Ǵ� index location ���
	return seq_search(key, low, high,interval); //����Ž������ ��� ��ġ�ϴ��� �ε��� �� ��ȯ
}
int main(void) {
	head();
	srand(time(NULL)); //seed�� �޶������� ����
	int key=0, res=0, interval=0;
	for (int i = 0; i < SIZE; i++) { //0~999 ������ ���� 100�� ����
		list[i] = rand() % 1000;
	}
	for (int i = 0; i < SIZE; i++) { //����Ʈ ���
		if (i % 10 == 0) putchar('\n');
		printf("%4d", list[i]);
	}
	printf("\n\n<���İ��>\n");
	quick_sort(list, 0, SIZE); //quick sort�� ����
	for (int i = 0; i < SIZE; i++) { //������ ����Ʈ ���
		if (i % 10 == 0) putchar('\n');
		printf("%4d", list[i]);
	}
	printf("\n\nInput index interval(1~100):");
	scanf("%d", &interval); //����ڷκ��� index interval �Է¹ޱ�
	int index_size;
	//index_size �����ϱ�
	if (100 % interval == 0) index_size = 100 / interval;
	else index_size = (int)(100 / interval) + 1;
	itable* index_list=(itable*)malloc(sizeof(itable)*index_size); //index_list ������ ����(�����Ҵ�)
	for (int i = 0; i < index_size; i++) { //index table ä���ֱ�
		index_list[i].index = i;
		index_list[i].key = list[interval*i];
	}
	printf("\n<Index table>\n");
	for (int i = 0; i < index_size; i++) { //index table ���
		printf("%3d: %3d\n", index_list[i].index, index_list[i].key);
	}
	printf("\n\nInput key to search:");
	scanf("%d", &key); //Ž���ϰ��� �ϴ� key�� �Է¹ޱ�
	printf("\n<indexed_search ���>\n");
	res = index_search(key, SIZE, index_list, index_size, interval); //key���� �ִ� index ���̺� ��ġ ���, list������ �ε��� �� res�� ����
	if (res != -1) printf("\n%d is found in position %d.\n", key, res); //ã�� ��ġ ���
	else printf("\nsearch failed.\n"); //���� ���
	free(index_list);
}