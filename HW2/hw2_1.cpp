#include <stdio.h>
#include <stdlib.h>

void head() {
	printf("====================\n");
	printf("�а�:���̹���������\n");
	printf("�й�:1971090\n");
	printf("����:�ѱٿ�\n");
	printf("====================\n");
}

typedef struct TreeNode { //�� ��忡 ���� ������ �����ϴ� ����ü
	int data;
	struct TreeNode* left, * right;
}TreeNode;

int max_key(TreeNode* exp,int max) { //�ִ� key���� ã�� �Լ�
	if (exp == NULL) return max; //���� �ܸ� ����̸� ���ڷ� ���� max �� ��ȯ
	else { //��ܸ� ����̸�
		if (exp->data > max) { //���� ���� ����� data���� ���ڷ� ���� max������ ũ�ٸ�
			int left_max = max_key(exp->left, exp->data); //���� ����� data���� �� max���� �Ǿ� left subtree ��������� max_key() ã�Ƽ� ����
			int right_max = max_key(exp->right, exp->data);//���� ����� data���� �� max���� �Ǿ� right subtree ��������� max_key() ã�Ƽ� ����
			if (left_max > right_max) return left_max; //���� left_max ���� �� ũ�� left_max�� ��ȯ
			else return right_max; //right_max���� �� ũ�� right_max�� ��ȯ
		}
		else { //���� ����� data������ ���ڷ� ���� max���� ũ��
			int left_max = max_key(exp->left, max); //���ڷ� ���� max�� �״�� left subtree ��������� max_key() ã�Ƽ� ����
			int right_max = max_key(exp->right, max); //���ڷ� ���� max�� �״�� right subtree ��������� max_key() ã�Ƽ� ����
			if (left_max > right_max) return left_max; //���� left_max�� �� ũ�� left_max�� ��ȯ
			else return right_max; //�ƴ϶�� right_max�� ��ȯ
		}
	}
}

int min_key(TreeNode* exp, int min) { //�ּ� key���� ã�� �Լ�
	if (exp == NULL) return min; //�ܸ� ����̸� ���ڷ� ���� min�� �״�� ��ȯ
	else { //��ܸ� ����̸�
		if (exp->data < min) { //min������ ���� ����� data���� �� ������
			int left_min = min_key(exp->left, exp->data); //���� ����� data���� �� min������ �Ͽ� left subtree ��������� min�� ã�Ƽ� ����
			int right_min = min_key(exp->right, exp->data);//���� ����� data���� �� min������ �Ͽ� right sugtree ��������� min�� ã�Ƽ� ����
			if (left_min < right_min) return left_min; //left_min���� �� ������ left_min ��ȯ
			else return right_min; //�ƴϸ� right_min �� ��ȯ
		}
		else { //min���� ���� ����� data������ ������
			int left_min = min_key(exp->left, min); //min�� �״�� left subtree ��������� min�� ã�Ƽ� ����
			int right_min = min_key(exp->right, min); //min�� �״�� right subtree ��������� min�� ã�Ƽ� ����
			if (left_min < right_min) return left_min; //left_min���� �� ������ left_min�� ��ȯ
			else return right_min;//�ƴϸ� right_min �� ��ȯ
		}
	}
}

int sum_key(TreeNode* exp) { //key���� �հ踦 ���ϴ� �Լ�
	if (exp == NULL) return 0; //���� �ܸ� ���� 0 ��ȯ
	else return sum_key(exp->left) + sum_key(exp->right) + exp->data; //��ܸ� ����̸� ��������� left subtree, right subtree key �� �հ�� ���� ����� data�� ���� �� ��ȯ
}

int one_child(TreeNode* exp) { //child �� �� ���� ����� �� ���ϴ� �Լ�
	if (exp == NULL) return 0; //�ܸ� ���� 0 ��ȯ
	else { //��ܸ� ����
		if ((exp->left == NULL && exp->right != NULL) || (exp->left != NULL && exp->right == NULL)) { //���� child�� �� ���� �����
			return one_child(exp->left) + one_child(exp->right) + 1; //��������� left subtree������ child �� ���� ����� ���� right subtree������ child �� ���� ����� �� ���ؼ� 1�� ���� �� ��ȯ
		}
		else return one_child(exp->left) + one_child(exp->right); //child�� �� ���� ��尡 �ƴ϶�� ��������� left subtree������ child �� ���� ����� ���� right subtree������ child �� ���� ����� �� ���ؼ� ���� �� ��ȯ
	}
}

int main(void) {
	head();
	//tree ����(�����ؼ� ���)
	TreeNode n0 = { 11, NULL, NULL };
	TreeNode n1 = { 2, &n0, NULL };
	TreeNode n2 = { 5, &n1, NULL };
	TreeNode n3 = { 13, &n2, NULL };
	TreeNode n4 = { 25, &n3, NULL };
	TreeNode n5 = { 8, NULL, NULL };
	TreeNode n6 = { 3, NULL, &n5 };
	TreeNode n7 = { 21, &n4, &n6 };
	TreeNode* exp = &n7;

	printf("Sum of keys in binary tree: %d\n", sum_key(exp)); //key�� �հ� ���
	printf("Num of one child nodes: %d\n", one_child(exp)); //child �� �� ���� ����� �� ���
	int max = 0; //�񱳿� ���� ��Ȯ�� ���� ã�� �� �ֵ��� �ʱⰪ �ִ��� �۰� ����
	int min = 100; //�񱳿� ���� ��Ȯ�� ���� ã�� �� �ֵ��� �ʱⰪ �ִ��� ũ�� ����
	printf("Max value: %d\n", max_key(exp,max)); //�ִ� key�� ���
	printf("Min value: %d\n", min_key(exp,min)); //�ּ� key�� ���
}