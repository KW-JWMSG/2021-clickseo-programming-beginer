#pragma warning(disable:4996)
#include <stdio.h>



void PRINT(int);

int main(void) {

	int gugudan;
	printf("원하는 구구단(1~9) : ");
	scanf("%d",&gugudan);
	PRINT(gugudan);
	return 0;
}


void PRINT(int num) {
	for (int i =1; i <= 9; i++) {
		printf("%d * %d = %d\n", num, i, num * i);
	}
}