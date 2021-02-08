#include <stdio.h>
#include <stdlib.h>
void head() {
	printf("====================\n");
	printf("학과:사이버보안전공\n");
	printf("학번:1971090\n");
	printf("성명:한근영\n");
	printf("====================\n");
}

typedef struct TreeNode { //트리 각 노드에 대한 구조체
	int key; //노드의 데이터를 저장할 변수
	struct TreeNode* left, * right; //각 노드의 오른쪽,왼쪽 자식 노드를 가리킬 포인터 변수
}TreeNode;

int get_node_count(TreeNode* exp) { //트리의 노드 개수를 반환하는 함수
	if (exp == NULL) return 0;
	else return get_node_count(exp->left) + get_node_count(exp->right) + 1; //왼쪽 subtree, 오른쪽 subtree의 노드 개수와 자기 자신을 더해 반환(재귀)
}

int get_leaf_count(TreeNode* exp) { //단말 노드 개수를 반환하는 함수
	if (exp == NULL) return 0;
	else {
		if (exp->left == NULL && exp->right == NULL) return 1; //만약 exp가 단말노드이면 1 반환
		else return get_leaf_count(exp->left) + get_leaf_count(exp->right); //재귀
	}
}

int get_height(TreeNode* exp) { //트리의 height를 반환하는 함수
	if (exp == NULL) return 0;
	else {
		int l_height = get_height(exp->left); //왼쪽 subtree의 height
		int r_height = get_height(exp->right); //오른쪽 subtree의 height
		if (l_height >= r_height) return l_height + 1; //만약 왼쪽 subtree의 height가 더 크면 l_height에 root 노드를 포함한 값을 반환
		else return r_height + 1; //아니라면 r_height에 root 노드를 포함한 값을 반환
	}
}

void inorder(TreeNode* exp) { //중위 순회로 출력하는 함수
	if (exp) {
		inorder(exp->left); //왼쪽 노드부터 출력
		printf(" [%d]", exp->key); //그 다음에 부모 노드 출력
		inorder(exp->right); //그 다음에 오른쪽 노드 출력
	}
}

void balanced(TreeNode* exp) { //이진트리의 subtree 높이 차이가 최대 1이하인 경우 찾는 함수
	int l_height = get_height(exp->left); //왼쪽 subtree의 height
	int r_height = get_height(exp->right); //오른쪽 subtree의 height
	if ((l_height - r_height >= -1)&&(l_height - r_height <= 1)) printf("Yes"); //만약 subtree의 높이 차가 최대 1이하인 경우면 balanced tree
	else printf("No");//아니면 no 출력
}

TreeNode* stack[100]; //트리 노드를 저장할 스택
int top = -1; //스택의 top 초기화
void push(TreeNode* p) { //스택에 push하는 함수
	if (top < 99) stack[++top] = p;
}
TreeNode* pop(void) { //스택에서 pop하는 함수
	TreeNode* p = NULL;
	if (top != -1) p = stack[top--];
	return p;
}
void greater_than(TreeNode*exp,int num) { //사용자가 입력한 값 num보다 큰 key값들만 출력하는 함수
	while (true) {//반복
		for (; exp; exp = exp->left) push(exp); //left에 노드가 있으면 stack에 push
		exp = pop(); //left에 노드가 어 없으면 pop
		if (exp == NULL) break; //모든 노드를 다 순회했으면 종료
		if (exp->key > num) printf(" %d", exp->key); //만약 pop한 노드가 num보다 크면 출력
		exp = exp->right; //오른쪽 노드로 이동해 반복
	}
}
//초기 트리 상태
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
	inorder(exp); //중위 순회로 출력
	printf("\nNumber of nodes in tree: %d\n", get_node_count(exp)); //노드 개수 출력
	printf("Height of the tree: %d\n", get_height(exp)); //height 출력
	printf("Number of leafs in tree: %d\n", get_leaf_count(exp)); //단말 노드 개수 출력
	printf("Balanced tree? ");
	balanced(exp); //balanced tree 여부 출력
	printf("\nInput a number to check: ");
	int num;
	scanf("%d", &num); //사용자로부터 숫자를 입력받아서
	printf("numbers greater than %d:", num);
	greater_than(exp,num); //그 숫자보다 큰 노드의 key값들 반환
}