#pragma warning(disable:4996)
#include <stdio.h>


int waitMenu();
void printBox();
void printPyramd();


int main(void) {

	while (1) {
		int menu = waitMenu();
		if (menu == 1)
			printBox();
		else if (menu == 2)
			printPyramd();
		else if (menu == 3)
			break;
	}

	return 0;
}

int waitMenu() {
	int selectedMenu = 0;
	printf("********* ��    �� *********\n");
	printf("1. ���ĺ� �ڽ� ��� ���\n");
	printf("2. ���ĺ� �Ƕ�̵� ��� ���\n");
	printf("3. ���α׷� ����\n");
	printf("****************************\n");
	printf("�޴� ���� : ");
	scanf(" %d", &selectedMenu);
	return selectedMenu;
}

void printBox() {
	int startChar = 'A';
	int lastChar = 'Z';
	int BoxSize = lastChar - startChar + 1;
	for (int i = 0; i < BoxSize; i++) {
		for (int j = i; j < BoxSize + i; j++){
			int nowChar = j % BoxSize + startChar;
			printf("%c ", nowChar);
		}
		printf("\n");
	}
}

void printPyramd() {
	int startChar = 'A';
	int lastChar = 'Z';
	int BoxSize = lastChar - startChar + 1;
	for (int i = 0; i < BoxSize; i++) {
		for (int j = 0; j < BoxSize - i; j++) {
			printf(" ");
		}
		for (int j = 0; j <= i; j++) {
			int nowChar = j % BoxSize + startChar;
			printf(" %c", nowChar);
		}
		printf("\n");
	}
}