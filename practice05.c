#pragma warning(disable:4996)
#include <stdio.h>


void devider(int, int);


int main(void) {

	int left, right;
	printf("�� ���� �Է� : ");
	scanf("%d %d", &left, &right);
	devider(left, right);
	return 0;
}

void devider(int left, int right) {
	if (right == 0) {
		printf("Error : ������ �Է� ����!!!\n");
		printf("        0 ���� ���� �� �����ϴ�.\n");
		return;
	}
	printf("%d / %d = %d, ������ : %d\n", left, right, left / right, left % right);
}