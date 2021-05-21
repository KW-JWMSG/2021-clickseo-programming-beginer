#pragma warning(disable:4996)
#include <stdio.h>
#include <time.h>


int reculsivePB(int limit, int current, unsigned long long priv1, unsigned long long priv2);
void generalPB(int limit);

int main(void) {
	int limit;
	clock_t  rc_start, rc_end;
	clock_t  gn_start, gn_end;

	printf("### �Ǻ���ġ ���� ###\n\n");
	printf("�� ���� �������� ����ұ�� : ");
	scanf("%d", &limit);

	printf("\n### ����� �Ǻ���ġ ���� ###\n");
	rc_start = clock(); // Check start current Clock
	reculsivePB(limit,0, 0, 0);
	rc_end = clock(); // Check end current Clock
	printf(">>>>>> �� %lf �� �ҿ�\n", (double)(rc_end - rc_start) / CLOCKS_PER_SEC);
	printf(">>>>>> �� %ld Ŭ�� �ҿ�\n", (rc_end - rc_start));

	printf("\n### ������� �Ǻ���ġ ���� ###\n");
	gn_start = clock(); // Check start current Clock
	generalPB(limit);
	gn_end = clock(); // Check end current Clock
	printf(">>>>>> �� %lf �� �ҿ�\n", (double)(gn_end - gn_start) / CLOCKS_PER_SEC);
	printf(">>>>>> �� %ld Ŭ�� �ҿ�\n", (gn_end - gn_start));

	/*
		�������� ��ǻ�� ������ ���Ƽ�
		1~2Ŭ�� ���̸� ��´� (���� ������ ����)
		������, ����� ���� �������� �����ٺ��� Ŭ�����̰� ���°� Ȯ�� �� �� �ִ� (���� 11Ŭ������ �ö�)
		�ʷκ��� ���� 0.001�� ���̶� (1000Ŭ���� 1����) Ŭ������ ���ϴ°� ��õ,
	*/

	return 0;
}

int reculsivePB(int limit, int current, unsigned long long priv1, unsigned long long priv2) {
	/*
		����������,
		�Լ� ȣ���� ��������� �ϸ�,
		�������, �Լ�ȣ�� ������ ��� �ɸ����̰�,
		���� �� �Լ����� �����ϴ� ������ �Ķ���͵��� ������, �µ鵵 �����ϰ� �ʱ�ȭ �ؾ� �ؼ�
		��������� �������� ���������� �Ǵܵ�.
	*/
	if (current >= limit) return;
	unsigned long long  new_current = priv1 + priv2;
	if (new_current == 0) new_current++;
	printf("%8d", new_current);
	if (((current+1) % 5 )== 0) printf("\n");
	priv1 = priv2;
	priv2 = new_current;
	reculsivePB(limit,++current, priv1, priv2);
	
}
void generalPB(int limit) {
	/*
		����,
		������ ���� �����ϰ� ���� ������,
		�������������� ���� �����ϴ� ������ �ٿ� ���ɿ� ����� ��.
	*/

	unsigned long long priv1 = 0;
	unsigned long long priv2 = 0;
	unsigned long long  new_current = 0;

	for (int i = 0; i < limit; i++) {
		new_current = priv1 + priv2;
		if (new_current == 0) new_current++;
		printf("%8d", new_current);
		if (((i + 1) % 5) == 0) printf("\n");
		priv1 = priv2;
		priv2 = new_current;
	}
}