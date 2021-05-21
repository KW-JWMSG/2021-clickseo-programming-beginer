#pragma warning(disable:4996)
#include <stdio.h>



int operatorSelector(int, char, int);
int adder(int, int);
int subtrater(int, int);
int multiplier(int, int);
int divider(int, int);

int main(void) {

	char oper;
	int left, right;
	printf("수식입력(예: 10 + 20) : ");
	scanf("%d %c %d", &left, &oper, &right);
	operatorSelector(left, oper, right);
	return 0;
}

int operatorSelector(int left, char oper, int right) {
	switch (oper)
	{
	case '+':
		return adder(left, right);
	case '-':
		return subtrater(left, right);
	case '/':
		return divider(left, right);
	case '*':
		return multiplier(left, right);
	default:
		printf("존재하지 않는 연산자 입니다.\n");
		break;
	}
}

int adder(int left, int right) {
	printf("%d + %d = %d\n", left, right, left + right);
	return left + right;
}

int subtrater(int left, int right) {
	printf("%d - %d = %d\n", left, right, left - right);
	return left + right;
}
int multiplier(int left, int right) {
	printf("%d * %d = %d\n", left, right, left * right);
	return left + right;
}
int divider(int left, int right) {
	if (right == 0) {
		printf("Error : 나눗셈 입력 오류!!!\n");
		return 0;
	}
	printf("%d / %d = %d\n", left, right, left / right);
	return left + right;
}