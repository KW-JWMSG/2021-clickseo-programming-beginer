#pragma warning(disable:4996)
#include <stdio.h>
#include <time.h>


int reculsivePB(int limit, int current, unsigned long long priv1, unsigned long long priv2);
void generalPB(int limit);

int main(void) {
	int limit;
	clock_t  rc_start, rc_end;
	clock_t  gn_start, gn_end;

	printf("### 피보나치 수열 ###\n\n");
	printf("몇 번재 수열까지 출력할까요 : ");
	scanf("%d", &limit);

	printf("\n### 재귀적 피보나치 수열 ###\n");
	rc_start = clock(); // Check start current Clock
	reculsivePB(limit,0, 0, 0);
	rc_end = clock(); // Check end current Clock
	printf(">>>>>> 총 %lf 초 소요\n", (double)(rc_end - rc_start) / CLOCKS_PER_SEC);
	printf(">>>>>> 총 %ld 클럭 소요\n", (rc_end - rc_start));

	printf("\n### 비재귀적 피보나치 수열 ###\n");
	gn_start = clock(); // Check start current Clock
	generalPB(limit);
	gn_end = clock(); // Check end current Clock
	printf(">>>>>> 총 %lf 초 소요\n", (double)(gn_end - gn_start) / CLOCKS_PER_SEC);
	printf(">>>>>> 총 %ld 클럭 소요\n", (gn_end - gn_start));

	/*
		생각보다 컴퓨터 성능이 좋아서
		1~2클럭 사이를 찍는다 (ㄹㅇ 별차이 없다)
		하지만, 디버그 모드로 여러차례 돌리다보면 클럭차이가 나는걸 확인 할 수 있다 (가끔 11클럭까지 올라감)
		초로보면 거의 0.001초 차이라서 (1000클럭당 1초임) 클럭으로 비교하는걸 추천,
	*/

	return 0;
}

int reculsivePB(int limit, int current, unsigned long long priv1, unsigned long long priv2) {
	/*
		추측이지만,
		함수 호출을 재귀적으로 하면,
		어셈블러상, 함수호출 로직이 계속 걸릴것이고,
		만약 이 함수에서 선언하는 변수나 파라미터들이 있으면, 걔들도 선언하고 초기화 해야 해서
		상대적으로 루프보단 느릴것으로 판단됨.
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
		참고,
		변수를 먼저 선언하고 루프 돌리면,
		루프돌릴때마다 변수 선언하는 로직을 줄여 성능에 향상을 줌.
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