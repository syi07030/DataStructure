#include <stdio.h>
#include <stdlib.h>
#define SIZE 10 //�Է¹޾Ƽ� ������ key���� ���� 10���� ����
#define TABLE_SIZE 11 //hash table ũ�� 11�� ����

void head() {
	printf("====================\n");
	printf("�а�:���̹���������\n");
	printf("�й�:1971090\n");
	printf("����:�ѱٿ�\n");
	printf("====================\n");
}

typedef struct { //key���� ���� element ����ü
	int key;
}element;

struct list { //�� ��忡 ���� ������ ��Ÿ���� ����ü
	element item;
	struct list* link;
};

struct list* hash_table[TABLE_SIZE]; //hash table ����

int hash_function(int key) { //modulo ���� ����� ��ȯ�ϴ� hash �Լ�
	return key % TABLE_SIZE;
}

void hash_chain_add(element item, struct list* ht[]) { //���ο� key�� hash table�� �߰��ϴ� �Լ�
	int hash_value = hash_function(item.key); //key�� ���� hash �� ����
	struct list* ptr;
	struct list* node_before = NULL, * node = ht[hash_value];
	for (; node; node_before = node, node = node->link) { //�ش� ��ġ�� ��� �˻�
		if (node->item.key == item.key) { //���� ���� ���� �ִٸ� ������ ���� ���
			fprintf(stderr, "%d is already stored\n", item.key);
			return;
		}
	}
	ptr = (struct list*)malloc(sizeof(struct list)); //�ش� key���� ����Ǿ� ���� �ʴٸ� �����Ҵ��� ���� ��� ����
	ptr->item = item; //���ο� ��忡 key�� ����
	ptr->link = NULL; //���ο� ��� ��ũ ����
	if (node_before) node_before->link = ptr; //���� �տ� �Ǵٸ� ��尡 �ִٸ� �� ��� ���� ��ġ�� �߰�
	else ht[hash_value] = ptr; //�ش� ��ġ�� �ƹ��� ��嵵 ���ٸ� ù ���� ����
}

void hash_chain_delete(element item, struct list* ht[]) { //�ش� key���� hash table���� �����ϴ� �Լ�
	struct list* rm; //������ ��带 ������ ������
	struct list* pre=NULL; //�����ϱ� ���� ��带 ����ų ������
	int hash_value = hash_function(item.key); //key�� ���� hash �� ����
	for (struct list*node = ht[hash_value]; node; node = node->link) { //�ش� ��ġ�� ��� �˻�
		if (node->item.key == item.key) { //���� ���� ���� �ִ� ��带 ã����
			rm = node; //rm�� �ش� ��� �ּ� ����
			if (pre==NULL) { //���� �� ��尡 ù �����
				ht[hash_value]= node->link; //node�� ���� ��带 ù ��ġ��
			}
			else { //���� �ش� ��尡 ù ��尡 �ƴ϶��
				pre->link = node->link; //node ���� ��带 node �� ��� �ٷ� ��������
			}
			free(rm); //������ ��� memory ��ȯ
			return;
		}
		pre = node; //pre node �ּ� ����
	}
	fprintf(stderr, "%d is not in the table\n", item.key); //���� �ش� key�� ������ ���
}

void hash_chain_search(element item, struct list* ht[]) { //key�� hash table ��� �ε����� ��ġ�ϴ��� ã�� �Լ�
	struct list* node;
	int hash_value = hash_function(item.key); //key�� ���� hash �� ����
	for (node = ht[hash_value]; node; node = node->link) { //�ش� ��ġ�� ��� �˻�
		if (node->item.key == item.key) { //���� ���� key���� ���� ��带 ã����
			fprintf(stderr, "%d is found at index %d\n", item.key, hash_value); //��� �ε����� �ִ��� ���
			return;
		}
	}
	fprintf(stderr, "%d is not in the table\n", item.key); //���� key�� ���� ��� ������ ���ٰ� ���
}

void hash_chain_print(struct list* ht[]) { //hash table ����ϴ� �Լ�
	struct list* node; 
	int i;
	printf("\n==============================\n");
	for (i = 0; i < TABLE_SIZE; i++) { //��ü table size��ŭ �ݺ��ؼ� ���
		printf("[%d]", i);
		for (node = ht[i]; node; node = node->link) { //�ش� ��ġ�� ��� link�� null�� ����ų ������ �ݺ��ؼ� ���
			printf(" - %3d", node->item.key);
		}
		printf("\n");
	}
	printf("==============================\n");
}

int main(void) {
	head();

	int data[SIZE]; //����ڰ� �Է��� key ������ ������ ����Ʈ
	printf("Input %d keys to add\n", SIZE);
	for (int i = 0; i < SIZE; i++) { //����ڷκ��� key ���� 10�� �Է¹ޱ�
		scanf("%d", &data[i]);
	}
	element e;
	for (int i = 0; i < SIZE; i++) { //�Է¹��� key������ hash table�� add
		e.key = data[i];
		hash_chain_add(e, hash_table);
	}
	hash_chain_print(hash_table); //hash table ���

	while (true) { //������ �ݺ�
		int ch;// ����ڰ� ������ operation ��ȣ
		printf("\nChoose operation (1.insert  2.delete  3.search  4.print  5.exit):");
		scanf("%d", &ch); //� operation���� �Է¹ޱ�
		switch (ch) { //ch���� ����
			element n;
		case 1: //1�̶��
			printf("input data to add:");
			scanf("%d", &(n.key)); //hash table�� ������ key���� �Է¹ް�
			hash_chain_add(n, hash_table); //�ش� element�� hash table�� ����
			break;
		case 2: //2���
			printf("input data to be delete:");
			scanf("%d", &(n.key)); //hash table���� ������ key���� �Է¹ް�
			hash_chain_delete(n, hash_table); //�ش� element�� hash table���� ����
			break;
		case 3: //3�̶��
			printf("input data to search:");
			scanf("%d", &(n.key)); //hash table���� ��ġ�� ã�� key���� �Է¹ް�
			hash_chain_search(n, hash_table); //�ش� ��ġ ã�Ƽ� ���
			break;
		case 4: //4���
			hash_chain_print(hash_table); //hash table ���
			break;
		case 5: //5���
			printf("\nProgram finished");
			exit(0); //���α׷� ����
		default: //�� ���� ���ڶ�� ������ ����ϰ� �ٽ� �ݺ�
			printf("Wrong input");
		}
	}
}