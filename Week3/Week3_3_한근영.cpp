#include <stdio.h>
#include <stdlib.h> //���� �Լ����� exit()�� ȣ���ϱ� ����
#define MAX 100 //�迭�� �ִ�ũ��
void head() {
	printf("====================\n");
	printf("�а�:���̹���������\n");
	printf("�й�:1971090\n");
	printf("����:�ѱٿ�\n");
	printf("====================\n");
}
void elementGeneration(int a[],int s) { //�迭 ���� �Է¹޾Ƽ� �����ϴ� �Լ�, �迭�� �ּҿ� element ������ ���ڷ�
	for (int i = 0; i < s; i++) {
		scanf("%d", &a[i]); //�Է¹޾Ƽ� �ش� �ε��� �迭�� ����
	}
}
void elementInsertion(int a[], int location, int value, int s) { //element �߰��ϴ� �Լ�, �迭 �ּҿ� �߰��ϴ� ��ġ, �߰��� ��, �߰��� ���� �迭 element ������ ���ڷ�
	for (int i = s - 1; i > location-2; i--) { //element�� �߰��ϱ� ���� ��ġ�κ��� �����ʿ� �ִ� ���ҵ��� �ϳ��� �ڷ� �̷�
		a[i + 1] = a[i];
	}
	a[location - 1] = value; //���ο� ���� �߰�
}
void elementDeletion(int a[],int location, int s) { //element �����ϴ� �Լ�, �迭 �ּҿ� �����ϴ� ��ġ, ������ ���� �迭 ���ҵ� ������ ���ڷ�
	for (int i = location - 1; i < s; i++) { //�����ϰ��� �ϴ� ������ ��ġ�κ��� �����ʿ� �ִ� ���ҵ��� �ϳ��� ������ ������
		a[i] = a[i + 1];
	}
}
void elementPrint(int a[],int s) { //�迭 ����ϴ� �Լ�, �迭 �ּҿ� element ������ ���ڷ�
	printf("Array: ");
	for (int i = 0; i < s; i++) { //���
		printf(" %d", a[i]);
	}
}
int main(void) {
	head();
	int count;//ó���� �Է��ϴ� ���� ���� ������ ����
	int arr[MAX]; //�迭 ����
	printf("How many numbers? ");
	scanf("%d", &count); //ó���� �Է��� ���� ���� �Է¹޾Ƽ� ����
	printf("input %d numbers\n", count);
	elementGeneration(arr, count); //�迭 ����
	elementPrint(arr,count); //�迭 ���
	int ch; //� operation�� ���������� ���� ����ڰ� �Է��ϴ� ���ڸ� ������ ����
	while (true) {
		printf("\n\nChoose operation:\n1.insertion  2.deletion  3.output  0.program end\n");
		scanf("%d", &ch); //����ڰ� �Է��� operation ��ȣ�� �Է¹޾Ƽ� ����
		switch (ch) 
		{
		case 1: //ch ���� 1�̸�
			printf("Input location and value to insert\n");
			int loc_inp, value;
			scanf("%d %d", &loc_inp, &value); //insert�� ��ġ�� ���� �Է¹޾Ƽ� ����
			if (loc_inp > count + 1) { //���� �߰��� ��ġ�� ���� �迭�� ���ҵ� ����+1���� ũ�� ������ ���� ����ϰ� break
				printf("Choose between %d and %d", 1, count + 1);
			}
			else { //�߰��� ��ġ�� 1�� count+1�� ���̶��
				count += 1; //count�� 1 ������Ű��
				elementInsertion(arr, loc_inp, value, count); //insert �Լ� ȣ��
				elementPrint(arr, count); //insert�ϰ� �� ���� �迭�� ���� ���
			}
			break;
		case 2: //ch���� 2�̸�
			printf("Input location to delete\n");
			int loc_del;
			scanf("%d", &loc_del); //������ ������ ��ġ�� �Է¹޾Ƽ� ����
			if (loc_del > count || loc_del < 1) { //��ġ�� ���� ���� ���� ������ ũ�ų� 1���� ���� ��� ������ ����ϰ� break
				printf("No element in location %d", loc_del);
			}
			else { //������ ��ġ�� 1�� count�� ���̿� �ִٸ�
				count -= 1; //count ���� 1 ���ҽ�Ű��
				elementDeletion(arr, loc_del, count); //���� �����ϴ� �Լ� ȣ��
				elementPrint(arr, count); //�����ϰ� �� ���� �迭 ���
			}
			break;
		case 3: //ch ���� 3�̸�
			elementPrint(arr,count); //�迭 ���
			break;
		case 0://ch���� 0�̸�
			exit(0); //���α׷� ����
		default: //�� ���� ���̸� �׳� break�ϰ� �ٽ� while�� ����
			break;
		}
	}
}