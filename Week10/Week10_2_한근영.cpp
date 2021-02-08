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

typedef struct { //element�� ���� ����ü
	int key;
}element;
typedef struct { //HeapType�� ���� ����ü
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

void init(HeapType* h) { //heap �ʱ�ȭ ��Ű�� �Լ�
	h->heap_size = 0;
}

int find_index(HeapType* h, element n) { //element ��� �ε��� ��ȯ�ϴ� �Լ�
	for (int i = 1; i <= h->heap_size; i++) {
		if (h->heap[i].key == n.key) { //���� �ش� ����� key���� ���ڷ� ���� element�� key���� ��ġ�ϸ�
			return i; //�ش� �ε��� ��ȯ
		}
	}
}

bool same_value(HeapType* h, int value) { //�ش� ���� heap�� �����ϴ��� �Ǵ��ϴ� �Լ�
	for (int i = 1; i <= h->heap_size; i++) {
		if (h->heap[i].key == value) { //���� �ش� ����� key���� ���ڷ� ���� value���� ���ٸ�
			return true; //true ��ȯ
		}
	}
	return false; //������ false ��ȯ
}

void insert_heap(HeapType* h, element item) { //���ο� ��� �߰��ϴ� �Լ�
	if (same_value(h,item.key) == true) { //���� �Ȱ��� key���� ���� ��尡 �̹� �����ϸ� ���� ���
		printf("same value exists\n");
	}
	else { //�Ȱ��� key���� ���� ��尡 �������� �ʴ´ٸ�
		int i;
		i = ++(h->heap_size); //��� �߰� �� ������ ���ܳ�� �ε��� ����
		while ((i != 1) && (item.key > h->heap[i / 2].key)) { //Ʈ���� �Ž��� �ö󰡸鼭 �θ� ��� key���� ��
			h->heap[i] = h->heap[i / 2]; //�߰��� ��� key������ ���� ��� �θ��带 ����
			i /= 2; //�� �θ�� ��ġ �̵�
		}
		h->heap[i] = item; //���� ������ ��ġ�� ���ο� ��� ����
	}
}

element delete_item(HeapType* h, element e) { //element ��� �����ϰ� heap �籸���ϴ� �Լ�
	int parent = find_index(h,e), child = parent*2; //���ڷ� ���� e�� key���� ���� ����� ��ġ�� ã�Ƽ� parent��, child�� �� �ڽ�
	element item = h->heap[1];
	element temp = h->heap[h->heap_size--];
	while (child <= h->heap_size) { //�ִ� ���ܱ��� Ʈ���� �������鼭 �ڽĳ�� key���� temp key�� ��
		if ((child < h->heap_size) && (h->heap[child].key < h->heap[child + 1].key)) child++; //�ڽ� ��尡 2���� ��� �� ū�� ã��
		if (temp.key >= h->heap[child].key) break; //�ڽĳ�庸�� �űԳ�� key���� �� ũ�� �ݺ� ����, ��ġ Ȯ��
		h->heap[parent] = h->heap[child]; //�ڽĳ�� key������ �� ũ�� �θ� ��忡 �ڽ� ��� ����
		parent = child; //�θ� �ε����� �ڽ� �ε����� ����
		child *= 2; //�� �Ʒ� �ڽ� ���� ��ġ �̵�
	}
	h->heap[parent] = temp; //Ȯ����ġ�� �űԳ�� ����
	return item;
}

void print_heap(HeapType* max_h) { //heap ����ϴ� �Լ�
	for (int i = 1; i <= max_h->heap_size; i++) {
		printf("%d ", max_h->heap[i]);
	}
	printf("\n");
}

int main(void) {
	head();

	HeapType* max_heap = (HeapType*)malloc(sizeof(HeapType)); //heap ����(�����Ҵ�)
	init(max_heap); //heap �ʱ�ȭ
	char ch;
	while (true) { //�ݺ�
		char ch;
		printf("Input Operation I(Insert)  D(Delete)  P(Print)  X(Exit): "); //� operation���� �Է¹ޱ�
		scanf(" %c", &ch);
		switch (ch) { //�Է¹��� ���� ����
		case 'I':
			element v;
			printf("Input value to insert: "); //�߰��� key�� �Է¹ޱ�
			scanf("%d", &v);
			insert_heap(max_heap, v); //heap�� ���ο� ��� �߰�
			break;
		case 'D':
			element d;
			printf("Input value to delete: "); //������ key�� �Է¹ޱ�
			scanf("%d", &d);
			delete_item(max_heap,d); //�ش� key�� ���� ��� ����
			break;
		case 'P':
			print_heap(max_heap); //heap ����Ʈ
			break;
		case 'X':
			exit(0); //���α׷� ����
		default:
			printf("Wrong Input\n"); //������ ����ϰ� �ٽ� �ݺ�
			break;
		}
	}
}