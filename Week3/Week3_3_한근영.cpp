#include <stdio.h>
#include <stdlib.h> //메인 함수에서 exit()을 호출하기 위해
#define MAX 100 //배열의 최대크기
void head() {
	printf("====================\n");
	printf("학과:사이버보안전공\n");
	printf("학번:1971090\n");
	printf("성명:한근영\n");
	printf("====================\n");
}
void elementGeneration(int a[],int s) { //배열 원소 입력받아서 저장하는 함수, 배열의 주소와 element 개수를 인자로
	for (int i = 0; i < s; i++) {
		scanf("%d", &a[i]); //입력받아서 해당 인덱스 배열에 저장
	}
}
void elementInsertion(int a[], int location, int value, int s) { //element 추가하는 함수, 배열 주소와 추가하는 위치, 추가할 값, 추가한 후의 배열 element 개수를 인자로
	for (int i = s - 1; i > location-2; i--) { //element를 추가하기 위한 위치로부터 오른쪽에 있는 원소들을 하나씩 뒤로 미룸
		a[i + 1] = a[i];
	}
	a[location - 1] = value; //새로운 원소 추가
}
void elementDeletion(int a[],int location, int s) { //element 삭제하는 함수, 배열 주소와 삭제하는 위치, 삭제한 후의 배열 원소들 개수를 인자로
	for (int i = location - 1; i < s; i++) { //삭제하고자 하는 원소의 위치로부터 오른쪽에 있는 원소들을 하나씩 앞으로 가져옴
		a[i] = a[i + 1];
	}
}
void elementPrint(int a[],int s) { //배열 출력하는 함수, 배열 주소와 element 개수를 인자로
	printf("Array: ");
	for (int i = 0; i < s; i++) { //출력
		printf(" %d", a[i]);
	}
}
int main(void) {
	head();
	int count;//처음에 입력하는 숫자 개수 저장할 변수
	int arr[MAX]; //배열 선언
	printf("How many numbers? ");
	scanf("%d", &count); //처음에 입력할 숫자 개수 입력받아서 저장
	printf("input %d numbers\n", count);
	elementGeneration(arr, count); //배열 생성
	elementPrint(arr,count); //배열 출력
	int ch; //어떤 operation을 실행할지에 대해 사용자가 입력하는 숫자를 저장할 변수
	while (true) {
		printf("\n\nChoose operation:\n1.insertion  2.deletion  3.output  0.program end\n");
		scanf("%d", &ch); //사용자가 입력한 operation 번호를 입력받아서 저장
		switch (ch) 
		{
		case 1: //ch 값이 1이면
			printf("Input location and value to insert\n");
			int loc_inp, value;
			scanf("%d %d", &loc_inp, &value); //insert할 위치와 값을 입력받아서 저장
			if (loc_inp > count + 1) { //만약 추가할 위치가 현재 배열의 원소들 개수+1보다 크면 다음과 같이 출력하고 break
				printf("Choose between %d and %d", 1, count + 1);
			}
			else { //추가할 위치가 1과 count+1값 사이라면
				count += 1; //count값 1 증가시키고
				elementInsertion(arr, loc_inp, value, count); //insert 함수 호출
				elementPrint(arr, count); //insert하고 난 후의 배열에 대한 출력
			}
			break;
		case 2: //ch값이 2이면
			printf("Input location to delete\n");
			int loc_del;
			scanf("%d", &loc_del); //삭제할 원소의 위치를 입력받아서 저장
			if (loc_del > count || loc_del < 1) { //위치가 현재 원소 개수 갑보다 크거나 1보다 작을 경우 다음을 출력하고 break
				printf("No element in location %d", loc_del);
			}
			else { //삭제할 위치가 1과 count값 사이에 있다면
				count -= 1; //count 값을 1 감소시키고
				elementDeletion(arr, loc_del, count); //원소 삭제하는 함수 호출
				elementPrint(arr, count); //삭제하고 난 후의 배열 출력
			}
			break;
		case 3: //ch 값이 3이면
			elementPrint(arr,count); //배열 출력
			break;
		case 0://ch값이 0이면
			exit(0); //프로그램 종료
		default: //그 외의 값이면 그냥 break하고 다시 while문 실행
			break;
		}
	}
}