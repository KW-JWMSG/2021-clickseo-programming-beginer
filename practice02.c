#pragma warning(disable:4996)
#include <stdio.h>



int MAX(int, int, int, int);
int MIN(int, int, int, int);

int main(void) {

	int a,b,c,d;
	printf("4개의 정수 입력 : ");
	scanf("%d %d %d %d", &a, &b, &c, &d);

	printf("\n최대값 : %d\n", MAX(a, b, c, d));
	printf("최소값 : %d\n", MIN(a, b, c, d));
	return 0;
}


int MAX(int a, int b, int c, int d) {
	int bases[4] = { a,b,c,d };
	int result = bases[0];
	for (int i = 1; i < 4; i++) {
		if (result < bases[i]) {
			result = bases[i];
		}
	}
	return result;
}
int MIN(int a, int b, int c, int d) {
	int bases[4] = { a,b,c,d };
	int result = bases[0];
	for (int i = 1; i < 4; i++) {
		if (result > bases[i]) {
			result = bases[i];
		}
	}
	return result;
}