/*
	위상 정렬 
	백준 2252번 문제 
	https://www.acmicpc.net/problem/2252
	줄세우기 
	시간제한 : 2 초
	메모리제한 : 128 MB
	
	문제
	N명의 학생들을 키 순서대로 줄을 세우려고 한다. 
	각 학생의 키를 직접 재서 정렬하면 간단하겠지만, 마땅한 방법이 없어서 
	두 학생의 키를 비교하는 방법을 사용하기로 하였다. 
	그나마도 모든 학생들을 다 비교해 본 것이 아니고, 
	일부 학생들의 키만을 비교해 보았다.

	일부 학생들의 키를 비교한 결과가 주어졌을 때, 
	줄을 세우는 프로그램을 작성하시오.

	입력
	첫째 줄에 N(1≤N≤32,000), M(1≤M≤100,000)이 주어진다. 
	M은 키를 비교한 회수이다. 
	다음 M개의 줄에는 키를 비교한 두 학생의 번호 A, B가 주어진다. 
	이는 학생 A가 학생 B의 앞에 서야 한다는 의미이다.

	학생들의 번호는 1번부터 N번이다.
	
	출력
	첫째 줄부터 앞에서부터 줄을 세운 결과를 출력한다. 
	답이 여러 가지인 경우에는 아무거나 출력한다.

	예제입력	예제출력
	3 2			1 2 3
	1 3
	2 3
	 1, 2는 진입차수가 0, 3은 진입차수가 2 
	
	예제입력	예제출력
	4 2			4 2 3 1
	4 2
	3 1
*/

#include <iostream>
#include <vector>
#include <queue>
#define MAX 32001

using namespace std;

int n, inDegree[MAX], result[MAX];
/*
	int n : 학생수, 
	int inDegree[MAX] : 차수기록, 
	int result[MAX] : 결과값 
*/
vector<int> a[MAX];

void topologySort() {
	queue<int> q;
	// 진입 차수가 0인 노드를 큐에 삽입합니다. 
	for(int i = 1; i <= n; i++) {
		if(inDegree[i] == 0) {
			q.push(i);
		}
	}
	// 정렬이 완전히 수행되려면 정확히 n개의 노드를 방문합니다. 
	for(int i = 1; i <= n; i++) {
		int x = q.front();
		q.pop();
		result[i] = x;
		for(int j = 0; j < a[x].size(); j++) {
			int y = a[x][j];
			// 새롭게 진입차수가 0이 된 정점을 큐에 삽입합니다. 
			if(--inDegree[y] == 0)
				q.push(y);
		}
	}
	for(int i = 1; i <= n; i++) {
		printf("%d ", result[i]);
	}
}


int main(void) {
	int m; // 학생키를 비교한 횟수 
	scanf("%d %d",&n,&m);
	for(int i=0; i<m; i++)
	{
		int x,y;
		scanf("%d %d", &x, &y);
		a[x].push_back(y);
		inDegree[y]++;
	}   
	topologySort();
}
