/*
	다이나믹 프로그래밍 타일링 문제
	백준 11727번 문제 
	https://www.acmicpc.net/problem/11727
	2×n 타일링
	시간제한 : 1 초
	메모리제한 : 256 MB
	
	문제
	2×n 직사각형을 2×1과 2×2 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.

	입력
	첫째 줄에 n이 주어진다. (1 ≤ n ≤ 1,000)
	
	출력
	첫째 줄에 2×n 크기의 직사각형을 채우는 방법의 수를 10,007로 나눈 나머지를 출력한다.

	예제입력	예제출력
	2			3
	8			171
	12			2731


	가장 마지막에 오는 타일을 기준으로 생각했을 때 가능한 경우는 다음의 세 가지 경우입니다.

	D[i] = D[i - 1] + 2 * D[i - 2]
*/

#include <stdio.h>

int d[1001];

int dp(int x) {
	if(x == 1) return 1;
	if(x == 2) return 3;
	if(d[x] != 0) return d[x];
	return d[x] = (dp(x - 1) + 2 * dp(x - 2)) % 10007;
}

int main(void) {
	int x;
	scanf("%d", &x);
	printf("%d", dp(x));
}
