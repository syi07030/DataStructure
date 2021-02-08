#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200
void head() {
	printf("====================\n");
	printf("�а�:���̹���������\n");
	printf("�й�:1971090\n");
	printf("����:�ѱٿ�\n");
	printf("====================\n");
}

typedef struct { //element ����ü
	int key;
}element;
typedef struct { //HeapType ����ü, heap ��� ��ġ�� ����� ���� ����
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

void init(HeapType* h) { //Heap �ʱ�ȭ ��Ű�� �Լ�
	h->heap_size = 0;
}

void insert_max_heap(HeapType* h, element item) { //max Heap�� ���ο� ��� �����ϴ� �Լ�
	int i;
	i = ++(h->heap_size); //��� �߰� �� ������ ���� ��� �ε����� i�� ����
	while ((i != 1) && (item.key > h->heap[i / 2].key)) { //Ʈ���� �Ž��� �ö󰡸鼭 �θ� ��� key�� ��
		h->heap[i] = h->heap[i / 2]; //�߰��� key���� ���� ��� �θ��带 ������
		i /= 2; //�ε����� �� �θ�� ��ġ �̵���Ŵ
	}
	h->heap[i] = item; //���� ������ ��ġ�� ���ο� ��� ����
}

element delete_max_heap(HeapType* h) { //max Heap���� ��Ʈ ��� �����ϴ� �Լ�
	int parent = 1, child = 2; //�� ��° ������ ��Ʈ ���� �񱳽���
	element item = h->heap[1]; //�����Ǵ� ���
	element temp = h->heap[h->heap_size--]; //���ܳ�带 temp�� ����
	while (child <= h->heap_size) { //���� ���� ������ �������鼭 �ڽĳ�� key���� temp key�� ��
		if ((child < h->heap_size) && (h->heap[child].key < h->heap[child + 1].key)) child++; //���� �ڽ� ��尡 2���� ��� �� �� ū ���� ã�� subtree ����
		if (temp.key >= h->heap[child].key) break; //���� �ڽĳ�庸�� �űԳ�� key�� ũ�� ��ġ Ȯ���Ǿ� �ݺ� ��������
		h->heap[parent] = h->heap[child]; //�ڽĳ�� key�� �� ũ�� �θ� ��忡 �ڽ� ��� ����
		parent = child; //�θ� �ε����� �ڽ� �ε�����
		child *= 2; //�ڽ� ���� �� �Ʒ� �ڽ� ���� ��ġ �̵�
	}
	h->heap[parent] = temp; //Ȯ����ġ�� �űԳ�� ����
	return item; //������ ��� ��ȯ
}

void insert_min_heap(HeapType* h, element item) { //min Heap���� ���ο� ��� �����ϴ� �Լ�
	int i;
	i=++(h->heap_size); //��� �߰� �� ������ ���ܳ�� �ε��� ����
	while ((i != 1) && (item.key < h->heap[i / 2].key)) { //Ʈ���� �Ž��� �ö󰡸鼭 �θ� ��� key���� ��
		h->heap[i] = h->heap[i / 2]; //�߰��� ��� key������ ū ��� �θ� ��带 ������
		i /= 2; //�ε��� ���ο� ��ġ�� �θ�� �̵�
	}
	h->heap[i] = item; //���� ������ ��ġ�� ���ο� ��� ����
}

element delete_min_heap(HeapType* h) { //min Heap���� ��Ʈ ��� �����ϴ� �Լ�
	int parent = 1, child = 2; //�ι�° ������ ��Ʈ ���� �� ����
	element item = h->heap[1]; //�����Ǵ� ��� ����
	element temp = h->heap[(h->heap_size)--]; //���ܳ�带 temp�� ����
	while (child <= h->heap_size) { //�ִ� ���� ������ Ʈ�� �������鼭 �ڽĳ�� key���� temp key�� ��
		if ((child < h->heap_size) && (h->heap[child].key > h->heap[child + 1].key)) child++; //�ڽ� ��尡 �� ���� �� �� ���� �� ã��
		if (temp.key < h->heap[child].key) break; //�ڽĺ��� �űԳ�� key���� ������ ��ġ Ȯ��, �ݺ��� ������
		h->heap[parent] = h->heap[child]; //�ڽĳ�� key�� �� ������Ť� �θ� ��忡 �ڽ� ��� ����
		parent = child; //�θ� �ε����� �ڽ� �ε����� ����
		child *= 2; //�� �Ʒ� �ڽ� ��� ��ġ�� �̵�
	}
	h->heap[parent] = temp; //Ȯ����ġ�� �űԳ�� ����
	return item; //������ ��� ��ȯ
}

void print_heap(HeapType* max_h,HeapType*min_h) { //heap ����ϴ� �Լ�
	printf("<Max Heap>\n");
	for (int i = 1; i <= max_h->heap_size; i++) { //max heap ���
		printf("%d ", max_h->heap[i]);
	}
	printf("\n<Min Heap>\n");
	for (int i = 1; i <= min_h->heap_size; i++) { //min heap ���
		printf("%d ", min_h->heap[i]);
	}
	printf("\n");
}

int main(void) {
	head();

	HeapType* min_heap = (HeapType*)malloc(sizeof(HeapType)); //min heap ����(�����Ҵ�)
	HeapType* max_heap = (HeapType*)malloc(sizeof(HeapType));//max heap ����(�����Ҵ�)
	init(min_heap); //min heap �ʱ�ȭ
	init(max_heap);//max heap �ʱ�ȭ
	char ch;
	while (true) {//�ݺ�
		char ch;
		printf("Input Operation I(Insert)  D(Delete)  X(Exit): ");
		scanf(" %c", &ch); //� operation�� ���� �Է¹ޱ�
		switch (ch) { //�Է¹��� ���� ����
		case 'I':
			element v;
			printf("Input value to insert: "); //������ ���� �Է¹ޱ�
			scanf("%d", &v);
			insert_max_heap(max_heap, v); //���ο� ��� max heap�� �߰�
			insert_min_heap(min_heap, v); //���ο� ��� min heap�� �߰�
			print_heap(max_heap, min_heap); //���� ����Ʈ
			break;
		case 'D':
			delete_max_heap(max_heap); //max heap���� ��Ʈ ��� ����
			delete_min_heap(min_heap); //min heap���� ��Ʈ ��� ����
			print_heap(max_heap, min_heap); //���� ����Ʈ
			break;
		case 'X':
			exit(0); //���α׷� ����
		default:
			printf("Wrong Input\n"); //������ ����Ʈ�ϰ� �ٽ� �ݺ�
			break;
		}
	}
}