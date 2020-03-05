/*
	강한 결합 요소 
	백준 3977번 문제 
	https://www.acmicpc.net/problem/3977
	축구 전술
	시간제한 : 1 초 
	메모리제한 : 256  MB
	
	문제
	World Soccer Championship이 다가오고 있다! 
	천재적인 전술을 창조하는 플랜 아티스트 감독 도현이는 
	자신의 팀이 승리하도록 만반의 준비를 가하고 있다. 
	도현이의 전략은 경기장을 여러 개의 구역으로 나누고, 
	어떤 선수가 A구역에서 B구역으로 이동하게 하는 움직임을 (A, B)로 표현한다. 
	모든 도현이의 팀 선수들이 이 움직임만을 따라서 
	이동한다면 승리하리라고 도현이는 확신한다.

	도현이는 선수들에게 자신의 전술을 말해주며, 
	다른 모든 구역에 도달할 수 있는 시작 구역을 찾은 뒤 
	지시한 움직임만을 따라가라고 했다. 
	그러나 도현이는 한 가지 간과한 것이 있었는데 
	그건 선수들이 자신만큼 똑똑하지 않다는 것이다. 
	선수들은 그러한 시작 구역을 찾는 것이 어려웠다. 
	이제 당신이 적절한 시작 구역을 찾아줘야 한다.

	입력
	첫 번째 줄에 테스트 케이스의 개수가 주어지며, 
	이는 11보다 작거나 같은 정수이다.

	그 다음 줄부터 여러 개의 테스트 케이스가 주어지는데, 각 테스트 케이스마다 
	첫 번째 줄에 구역의 수 N, 지시한 움직임의 수 M이 주어지며 
	1 ≤ N, M ≤ 100,000 이다. 
	그 다음 M개의 줄에 걸쳐서 움직임 (A, B)가 주어지며, 
	A, B는 0 ≤ A, B < N인 정수이다.
	
	각 테스트 케이스는 하나의 빈 줄로 구분된다.
	
	출력 
	각 테스트 케이스마다 가능한 모든 시작 구역을 
	오름차순으로 한 줄에 하나씩 출력한다. 
	만약 그러한 시작 구역이 없으면, "Confused"를 출력한다.

	각 테스트 케이스의 끝에는 하나의 빈 줄을 출력한다.

	예제입력
	2
	4 4
	0 1
	1 2
	2 0
	2 3
	
	4 4
	0 3
	1 0
	2 0
	2 3
	
	예제출력
	0
	1
	2
	
	Confused
	
	축구 전술 문제는 하나의 강한 결합 요소에서 출발하여 
	모든 그래프를 방문할 수 있을 때에 한해서 출발 SCC의 모든 원소를 
	출력하는 문제입니다. 
	따라서 이 문제에서 반드시 정답이 존재한다고 가정했을 때 
	출발 SCC를 찾으려면 진입 차수가 0인 SCC를 찾으면 됩니다. 
	이 때 진입 차수가 0인 SCC가 여러 개이거나 존재하지 않는 경우 
	'정확한 답을 찾을 수 없다(Confused)'라고 출력하면 됩니다. 
	따라서 진입 차수가 0인 SCC가 오직 하나 존재할 때만 
	해당 SCC의 모든 원소를 출력하면 됩니다.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#define MAX 100001

using namespace std;

int n, m;
int id, d[MAX];
bool finished[MAX];
vector<int> a[MAX];
vector<vector<int> > SCC;
stack<int> s;
int group[MAX];
bool inDegree[MAX];
vector<int> result;

int dfs(int x) {
	d[x] = ++id;
	s.push(x);
	
	int parent = d[x];
	for(int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		if(d[y] == 0) parent = min(parent, dfs(y)); 
		else if(!finished[y]) parent = min(parent, d[y]); 
	}
	
	if(parent == d[x]) { 
		vector<int> scc;
		while(1){
			int t = s.top();
			s.pop();
			scc.push_back(t);
			group[t] = SCC.size() + 1;
			finished[t] = true;
			if(t == x) break;
		}
		SCC.push_back(scc);
	}
	
	return parent; 
} 

int main(void) {
	int t;
	scanf("%d", &t);
	while(t--) {
		SCC.clear();
		fill(d, d + MAX, 0);
		fill(finished, finished + MAX, 0);	
		fill(inDegree, inDegree + MAX, false);
		result.clear();
		scanf("%d %d", &n, &m);
		for(int i = 1; i <= n; i++) {
			a[i].clear();
		}
		for(int i = 0; i < m; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			a[x + 1].push_back(y + 1);
		}
		for(int i = 1; i <= n; i++) {
			if(d[i] == 0) dfs(i);
		}
		for(int i = 1; i <= n; i++) {
			for(int j = 0; j < a[i].size(); j++) {
				int y = a[i][j];
				if(group[i] != group[y])
					inDegree[group[y]] = true;
			}
		}
		int count = 0;
		for(int i = 0; i < SCC.size(); i++) {
			// 특정한 SCC의 진입차수가 없는 경우 
			if(!inDegree[i + 1]) {
				count++;
				for(int j = 0; j < SCC[i].size(); j++) {
					result.push_back(SCC[i][j] - 1);
				}
			}
		}
		sort(result.begin(), result.end());
		if(count != 1) {
			printf("Confused\n\n");
		} else {
			for(int i = 0; i < result.size(); i++) {
				printf("%d\n", result[i]);
			}
			printf("\n");
		}
	}
	return 0;
}
