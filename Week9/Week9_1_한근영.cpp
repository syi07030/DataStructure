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
	int key; //����� �����͸� ������ ����
	struct TreeNode* left, * right; //�� ����� ������,���� �ڽ� ��带 ����ų ������ ����
}TreeNode;

int get_node_count(TreeNode* exp) { //Ʈ���� ��� ������ ��ȯ�ϴ� �Լ�
	if (exp == NULL) return 0;
	else return get_node_count(exp->left) + get_node_count(exp->right) + 1; //���� subtree, ������ subtree�� ��� ������ �ڱ� �ڽ��� ���� ��ȯ(���)
}

int get_leaf_count(TreeNode* exp) { //�ܸ� ��� ������ ��ȯ�ϴ� �Լ�
	if (exp == NULL) return 0;
	else {
		if (exp->left == NULL && exp->right == NULL) return 1; //���� exp�� �ܸ�����̸� 1 ��ȯ
		else return get_leaf_count(exp->left) + get_leaf_count(exp->right); //���
	}
}

int get_height(TreeNode* exp) { //Ʈ���� height�� ��ȯ�ϴ� �Լ�
	if (exp == NULL) return 0;
	else {
		int l_height = get_height(exp->left); //���� subtree�� height
		int r_height = get_height(exp->right); //������ subtree�� height
		if (l_height >= r_height) return l_height + 1; //���� ���� subtree�� height�� �� ũ�� l_height�� root ��带 ������ ���� ��ȯ
		else return r_height + 1; //�ƴ϶�� r_height�� root ��带 ������ ���� ��ȯ
	}
}

void inorder(TreeNode* exp) { //���� ��ȸ�� ����ϴ� �Լ�
	if (exp) {
		inorder(exp->left); //���� ������ ���
		printf(" [%d]", exp->key); //�� ������ �θ� ��� ���
		inorder(exp->right); //�� ������ ������ ��� ���
	}
}

void balanced(TreeNode* exp) { //����Ʈ���� subtree ���� ���̰� �ִ� 1������ ��� ã�� �Լ�
	int l_height = get_height(exp->left); //���� subtree�� height
	int r_height = get_height(exp->right); //������ subtree�� height
	if ((l_height - r_height >= -1)&&(l_height - r_height <= 1)) printf("Yes"); //���� subtree�� ���� ���� �ִ� 1������ ���� balanced tree
	else printf("No");//�ƴϸ� no ���
}

TreeNode* stack[100]; //Ʈ�� ��带 ������ ����
int top = -1; //������ top �ʱ�ȭ
void push(TreeNode* p) { //���ÿ� push�ϴ� �Լ�
	if (top < 99) stack[++top] = p;
}
TreeNode* pop(void) { //���ÿ��� pop�ϴ� �Լ�
	TreeNode* p = NULL;
	if (top != -1) p = stack[top--];
	return p;
}
void greater_than(TreeNode*exp,int num) { //����ڰ� �Է��� �� num���� ū key���鸸 ����ϴ� �Լ�
	while (true) {//�ݺ�
		for (; exp; exp = exp->left) push(exp); //left�� ��尡 ������ stack�� push
		exp = pop(); //left�� ��尡 �� ������ pop
		if (exp == NULL) break; //��� ��带 �� ��ȸ������ ����
		if (exp->key > num) printf(" %d", exp->key); //���� pop�� ��尡 num���� ũ�� ���
		exp = exp->right; //������ ���� �̵��� �ݺ�
	}
}
//�ʱ� Ʈ�� ����
TreeNode n1 = { 1,NULL,NULL };
TreeNode n2 = { 4,NULL,NULL };
TreeNode n3 = { 15,&n1,&n2 };
TreeNode n4 = { 16,NULL,NULL };
TreeNode n5 = { 25,NULL,NULL };
TreeNode n6 = { 7,&n4,&n5 };
TreeNode n7 = { 30,&n3,&n6 };
TreeNode* exp = &n7;

int main(void) {
	head();
	inorder(exp); //���� ��ȸ�� ���
	printf("\nNumber of nodes in tree: %d\n", get_node_count(exp)); //��� ���� ���
	printf("Height of the tree: %d\n", get_height(exp)); //height ���
	printf("Number of leafs in tree: %d\n", get_leaf_count(exp)); //�ܸ� ��� ���� ���
	printf("Balanced tree? ");
	balanced(exp); //balanced tree ���� ���
	printf("\nInput a number to check: ");
	int num;
	scanf("%d", &num); //����ڷκ��� ���ڸ� �Է¹޾Ƽ�
	printf("numbers greater than %d:", num);
	greater_than(exp,num); //�� ���ں��� ū ����� key���� ��ȯ
}