#pragma warning(disable:4996)
#include <stdio.h>


void revPrint(void);


int main(void) {

	printf("���ڿ� �Է� : ");
	revPrint();
	return 0;
}

void revPrint(void) {
	char c = getchar();
	if (c != '\n')
		revPrint();
	putchar(c);
}