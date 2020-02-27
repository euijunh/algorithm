/*
	이분 매칭 
	백준 11377번 문제 
	https://www.acmicpc.net/problem/11377
	열혈강호 3
	시간제한 : 3 초 
	메모리제한 : 256 MB
	
	문제
	강호네 회사에는 직원이 N명이 있고, 해야할 일이 M개가 있다. 
	직원은 1번부터 N번까지 번호가 매겨져 있고, 
	일은 1번부터 M번까지 번호가 매겨져 있다.

	각 직원은 한 개의 일만 할 수 있고, 
	각각의 일을 담당하는 사람은 1명이어야 한다. 
	단, N명 중에서 K명은 일을 최대 2개할 수 있다.
	
	각각의 직원이 할 수 있는 일의 목록이 주어졌을 때, 
	M개의 일 중에서 최대 몇 개를 할 수 있는지 구하는 프로그램을 작성하시오.

	입력
	첫째 줄에 직원의 수 N과 일의 개수 M, 
	일을 2개할 수 있는 직원의 수 K가 주어진다. 
	(1 ≤ N, M ≤ 1,000, 1 ≤ K ≤ N)

	둘째 줄부터 N개의 줄의 i번째 줄에는 i번 직원이 할 수 있는 일의 
	개수와 할 수 있는 일의 번호가 주어진다.
	
	출력
	첫째 줄에 강호네 회사에서 할 수 있는 일의 개수를 출력한다.
	
	예제입력		
	5 5 1
	3 1 2 3
	3 1 2 3
	1 5
	1 5
	1 5
	
	예제출력
	4

	이 문제는 특정한 직원에 한해서만 2번씩 일을 할 수 있도록 매칭하는 문제입니다. 
	따라서 모든 직원에 대해 1번씩 매칭을 해주고, 나머지 특정한 직원의 숫자 만큼만 추가적으로 
	한 번씩 더 매칭을 수행시켜주면 됩니다.
*/

#include <iostream>
#include <vector>
#define MAX 1001

using namespace std;

vector<int> a[MAX];
int d[MAX];
bool c[MAX];
int n, m, k, s;

bool dfs(int x) {
	for(int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		if(c[y]) continue;
		c[y] = true;
		if(d[y] == 0 || dfs(d[y])) {
			d[y] = x;
			return true; 
		}
	}
	return false;
}

int main(void) {
	// n = 직원수, m = 해야할 일, k = 일을 2번할 수 있는 직원수 
	cin >> n >> m >> k;
	// 둘째 줄부터 N개의 줄의 i번째 줄에는 i번 직원이 할 수 있는 일의 개수와 할 수 있는 일의 번호가 주어진다.
	for(int i = 1; i <= n; i++) {
		cin >> s; // 할 수 있는 일의 개수 
		for(int j = 1; j <= s; j++) {
			// 할 수 있는 일의 개수만큼 일의 번호 입력받기 
			int t;
			cin >> t;
			a[i].push_back(t);
		}
	} 
	int count = 0;
	// 일단 한번씩 매칭을 시켜준다. 
	for(int i = 1; i <= n; i++) {
        fill(c, c + MAX, false);
		if (dfs(i)) count++;
	}
    // 2번씩 작업 할 수 있는 사람을 추가적으로 계산합니다.
	int extra = 0;
	for(int i = 1; i <= n && extra < k; i++) {
        fill(c, c + MAX, false);
		if (dfs(i)) extra++;
	}
	cout << count + extra << '\n';
	return 0;
}
