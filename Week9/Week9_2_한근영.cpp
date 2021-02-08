#include <stdio.h>
#include <stdlib.h>
void head() {
	printf("====================\n");
	printf("�а�:���̹���������\n");
	printf("�й�:1971090\n");
	printf("����:�ѱٿ�\n");
	printf("====================\n");
}

typedef struct TreeNode { //Ʈ�� �� ��忡 ���� ����ü
	int key; //����� key���� ������ ����
	struct TreeNode* left, * right; //����� ����, ������ child ��带 ����ų ������ ����
}TreeNode;

TreeNode* new_node(int item) { //���ο� ��带 �����ؼ� ��ȯ�ϴ� �Լ�
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode)); //���ο� ��� ����(�����Ҵ�)
	node->key = item; //����� key���� ���ڷ� ���� item�� ����
	node->left = node->right = NULL; //child ��尡 ���� �����Ƿ� null
	return node;
}

TreeNode* insert_node(TreeNode* node, int key) { //Ʈ���� ��� �����ϴ� �Լ�
	if (node == NULL) return new_node(key);
	if (key < node->key) node->left = insert_node(node->left, key); //���� ���ڷ� ���� key���� node�� key������ ������ ���ʿ� ���� 
	else if (key > node->key) node->right = insert_node(node->right, key); //�ݴ�� �����ʿ� ����
	return node;
}

void inorder(TreeNode* root) { //������ȸ�� Ʈ�� ����ϴ� �Լ�
	if (root == NULL) return;
	else {
		inorder(root->left); //���ʺ��� ���
		printf(" [%d]", root->key); //�� ������ �θ� ��� key�� ����ϰ�
		inorder(root->right); //�� ������ ������ ��� ���
	}
}

TreeNode* search(TreeNode* node, int key) { //����Ž��Ʈ�� Ž���ϴ� �Լ�
	if (node == NULL) return NULL;
	if (node->key == key) return node; //���� ���ڷ� ���� key���̶� node->key���� ������ �� ��� ��ȯ
	else if (key < node->key) return search(node->left, key); //���� ���ڷ� ���� key���� ������ ���� subtree���� �ٽ� Ž��
	else return search(node->right, key);//�� ũ�� ������ subtree���� �ٽ� Ž��
}

TreeNode* min_value_node_r(TreeNode* node) { //right subtree���� ���� ���� �� ���� ��� ��ȯ�ϴ� �Լ�
	TreeNode* current = node;
	while (current->left != NULL) {
		current = current->left;
	}
	return current;
}

TreeNode* min_value_node_l(TreeNode* node) { //left subtree���� ���� ū �� ���� ��� ��ȯ�ϴ� �Լ�
	TreeNode* current = node;
	while (current->right != NULL) {
		current = current->right;
	}
	return current;
}

TreeNode* delete_node(TreeNode* root, int key) { //Ʈ������ �ش� ��� ã�Ƽ� �����ϰ� ���ο� root ��ȯ�ϴ� �Լ�
	if (root == NULL) return root;
	else if (root->key > key) root->left = delete_node(root->left, key); //���� subtree���� key�� ã�� �����ϵ��� ��� ȣ��
	else if (root->key < key) root->right = delete_node(root->right, key);//������ subtree���� key�� ã�� �����ϵ��� ��� ȣ��
	else { //�����ϰ��� �ϴ� key�� ���� ��带 ã����
		if (root->left == NULL) { //�ܸ� ���ų� right child �ϳ��� ���� ���
			TreeNode* tmp = root->right;
			free(root); //root ��� free���ְ�
			return tmp; //���ο� root ��ȯ
		}
		else if (root->right == NULL) { //�ܸ� ���ų� left child �ϳ��� ���� ���
			TreeNode* tmp = root->left;
			free(root); //root ��� free���ְ�
			return tmp; //���ο� root ��ȯ
		}
		//child�� �� �� �ִ� ���
		TreeNode* tmp_l = min_value_node_l(root->left); //left subtree���� ���� ū �� ���� ��� ����
		TreeNode* tmp_r = min_value_node_r(root->right);//right subtree���� ���� ���� �� ���� ��� ����
		TreeNode* tmp;
		printf("left subtree�� MAX: %d", tmp_l->key); //left subtree���� ���� ū key�� ���
		printf("\nright subtree�� MIN: %d", tmp_r->key); //right subtree���� ���� ���� key�� ���
		if (abs(key - (tmp_l->key)) >= abs(key - (tmp_r->key))) { //������ ����� key���� �� ����� ����  right subtree������ ���� ���� ���̶��
			tmp = tmp_r; //tmp�� right subtree������ ���� ���� �� ���� ��� ����
			printf("\noriginal value:%d  new value:%d\n", key, tmp->key);
			root->key = tmp->key; //���� ����� key���� ������ ��ġ�� ����
			root->right = delete_node(root->right, tmp->key); //����� ���� ���� �ִ� ��� ����
		}
		else {//������ ����� key���� �� ����� ����  left subtree������ ���� ū ���̶��
			tmp = tmp_l; //tmp�� left subtree������ ���� ū �� ���� ��� ����
			printf("\noriginal value:%d  new value:%d\n", key, tmp->key);
			root->key = tmp->key; //���� ����� key���� ������ ��ġ�� ����
			root->left = delete_node(root->left, tmp->key); //����� ���� ���� �ִ� ��� ����
		}
	}
	return root; //root ��ȯ
}
int main(void) {
	head();

	TreeNode* root = NULL; //root�� ����ų ����ü ������ ���� �ʱ�ȭ
	//�ʱ����
	root = insert_node(root, 30);
	root = insert_node(root, 20);
	root = insert_node(root, 10);
	root = insert_node(root, 45);
	root = insert_node(root, 50);
	root = insert_node(root, 60);

	printf("���� Ž�� Ʈ�� ���� ��ȸ ���\n");
	inorder(root); //Ʈ�� ���� ��ȸ�� ���
	printf("\n");
	char ch;
	while (true) { //�ݺ�
		printf("\n* operation ����: Insert(I) / Delete(D) / Exit(X): ");
		scanf(" %c", &ch);
		switch (ch) { //����ڰ� �Է��� operation ���ÿ� ����
		case 'I': //I�� �Է��ϸ�
			int i;
			printf("Insert�� ����? ");
			scanf("%d", &i); 
			insert_node(root, i); //����ڰ� �Է��� ���ڸ� ���ڷ� �Բ� ���� Ʈ���� ���ο� ��� ����
			inorder(root); //������ȸ�� Ʈ�� ���
			printf("\n");
			break;
		case 'D': //D�� �Է��ϸ�
			printf("Delete�� ����? ");
			int d;
			scanf("%d", &d);
			delete_node(root, d); //����ڰ� �Է��� ���ڸ� ���ڷ� �Բ� ���� Ʈ������ �ش�Ǵ� ���� key�� ���� ��� ����
			inorder(root);//������ȸ�� Ʈ�� ���
			printf("\n");
			break;
		case 'X': //X�� �Է��ϸ�
			printf("���α׷� ����");
			exit(0); //����
		}
	}
}