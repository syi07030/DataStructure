#include <stdio.h>
#include <stdlib.h>
#include <string.h> //strcmp,strcpy 사용
#define SIZE 20 //단어 크기 임의로 지정

void head() {
	printf("====================\n");
	printf("학과:사이버보안전공\n");
	printf("학번:1971090\n");
	printf("성명:한근영\n");
	printf("====================\n");
}

typedef struct TreeNode { //각 노드에 대한 구조체
	char key[SIZE]; //과일명 저장할 key 문자배열
	struct TreeNode* left, * right; //자식노드 연결할 링크
}TreeNode;

TreeNode* new_node(char item[]) { //새로운 노드 생성하는 함수
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode)); //동적할당
	strcpy(node->key,item); //인자로 받은 item값 key값으로 저장
	node->left = node->right = NULL; //자식 노드는 모두 null로 초기화
	return node;
}

TreeNode* insert(TreeNode* node, char key[]) { //새로운 단어 insert하는 함수
	if (node == NULL) return new_node(key); //단말까지 오면 노드 생성해서 삽입
	if (strcmp(key, node->key) == -1) node->left = insert(node->left, key); //만약 key값이 아스키코드 상 현재 노드의 key값보다 작으면 왼쪽 subtree로 다시 재귀적으로 insert
	else if (strcmp(key, node->key) == 1) node->right = insert(node->right, key); //key값이 아스키코드 상 현재 노드의 key값보다 클 경우 오른쪽 subtree로 다시 재귀적으로 insert
	return node;
}

TreeNode* min_value_node(TreeNode* node) { //트리에서 노드 삭제하고 트리 재정비할 때 필요한 노드 찾기 함수
	TreeNode* current = node;
	while (current->left != NULL) { //왼쪽에 노드가 더 이상 없을 때까지 왼쪽 자식 노드로 내려가는 거 반복
		current = current->left;
	}
	return current; //가장 작은 key값 갖는 왼쪽 노드 반환
}

TreeNode* del(TreeNode* root, char key[]) { //특정 단어 삭제하는 함수
	if (root == NULL) return root; 
	else if (strcmp(root->key, key) == 1) root->left = del(root->left, key); //왼쪽 subtree에서 key값 삭제하도록 재귀호출
	else if (strcmp(root->key, key) == -1) root->right = del(root->right, key); //오른쪽 subtree에서 key값 삭제하도록 재귀호출
	else { //삭제하고자 하는 key값을 찾았을 경우
		if (root->left == NULL) { //왼쪽 자식이 없을 경우
			TreeNode* temp = root->right; //오른쪽 자식 임시로 temp 저장
			free(root); //해당 노드 삭제
			return temp; //해당 노드 위치에 오른쪽 자식 노드가
		}
		else if (root->right == NULL) { //오른쪽 자식 노드가 없을 경우
			TreeNode* temp = root->left; //왼쪽 자식 노드 임시로 temp 저장
			free(root);//해당 노드 삭제
			return temp; //해당 노드 위치에 왼쪽 자식 노드가
		}
		TreeNode* temp = min_value_node(root->right); //child가 둘 다 있을 경우 가장 가까운 key값 갖는 노드 찾기
		strcpy(root->key, temp->key); //가장 가까운 key값을 삭제할 위치에 복사
		root->right = del(root->right, temp->key); //복사된 값을 갖고 있던 노드 삭제
	}
	return root; //새로운 root 반환
}

TreeNode* search(TreeNode* node, char key[]) { //특정 단어 검색하는 함수
	if (node == NULL) return NULL; 
	if (strcmp(node->key, key) == 0) return node; //찾으면 그 key값 갖는 node 반환 
	else if (strcmp(key, node->key) == -1) return search(node->left, key); //현재 node의 key값보다 작으면 left subtree 검색
	else return search(node->right, key); //현재 node값보다 크면 right subtree 검색
}

void inorder_print(TreeNode* root) { //inorder 정렬 상태로 출력하는 함수
	if (root == NULL) return;
	else {
		inorder_print(root->left); //왼쪽 노드부터 출력
		printf("%s\n", root->key); //root key값 출력
		inorder_print(root->right); //오른쪽 노드 출력
	}
}

TreeNode* init(TreeNode* root) { //초기화 함수
	char word[6][SIZE] = {"apple","banana","blueberry","kiwi","orange","pear"};
	for (int i = 0; i < 6; i++) {
		root = insert(root, word[i]); //초기값들 트리에 삽입
	}
	return root;
}

int main(void) {
	head();

	TreeNode* root = NULL; //root 생성
	root=init(root); //트리 초기화
	while (true) { //반복
		int op;
		printf("\n* Choose operation<1.insert 2.delete 3.search 4.print 5.exit>:");
		scanf("%d", &op); //사용자로부터 무슨 operation할지 입력받기
		switch (op) { //op값에 따라
		case 1: //1이면 새로운 단어 입력
			char w[SIZE];
			printf("Enter a word:");
			scanf("%s", w);
			root = insert(root, w); //입력받은 단어를 트리에 삽입
			break;
		case 2: //2면 특정단어 삭제
			char d[SIZE];
			printf("Enter a word to delete:");
			scanf("%s", d);
			root = del(root, d); //입력받은 단어를 찾아서 트리에서 삭제
			break;
		case 3: //3이면 특정단어 검색
			char s[SIZE];
			printf("Enter a word:");
			scanf("%s", s);
			if (search(root,s) != NULL) printf("%s is found\n", s); //입력받은 단어가 있는지 여부 출력
			else printf("%s is not found\n", s);
			break;
		case 4: //4면 모든 단어 inorder상태로 출력
			inorder_print(root);
			break;
		case 5: //5면 프로그램 종료
			printf("Program finished\n");
			exit(0);
		default: //그 외는 아래 출력하고 반복
			printf("Wrong input\n");
			break;
		}
	}
}