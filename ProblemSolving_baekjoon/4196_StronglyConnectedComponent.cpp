/*
	강한 결합 요소 
	백준 4196번 문제 
	https://www.acmicpc.net/problem/4196
	도미노
	시간제한 : 1 초 
	메모리제한 : 256  MB
	
	문제
	도미노는 재밌다. 
	도미노 블록을 일렬로 길게 늘어세운 뒤 블록 하나를 넘어뜨리면 
	그 블록이 넘어지며 다음 블록을 넘어뜨리는 일이 반복되어 
	일렬로 늘어선 블록들을 연쇄적으로 모두 쓰러뜨릴 수 있다. 
	그러나, 가끔씩 도미노가 다른 블록을 넘어뜨리지 못하게 배치되어 있다면, 
	우리는 다음 블록을 수동으로 넘어뜨려야 한다.

	이제 각 도미노 블록의 배치가 주어졌을 때, 
	모든 블록을 넘어뜨리기 위해 손으로 넘어뜨려야 하는 블록 개수의 최솟값을 구하자.

	입력
	첫 번째 줄에 테스트 케이스의 개수가 주어진다.

	각 테스트 케이스의 첫 번째 줄에는 두 정수 N, M이 주어지며 
	두 수는 100,000을 넘지 않는다. N은 도미노의 개수를, M은 관계의 개수를 나타낸다. 
	도미노 블록의 번호는 1과 N 사이의 정수다. 
	다음 M개의 줄에는 각각 두 정수 x, y가 주어지는데, 
	이는 x번 블록이 넘어지면 y번 블록도 넘어짐을 뜻한다.
	
	출력
	각 테스트 케이스마다 한 줄에 정수 하나를 출력한다. 
	정답은 손으로 넘어뜨려야 하는 최소의 도미노 블록 개수이다.

	예제입력
	1
	3 2
	1 2
	2 3
	
	예제출력
	1
	
	이 문제는 단순히 강한 결합 요소만을 구하는 문제가 아니라 
	강한 결합 요소 사이의 관계까지도 구해야 하는 문제입니다. 
	강한 결합 요소끼리는 일방향적으로 연결되어 있다는 점에서 
	위상 정렬을 수행할 수 있습니다. 
	도미노는 강한 결합 요소를 정점으로 보고 위상 정렬을 수행했을 때 
	진입 차수(Indegree)가 0인 정점의 갯수를 세면 되는 문제입니다.

	따라서 모든 강한 결합 요소에 대해서 각각 고유한 번호 값을 매겨 
	그룹을 만든 뒤에, 각각의 그룹을 하나의 정점으로 보고 단순하게 
	진입 차수의 갯수만 세주면 됩니다. 
	이후에 각 그룹에 대해 진입 차수의 갯수가 0인 경우에만 
	카운트를 해주어서 결과적으로 최종 카운트를 출력하면 됩니다.
*/

#include <iostream>
#include <vector>
#include <stack>
#define MAX 100001

using namespace std;

int n, m;
int id, d[MAX]; // d[MAX] : 각 노드마다 고유한 번호 할당 
bool finished[MAX]; // 처리된 노드를 담는다 
vector<int> a[MAX]; // 정점에 인접한 노드를 담는다. 
vector<vector<int> > SCC;
stack<int> s;
int group[MAX]; // 각 정점들이 어떤 그룸에 속하는지 기록 
bool inDegree[MAX]; // 각 SCC의 진입차수 기록 

int dfs(int x) {
	d[x] = ++id; // 1번부터 차례로 정점의 번호지정 
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
			// 첫번째 SCC에 속한 정점들은 1, 두번째는 2 .... 
			group[t] = SCC.size() + 1;
			finished[t] = true;
			if(t == x) break;
		}
		SCC.push_back(scc);
	}
	
	return parent; 
} 

int main(void) {
	// 테스트 케이스 개수 입력 
	int t;
	scanf("%d", &t);
	// 테스트 케이스 개수만큼 반복 
	while(t--) {
		SCC.clear();
		fill(d, d + MAX, 0);
		fill(finished, finished + MAX, 0);	
		fill(inDegree, inDegree + MAX, false);
		scanf("%d %d", &n, &m); // 도미노의 개수, 관계의 개수 
		for(int i = 1; i <= n; i++) {
			a[i].clear();
		}
		for(int i = 0; i < m; i++) {
			int x, y;
			// x가 무너지면 y도 무너진다. 
			scanf("%d %d", &x, &y);
			a[x].push_back(y);
		}
		for(int i = 1; i <= n; i++) {
			if(d[i] == 0) dfs(i);
		}
		// 도미노의 개수만큼 반복 
		for(int i = 1; i <= n; i++) {
			for(int j = 0; j < a[i].size(); j++) {
				int y = a[i][j];
				// 진입차수가 존대할 경우 
				if(group[i] != group[y])
					inDegree[group[y]] = true;
			}
		}
		int result = 0;
		// 진입차수가 false인 inDegree 개수 구하기 
		for(int i = 1; i <= SCC.size(); i++) {
			if(!inDegree[i]) result++;
		}
		printf("%d\n", result);
	}
	return 0;
}
