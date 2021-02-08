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
	int key; //노드의 key값을 저장할 변수
	struct TreeNode* left, * right; //노드의 왼쪽, 오른쪽 child 노드를 가리킬 포인터 변수
}TreeNode;

TreeNode* new_node(int item) { //새로운 노드를 생성해서 반환하는 함수
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode)); //새로운 노드 생성(동적할당)
	node->key = item; //노드의 key값에 인자로 받은 item값 저장
	node->left = node->right = NULL; //child 노드가 아직 없으므로 null
	return node;
}

TreeNode* insert_node(TreeNode* node, int key) { //트리에 노드 삽입하는 함수
	if (node == NULL) return new_node(key);
	if (key < node->key) node->left = insert_node(node->left, key); //만약 인자로 받은 key값이 node의 key값보다 작으면 왼쪽에 삽입 
	else if (key > node->key) node->right = insert_node(node->right, key); //반대면 오른쪽에 삽입
	return node;
}

void inorder(TreeNode* root) { //중위순회로 트리 출력하는 함수
	if (root == NULL) return;
	else {
		inorder(root->left); //왼쪽부터 출력
		printf(" [%d]", root->key); //그 다음에 부모 노드 key값 출력하고
		inorder(root->right); //그 다음에 오른쪽 노드 출력
	}
}

TreeNode* search(TreeNode* node, int key) { //이진탐색트리 탐색하는 함수
	if (node == NULL) return NULL;
	if (node->key == key) return node; //만약 인자로 받은 key값이랑 node->key값이 같으면 그 노드 반환
	else if (key < node->key) return search(node->left, key); //만약 인자로 받은 key값이 작으면 왼쪽 subtree에서 다시 탐색
	else return search(node->right, key);//더 크면 오른쪽 subtree에서 다시 탐색
}

TreeNode* min_value_node_r(TreeNode* node) { //right subtree에서 제일 작은 값 갖는 노드 반환하는 함수
	TreeNode* current = node;
	while (current->left != NULL) {
		current = current->left;
	}
	return current;
}

TreeNode* min_value_node_l(TreeNode* node) { //left subtree에서 제일 큰 값 갖는 노드 반환하는 함수
	TreeNode* current = node;
	while (current->right != NULL) {
		current = current->right;
	}
	return current;
}

TreeNode* delete_node(TreeNode* root, int key) { //트리에서 해당 노드 찾아서 삭제하고 새로운 root 반환하는 함수
	if (root == NULL) return root;
	else if (root->key > key) root->left = delete_node(root->left, key); //왼쪽 subtree에서 key값 찾아 삭제하도록 재귀 호출
	else if (root->key < key) root->right = delete_node(root->right, key);//오른쪽 subtree에서 key값 찾아 삭제하도록 재귀 호출
	else { //삭제하고자 하는 key값 갖는 노드를 찾으면
		if (root->left == NULL) { //단말 노드거나 right child 하나만 갖는 경우
			TreeNode* tmp = root->right;
			free(root); //root 노드 free해주고
			return tmp; //새로운 root 반환
		}
		else if (root->right == NULL) { //단말 노드거나 left child 하나만 갖는 경우
			TreeNode* tmp = root->left;
			free(root); //root 노드 free해주고
			return tmp; //새로운 root 반환
		}
		//child가 둘 다 있는 경우
		TreeNode* tmp_l = min_value_node_l(root->left); //left subtree에서 제일 큰 값 갖는 노드 저장
		TreeNode* tmp_r = min_value_node_r(root->right);//right subtree에서 제일 작은 값 갖는 노드 저장
		TreeNode* tmp;
		printf("left subtree의 MAX: %d", tmp_l->key); //left subtree에서 제일 큰 key값 출력
		printf("\nright subtree의 MIN: %d", tmp_r->key); //right subtree에서 제일 작은 key값 출력
		if (abs(key - (tmp_l->key)) >= abs(key - (tmp_r->key))) { //삭제할 노드의 key값과 더 가까운 값이  right subtree에서의 제일 작은 값이라면
			tmp = tmp_r; //tmp에 right subtree에서의 제일 작은 값 갖는 노드 저장
			printf("\noriginal value:%d  new value:%d\n", key, tmp->key);
			root->key = tmp->key; //가장 가까운 key값을 삭제할 위치에 복사
			root->right = delete_node(root->right, tmp->key); //복사된 값을 갖고 있던 노드 삭제
		}
		else {//삭제할 노드의 key값과 더 가까운 값이  left subtree에서의 제일 큰 값이라면
			tmp = tmp_l; //tmp에 left subtree에서의 제일 큰 값 갖는 노드 저장
			printf("\noriginal value:%d  new value:%d\n", key, tmp->key);
			root->key = tmp->key; //가장 가까운 key값을 삭제할 위치에 복사
			root->left = delete_node(root->left, tmp->key); //복사된 값을 갖고 있던 노드 삭제
		}
	}
	return root; //root 반환
}
int main(void) {
	head();

	TreeNode* root = NULL; //root를 가리킬 구조체 포인터 변수 초기화
	//초기상태
	root = insert_node(root, 30);
	root = insert_node(root, 20);
	root = insert_node(root, 10);
	root = insert_node(root, 45);
	root = insert_node(root, 50);
	root = insert_node(root, 60);

	printf("이진 탐색 트리 중위 순회 결과\n");
	inorder(root); //트리 중위 순회로 출력
	printf("\n");
	char ch;
	while (true) { //반복
		printf("\n* operation 선택: Insert(I) / Delete(D) / Exit(X): ");
		scanf(" %c", &ch);
		switch (ch) { //사용자가 입력한 operation 선택에 따라
		case 'I': //I를 입력하면
			int i;
			printf("Insert할 값은? ");
			scanf("%d", &i); 
			insert_node(root, i); //사용자가 입력한 숫자를 인자로 함께 보내 트리에 새로운 노드 삽입
			inorder(root); //중위순회로 트리 출력
			printf("\n");
			break;
		case 'D': //D를 입력하면
			printf("Delete할 값은? ");
			int d;
			scanf("%d", &d);
			delete_node(root, d); //사용자가 입력한 숫자를 인자로 함께 보내 트리에서 해당되는 값을 key로 갖는 노드 삭제
			inorder(root);//중위순회로 트리 출력
			printf("\n");
			break;
		case 'X': //X를 입력하면
			printf("프로그램 종료");
			exit(0); //종료
		}
	}
}