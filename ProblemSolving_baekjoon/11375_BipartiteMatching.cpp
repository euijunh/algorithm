/*
	이분 매칭 
	백준 11375번 문제 
	https://www.acmicpc.net/problem/11375
	열혈강호
	시간제한 : 2 초
	메모리제한 : 256 MB
	
	문제
	강호네 회사에는 직원이 N명이 있고, 해야할 일이 M개가 있다. 
	직원은 1번부터 N번까지 번호가 매겨져 있고, 
	일은 1번부터 M번까지 번호가 매겨져 있다.

	각 직원은 한 개의 일만 할 수 있고, 
	각각의 일을 담당하는 사람은 1명이어야 한다.
	
	각각의 직원이 할 수 있는 일의 목록이 주어졌을 때, 
	M개의 일 중에서 최대 몇 개를 할 수 있는지 
	구하는 프로그램을 작성하시오.

	입력
	첫째 줄에 직원의 수 N과 일의 개수 M이 주어진다. (1 ≤ N, M ≤ 1,000)

	둘째 줄부터 N개의 줄의 i번째 줄에는 i번 직원이 
	할 수 있는 일의 개수와 할 수 있는 일의 번호가 주어진다.
	
	출력
	첫째 줄에 강호네 회사에서 할 수 있는 일의 개수를 출력한다.

	예제입력		
	5 5
	2 1 2
	1 1
	2 2 3
	3 3 4 5
	1 1
	
	예제출력
	4
	 
	
*/
#include <iostream>
#include <vector>
#define MAX 1001

using namespace std;

vector<int> a[MAX];
int d[MAX];
bool c[MAX];
int n, m;

bool dfs(int x) { 
	for(int i = 0; i < a[x].size(); i++) {
		int t = a[x][i];
		if(c[t]) continue;
		c[t] = true;
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
		int k;
		scanf("%d", &k);
		for(int j = 1; j <= k; j++) {
			int t;
			scanf("%d", &t);
			a[i].push_back(t);
		}
	} 
	int count = 0;
	for(int i = 1; i <= n; i++) {
		fill(c, c + MAX, false);
		if(dfs(i)) count++;
	}
	cout << count << '\n';
	return 0;
}
