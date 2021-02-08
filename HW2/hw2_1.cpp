#include <stdio.h>
#include <stdlib.h>

void head() {
	printf("====================\n");
	printf("학과:사이버보안전공\n");
	printf("학번:1971090\n");
	printf("성명:한근영\n");
	printf("====================\n");
}

typedef struct TreeNode { //각 노드에 대한 정보를 저장하는 구조체
	int data;
	struct TreeNode* left, * right;
}TreeNode;

int max_key(TreeNode* exp,int max) { //최대 key값을 찾는 함수
	if (exp == NULL) return max; //만약 단말 노드이면 인자로 받은 max 값 반환
	else { //비단말 노드이면
		if (exp->data > max) { //만약 현재 노드의 data값이 인자로 받은 max값보다 크다면
			int left_max = max_key(exp->left, exp->data); //현재 노드의 data값이 새 max값이 되어 left subtree 재귀적으로 max_key() 찾아서 저장
			int right_max = max_key(exp->right, exp->data);//현재 노드의 data값이 새 max값이 되어 right subtree 재귀적으로 max_key() 찾아서 저장
			if (left_max > right_max) return left_max; //만약 left_max 값이 더 크면 left_max값 반환
			else return right_max; //right_max값이 더 크면 right_max값 반환
		}
		else { //현재 노드의 data값보다 인자로 받은 max값이 크면
			int left_max = max_key(exp->left, max); //인자로 받은 max값 그대로 left subtree 재귀적으로 max_key() 찾아서 저장
			int right_max = max_key(exp->right, max); //인자로 받은 max값 그대로 right subtree 재귀적으로 max_key() 찾아서 저장
			if (left_max > right_max) return left_max; //만약 left_max가 더 크면 left_max값 반환
			else return right_max; //아니라면 right_max값 반환
		}
	}
}

int min_key(TreeNode* exp, int min) { //최소 key값을 찾는 함수
	if (exp == NULL) return min; //단말 노드이면 인자로 받은 min값 그대로 반환
	else { //비단말 노드이면
		if (exp->data < min) { //min값보다 현재 노드의 data값이 더 작으면
			int left_min = min_key(exp->left, exp->data); //현재 노드의 data값을 새 min값으로 하여 left subtree 재귀적으로 min값 찾아서 저장
			int right_min = min_key(exp->right, exp->data);//현재 노드의 data값을 새 min값으로 하여 right sugtree 재귀적으로 min값 찾아서 저장
			if (left_min < right_min) return left_min; //left_min값이 더 작으면 left_min 반환
			else return right_min; //아니면 right_min 값 반환
		}
		else { //min값이 현재 노드의 data값보다 작으면
			int left_min = min_key(exp->left, min); //min값 그대로 left subtree 재귀적으로 min값 찾아서 저장
			int right_min = min_key(exp->right, min); //min값 그대로 right subtree 재귀적으로 min값 찾아서 저장
			if (left_min < right_min) return left_min; //left_min값이 더 작으면 left_min값 반환
			else return right_min;//아니면 right_min 값 반환
		}
	}
}

int sum_key(TreeNode* exp) { //key값의 합계를 구하는 함수
	if (exp == NULL) return 0; //만약 단말 노드면 0 반환
	else return sum_key(exp->left) + sum_key(exp->right) + exp->data; //비단말 노드이면 재귀적으로 left subtree, right subtree key 값 합계와 현재 노드의 data값 더한 값 반환
}

int one_child(TreeNode* exp) { //child 한 개 갖는 노드의 수 구하는 함수
	if (exp == NULL) return 0; //단말 노드면 0 반환
	else { //비단말 노드면
		if ((exp->left == NULL && exp->right != NULL) || (exp->left != NULL && exp->right == NULL)) { //만약 child가 한 개인 노드라면
			return one_child(exp->left) + one_child(exp->right) + 1; //재귀적으로 left subtree에서의 child 한 개인 노드의 수와 right subtree에서의 child 한 개인 노드의 수 구해서 1과 더한 값 반환
		}
		else return one_child(exp->left) + one_child(exp->right); //child가 한 개인 노드가 아니라면 재귀적으로 left subtree에서의 child 한 개인 노드의 수와 right subtree에서의 child 한 개인 노드의 수 구해서 더한 값 반환
	}
}

int main(void) {
	head();
	//tree 정보(복사해서 사용)
	TreeNode n0 = { 11, NULL, NULL };
	TreeNode n1 = { 2, &n0, NULL };
	TreeNode n2 = { 5, &n1, NULL };
	TreeNode n3 = { 13, &n2, NULL };
	TreeNode n4 = { 25, &n3, NULL };
	TreeNode n5 = { 8, NULL, NULL };
	TreeNode n6 = { 3, NULL, &n5 };
	TreeNode n7 = { 21, &n4, &n6 };
	TreeNode* exp = &n7;

	printf("Sum of keys in binary tree: %d\n", sum_key(exp)); //key값 합계 출력
	printf("Num of one child nodes: %d\n", one_child(exp)); //child 한 개 갖는 노드의 수 출력
	int max = 0; //비교에 의해 정확한 값을 찾을 수 있도록 초기값 최대한 작게 설정
	int min = 100; //비교에 의해 정확한 값을 찾을 수 있도록 초기값 최대한 크게 설정
	printf("Max value: %d\n", max_key(exp,max)); //최대 key값 출력
	printf("Min value: %d\n", min_key(exp,min)); //최소 key값 출력
}