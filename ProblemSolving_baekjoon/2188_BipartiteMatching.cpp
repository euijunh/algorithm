/*
	이분 매칭 
	백준 2188번 문제 
	https://www.acmicpc.net/problem/2188
	축사 배정
	시간제한 : 2 초
	메모리제한 : 128 MB
	
	문제
	농부 존은 소 축사를 완성하였다. 
	축사 환경을 쾌적하게 유지하기 위해서, 
	존은 축사를 N개의 칸으로 구분하고, 
	한 칸에는 최대 한 마리의 소만 들어가게 계획했다.
	
	첫 주에는 소를 임의 배정해서 축사를 운영했으나, 
	곧 문제가 발생하게 되었다. 
	바로 소가 자신이 희망하는 몇 개의 축사 외에는 
	들어가기를 거부하는 것이다.
	
	농부 존을 도와 최대한 많은 수의 소가 축사에 들어갈 수 
	있도록 하는 프로그램을 작성하시오. 
	축사의 번호는 1부터 M까지 매겨져 있다.

	입력
	첫째 줄에 소의 수 N과 축사의 수 M이 주어진다. (1 ≤ N, M ≤ 200)

	둘째 줄부터 N개의 줄에는 각 소가 들어가기 원하는 축사에 
	대한 정보가 주어진다. i번째 소가 들어가기 원하는 
	축사의 수 Si (0 ≤ Si ≤ M)이 먼저 주어지고, 
	이후 Si개의 축사 번호가 주어진다. 
	같은 축사 번호가 두 번 이상 주어지는 경우는 없다.
	
	출력
	첫째 줄에 축사에 들어갈 수 있는 소의 최댓값을 출력한다.

	예제입력		
	5 5
	2 2 5
	3 2 3 4
	2 1 5
	3 1 2 5
	1 2
	
	예제출력
	4
	 
	
*/
#include <iostream>
#include <vector>
#define MAX 201

using namespace std;

vector<int> a[MAX];
int d[MAX];
bool c[MAX];
int n, m, s;

// 매칭에 성공한 경우 True, 실패한 경우 False 
bool dfs(int x) {
	// 연결된 모든 노드에 대해서 들어갈 수 있는지 시도 
	for(int i = 0; i < a[x].size(); i++) {
		int t = a[x][i];
		// 이미 처리한 노드는 더 이상 볼 필요가 없음 
		if(c[t]) continue;
		c[t] = true;
		// 비어있거나 점유 노드에 더 들어갈 공간이 있는 경우 
		if(d[t] == 0 || dfs(d[t])) {
			d[t] = x;
			return true;
		}
	}
	return false;
}

int main(void) {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &s);
		for(int j = 1; j <= s; j++) {
			int t;
			scanf("%d", &t);
			a[i].push_back(t);
		}
	}
	int count = 0;
	for(int i = 1; i <= n; i++) { // 최대한 우겨 넣습니다. 
		fill(c, c + MAX, false);
		if(dfs(i)) count++;
	}
	printf("%d\n", count);
	return 0;
}
