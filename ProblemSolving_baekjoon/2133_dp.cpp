/*
	다이나믹 프로그래밍 타일링 문제
	백준 2133번 문제 
	https://www.acmicpc.net/problem/2133
	2×n 타일링
	시간제한 : 2 초
	메모리제한 : 128 MB
	
	문제
	3×N 크기의 벽을 2×1, 1×2 크기의 타일로 채우는 경우의 수를 구해보자.

	입력
	첫째 줄에 N(1 ≤ N ≤ 30)이 주어진다.
	
	출력
	첫째 줄에 경우의 수를 출력한다.

	예제입력	예제출력
	2			3


	가장 마지막에 오는 타일을 기준으로 생각했을 때 가능한 경우는 다음의 3가지 경우입니다. 
	또한 4부터는 2의 배수가 될 때마다 고유한 모양이 2개씩 나타납니다. 
	따라서 점화식은 다음과 같습니다.
	
	D[i] = 3 * D[i - 2] + (2 * D[i - 4] + 2 * D[i - 6] ... 2 * D[0])
	
	더불어 i가 홀수일 때는 0을 출력해줍니다. 
*/

#include <stdio.h>

int d[1001];

int dp(int x) {
	if(x == 0) return 1;
	if(x == 1) return 0;
	if(x == 2) return 3;
	if(d[x] != 0) return d[x];
	int result = 3 * dp(x - 2);
	for(int i = 3; i <= x; i++) {
		if(i % 2 == 0)
			result += 2 * dp(x - i);
	}
	return d[x] = result;
}

int main(void) {
	int x;
	scanf("%d", &x);
	printf("%d", dp(x));
}
