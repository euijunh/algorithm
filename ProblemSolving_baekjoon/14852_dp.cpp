/*
	다이나믹 프로그래밍 타일링 문제
	백준 14852번 문제 
	https://www.acmicpc.net/problem/14852
	타일 채우기 3
	시간제한 : 2 초
	메모리제한 : 512 MB
	
	문제
	2×N 크기의 벽을 2×1, 1×2, 1×1 크기의 타일로 채우는 경우의 수를 구해보자.

	입력
	첫째 줄에 N(1 ≤ N ≤ 1,000,000)이 주어진다.
	
	출력
	첫째 줄에 경우의 수를 1,000,000,007로 나눈 나머지를 출력한다.

	예제입력	예제출력
	1			2
	2			7
	3			22


	가장 마지막에 오는 타일을 기준으로 생각했을 때 가능한 경우는 다음의 5가지 경우입니다. 
	또한 3부터 하나씩 증가할 때마다 고유한 모양이 2개씩 나타납니다. 
	따라서 점화식은 다음과 같습니다.
	
	D[i] = 3 * D[i - 2] + 2 * D[i - 1] + (2 * D[i - 3] + 2 * D[i - 4] ... 2 * D[0])

#include <stdio.h>

int d[1000001];
	
long long int dp(int d[], int x) {
	if(x == 0) return 1;
	if(x == 1) return 2;
	if(x == 2) return 7;
	if(d[x] > 0) return d[x];
	long long int result = 3 * dp(d, x - 2) + 2 * dp(d, x - 1);
	for(int i = 3; i <= x; i++) {
		result += (2 * dp(d, x - i)) % 100000007;
	}
	return d[x] = result % 100000007;
}

int main(void)
{
	int x;
	scanf("%d", &x);
	printf("%d", dp(d, x));
	return 0;
}

	이 경우 시간 복잡도가 사실상 O(N^2)이 나온다는 점에서 시간 초과가 발생합니다. 
	따라서 2차원 다이나믹 프로그래밍 기법을 사용하여 다음과 같이 해결해야 합니다.
*/

#include <stdio.h>

long long int d[1000001][2];

long long int dp(int x) {
	d[0][0] = 0;
	d[1][0] = 2;
	d[2][0] = 7;
	d[2][1] = 1;
	for(int i = 3; i <= x; i++) {
		d[i][1] = (d[i - 1][1] + d[i - 3][0]) % 1000000007;
		d[i][0] = (3 * d[i - 2][0] + 2 * d[i - 1][0] + 2 * d[i][1]) % 1000000007;
	}
	return d[x][0];
}

int main(void)
{
	int x;
	scanf("%d", &x);
	printf("%lld", dp(x));
	return 0;
}

/*
	위와 같이 해결하면 시간 복잡도 O(N) 가량으로 풀게 되어 즉시 해결됩니다. 
	2씩 더해지는 부분을 처리하기 위해 배열에 별도의 행을 만들어 처리해줍니다. 
*/
