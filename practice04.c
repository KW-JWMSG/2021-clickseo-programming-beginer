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
	printf("********* 메    뉴 *********\n");
	printf("1. 알파벳 박스 모양 출력\n");
	printf("2. 알파벳 피라미드 모양 출력\n");
	printf("3. 프로그램 종료\n");
	printf("****************************\n");
	printf("메뉴 선택 : ");
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