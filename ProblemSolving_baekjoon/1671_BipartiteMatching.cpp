/*
	이분 매칭 
	백준 1671번 문제 
	https://www.acmicpc.net/problem/1671
	상어의 저녁식사
	시간제한 : 2 초 
	메모리제한 : 128 MB
	
	문제
	어떤 상어는 저녁식사로 서로를 먹는다. 
	모든 상어는 자신과 다른 상어의 크기, 속도, 지능을 
	수치로 나타낸 것을 알고 있다. 
	만약, 상어 A의 크기, 속도, 지능이 상어 B의 크기, 속도, 지능보다 
	크거나 같다면 상어 A는 상어 B를 먹을 수 있다. 
	그러나, 상어들의 왕 김재홍은 상어들이 많이 없어지는 것을 
	방지하기 위해서 한 상어가 최대 두 개의 상어만 먹을 수 있게 했다. 
	상어들은 김재홍의 말을 모두 듣는다.

	N마리 상어의 크기, 속도, 지능이 주어졌을 때, 살아남을 수 있는 상어의 최솟값을 구하시오.

	입력
	첫째 줄에 상어의 마리 수 N이 주어진다. 
	이 값은 50보다 작거나 같은 자연수이다. 
	둘째 줄부터 각 상어의 크기, 속도, 지능의 정보가 주어진다. 
	이 값은 2,000,000,000보다 작거나 같은 자연수이다.
	
	출력
	첫째 줄에 살아남을 수 있는 상어의 최솟값을 출력한다.
	
	예제입력		
	5
	4 5 5
	10 10 8
	5 7 10
	8 7 7
	8 10 3
	
	예제출력
	2

	이 문제도 단순히 2번씩 매칭을 수행해주면 되는 간단한 문제입니다. 
	다만 문제에서는 상어들의 능력 수치에 따라서 매칭을 시켜주라고 
	지시하고 있으므로 능력 수치를 비교하는 부분만 신경써서 
	작성해주면 정답 처리를 받을 수 있습니다.
*/

#include <iostream>
#include <vector>
#define MAX 51

using namespace std;

vector<int> a[MAX];
int stat[MAX][3]; // 상어들의 크기, 속도, 지능 정보 
int d[51];
int c[51];
int n;

bool dfs(int x) {
	// 특정한 상어에 연결되어 있는 모든 상어들의 정보를 확인 
	// 자기보다 스탯이 낮은 상어들이 표적이 된다. 
	for(int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		if(c[y]) continue; // 해당 상어를 살펴보았다면 넘어간다. 
		c[y] = true;
		// 현재 잡아먹으려는 상어가 다른 상어에게 점유당하지 않았거나
		// 다른 상어가 점유하고 있되 점유하고 있는 그 상어가 또 다른 상어를 먹는식으로 
		if(d[y] == 0 || dfs(d[y])) {
			d[y] = x;
			return true;
		}
	}
	return false;
}

int main(void) {
	scanf("%d", &n); // 상어의 마리수 
	for(int i = 1; i <= n; i++) {
		int a, b, c;
		//  크기, 속도, 지능 입력 
		scanf("%d %d %d", &stat[i][0], &stat[i][1], &stat[i][2]);
	}
	for(int i = 1; i <= n - 1; i++) {
		for(int j = i + 1; j <= n; j++) {
			if(stat[i][0] == stat[j][0] && stat[i][1] == stat[j][1] && stat[i][2] == stat[j][2]) {
				// 스탯이 모두 동일한 경우 
				a[i].push_back(j);
			} else if(stat[i][0] >= stat[j][0] && stat[i][1] >= stat[j][1] && stat[i][2] >= stat[j][2]) {
				// 스탯이 더 강한 경우 
				a[i].push_back(j);
			} else if(stat[i][0] <= stat[j][0] && stat[i][1] <= stat[j][1] && stat[i][2] <= stat[j][2]) {
				// 스탯이 더 약한 경우 
				a[j].push_back(i);
			}
		}
	}
	int count = 0;
	// 한 상어가 최대 두개의 상어까지만 먹을 수 있다. 
	for(int k = 0; k < 2; k++) {
		for(int i = 1; i <= n; i++) {
			fill(c, c + MAX, false);
			if(dfs(i)) count++;
		}
	}
	// 남아있는 상어의 개수 출력 - 전체 상어개수 - 잡아먹힐 상어들의 개수 
	printf("%d\n", n - count);
	return 0;
}
