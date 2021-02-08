#include <stdio.h>
#include <stdlib.h>
#include <string.h> //strcmp,strcpy ���
#define SIZE 20 //�ܾ� ũ�� ���Ƿ� ����

void head() {
	printf("====================\n");
	printf("�а�:���̹���������\n");
	printf("�й�:1971090\n");
	printf("����:�ѱٿ�\n");
	printf("====================\n");
}

typedef struct TreeNode { //�� ��忡 ���� ����ü
	char key[SIZE]; //���ϸ� ������ key ���ڹ迭
	struct TreeNode* left, * right; //�ڽĳ�� ������ ��ũ
}TreeNode;

TreeNode* new_node(char item[]) { //���ο� ��� �����ϴ� �Լ�
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode)); //�����Ҵ�
	strcpy(node->key,item); //���ڷ� ���� item�� key������ ����
	node->left = node->right = NULL; //�ڽ� ���� ��� null�� �ʱ�ȭ
	return node;
}

TreeNode* insert(TreeNode* node, char key[]) { //���ο� �ܾ� insert�ϴ� �Լ�
	if (node == NULL) return new_node(key); //�ܸ����� ���� ��� �����ؼ� ����
	if (strcmp(key, node->key) == -1) node->left = insert(node->left, key); //���� key���� �ƽ�Ű�ڵ� �� ���� ����� key������ ������ ���� subtree�� �ٽ� ��������� insert
	else if (strcmp(key, node->key) == 1) node->right = insert(node->right, key); //key���� �ƽ�Ű�ڵ� �� ���� ����� key������ Ŭ ��� ������ subtree�� �ٽ� ��������� insert
	return node;
}

TreeNode* min_value_node(TreeNode* node) { //Ʈ������ ��� �����ϰ� Ʈ�� �������� �� �ʿ��� ��� ã�� �Լ�
	TreeNode* current = node;
	while (current->left != NULL) { //���ʿ� ��尡 �� �̻� ���� ������ ���� �ڽ� ���� �������� �� �ݺ�
		current = current->left;
	}
	return current; //���� ���� key�� ���� ���� ��� ��ȯ
}

TreeNode* del(TreeNode* root, char key[]) { //Ư�� �ܾ� �����ϴ� �Լ�
	if (root == NULL) return root; 
	else if (strcmp(root->key, key) == 1) root->left = del(root->left, key); //���� subtree���� key�� �����ϵ��� ���ȣ��
	else if (strcmp(root->key, key) == -1) root->right = del(root->right, key); //������ subtree���� key�� �����ϵ��� ���ȣ��
	else { //�����ϰ��� �ϴ� key���� ã���� ���
		if (root->left == NULL) { //���� �ڽ��� ���� ���
			TreeNode* temp = root->right; //������ �ڽ� �ӽ÷� temp ����
			free(root); //�ش� ��� ����
			return temp; //�ش� ��� ��ġ�� ������ �ڽ� ��尡
		}
		else if (root->right == NULL) { //������ �ڽ� ��尡 ���� ���
			TreeNode* temp = root->left; //���� �ڽ� ��� �ӽ÷� temp ����
			free(root);//�ش� ��� ����
			return temp; //�ش� ��� ��ġ�� ���� �ڽ� ��尡
		}
		TreeNode* temp = min_value_node(root->right); //child�� �� �� ���� ��� ���� ����� key�� ���� ��� ã��
		strcpy(root->key, temp->key); //���� ����� key���� ������ ��ġ�� ����
		root->right = del(root->right, temp->key); //����� ���� ���� �ִ� ��� ����
	}
	return root; //���ο� root ��ȯ
}

TreeNode* search(TreeNode* node, char key[]) { //Ư�� �ܾ� �˻��ϴ� �Լ�
	if (node == NULL) return NULL; 
	if (strcmp(node->key, key) == 0) return node; //ã���� �� key�� ���� node ��ȯ 
	else if (strcmp(key, node->key) == -1) return search(node->left, key); //���� node�� key������ ������ left subtree �˻�
	else return search(node->right, key); //���� node������ ũ�� right subtree �˻�
}

void inorder_print(TreeNode* root) { //inorder ���� ���·� ����ϴ� �Լ�
	if (root == NULL) return;
	else {
		inorder_print(root->left); //���� ������ ���
		printf("%s\n", root->key); //root key�� ���
		inorder_print(root->right); //������ ��� ���
	}
}

TreeNode* init(TreeNode* root) { //�ʱ�ȭ �Լ�
	char word[6][SIZE] = {"apple","banana","blueberry","kiwi","orange","pear"};
	for (int i = 0; i < 6; i++) {
		root = insert(root, word[i]); //�ʱⰪ�� Ʈ���� ����
	}
	return root;
}

int main(void) {
	head();

	TreeNode* root = NULL; //root ����
	root=init(root); //Ʈ�� �ʱ�ȭ
	while (true) { //�ݺ�
		int op;
		printf("\n* Choose operation<1.insert 2.delete 3.search 4.print 5.exit>:");
		scanf("%d", &op); //����ڷκ��� ���� operation���� �Է¹ޱ�
		switch (op) { //op���� ����
		case 1: //1�̸� ���ο� �ܾ� �Է�
			char w[SIZE];
			printf("Enter a word:");
			scanf("%s", w);
			root = insert(root, w); //�Է¹��� �ܾ Ʈ���� ����
			break;
		case 2: //2�� Ư���ܾ� ����
			char d[SIZE];
			printf("Enter a word to delete:");
			scanf("%s", d);
			root = del(root, d); //�Է¹��� �ܾ ã�Ƽ� Ʈ������ ����
			break;
		case 3: //3�̸� Ư���ܾ� �˻�
			char s[SIZE];
			printf("Enter a word:");
			scanf("%s", s);
			if (search(root,s) != NULL) printf("%s is found\n", s); //�Է¹��� �ܾ �ִ��� ���� ���
			else printf("%s is not found\n", s);
			break;
		case 4: //4�� ��� �ܾ� inorder���·� ���
			inorder_print(root);
			break;
		case 5: //5�� ���α׷� ����
			printf("Program finished\n");
			exit(0);
		default: //�� �ܴ� �Ʒ� ����ϰ� �ݺ�
			printf("Wrong input\n");
			break;
		}
	}
}