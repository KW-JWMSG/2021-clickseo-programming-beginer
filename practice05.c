#pragma warning(disable:4996)
#include <stdio.h>


void devider(int, int);


int main(void) {

	int left, right;
	printf("두 정수 입력 : ");
	scanf("%d %d", &left, &right);
	devider(left, right);
	return 0;
}

void devider(int left, int right) {
	if (right == 0) {
		printf("Error : 나눗셈 입력 오류!!!\n");
		printf("        0 으로 나눌 수 없습니다.\n");
		return;
	}
	printf("%d / %d = %d, 나머지 : %d\n", left, right, left / right, left % right);
}