/*
	다익스트라(Dijkstra) 알고리즘
	
	다익스트라(Dijkstra) 알고리즘은 다이나믹 프로그래밍을 활용한 대표적인 
	최단 경로(Shortest Path) 탐색 알고리즘입니다. 
	흔히 인공위성 GPS 소프트웨어 등에서 가장 많이 사용됩니다. 
	다익스트라 알고리즘은 특정한 하나의 정점에서 다른 모든 정점으로 
	가는 최단 경로를 알려줍니다. 다만 이 떄 음의 간선을 포함할 수 없습니다. 
	물론 현실 세계에서는 음의 간선이 존재하지 않기 때문에 다익스트라는 
	현실 세계에 사용하기 매우 적합한 알고리즘 중 하나라고 할 수 있습니다.

	다익스트라 알고리즘이 다이나믹 프로그래밍 문제인 이유는 
	'최단 거리는 여러 개의 최단 거리로 이루어져있기 때문입니다.' 
	작은 문제가 큰 문제의 부분 집합에 속해있다고 볼 수 있습니다. 
	기본적으로 다익스트라는 하나의 최단 거리를 구할 때 그 이전까지 구했던 
	최단 거리 정보를 그대로 사용한다는 특징이 있습니다. 

	다익스트라 알고리즘은 
	'현재까지 알고 있던 최단 경로를 계속해서 갱신'합니다.

	구체적인 작동 과정은 다음과 같습니다.
	
	1. 출발 노드를 설정합니다.
	2. 출발 노드를 기준으로 각 노드의 최소 비용을 저장합니다.
	3. 방문하지 않은 노드 중에서 가장 비용이 적은 노드를 선택합니다.
	4. 해당 노드를 거쳐서 특정한 노드로 가는 경우를 고려하여 최소 비용을 갱신합니다.
	5. 위 과정에서 3번 ~ 4번을 반복합니다.

	바로 실제 예시를 통해 확인해봅시다.
	그래프는 실제로 컴퓨터 안에서 처리할 때 
	이차원 배열 형태로 처리해야 합니다. 
	바로 다음과 같이 해줍니다. 
	아래 표의 의미는 특정 행에서 열로 가는 비용입니다. 
	보시면 1행 3열의 값이 5입니다. 
	이것은 1번 노드에서 3번 노드로 가는 비용이 5라는 겁니다.
  
	0	2	5	1	무한	무한
	2	0	3	2	무한	무한
	5	3	0	3	1	5
	1	2	3	0	1	무한
	무한	무한	5
	1	0	2
	무한	무한	5	무한	2	0
	
	즉 이 상태에서 1번 노드를 선택해봅시다.
	
	위와 같이 노드 1을 선택한 상태고, 그와 연결된 세 개의 간선을 확인한 
	상태라고 할 수 있습니다.1번 노드에서 다른 정점으로 가는 최소 비용은 
	다음과 같습니다. 배열을 만든 뒤에는 이 최소 비용 배열을 
	계속해서 갱신할 것입니다. 현재 방문하지 않은 
	노드 중에서 가장 비용이 적은 노드는 4번 노드입니다. 
	
	0	2	5	1	무한	무한
	
	따라서 위 배열의 상태를 고려하여 4번 노드가 선택되었습니다. 
	4번 노드를 거쳐서 가는 경우를 모두 고려하여 최소 비용 배열을 갱신하면 됩니다.

	보면 기존에 5로 가는 최소 비용은 무한이었습니다. 
	하지만 4를 거쳐서 5로 가는 경우는 비용이 2이므로 
	최소 비용 배열을 갱신해줍니다.  또한 4를 거쳐서 3으로 
	가는 경우는 비용이 4이므로 기존보다 더 저렴합니다. 
	따라서 최소 비용 배열을 갱신해줍니다. 결과적으로 아래와 같습니다.
	
	0	2	4	1	2	무한
	
	이제 다음으로 방문하지 않은 노드 중에서 가장 비용이 적은 노드는 2번 노드입니다.

	보면 2를 거쳐서 가더라도 비용이 갱신되는 경우가 없습니다. 
	따라서 배열은 그대로 유지합니다.

	0	2	4	1	2	무한
	
	다음으로 방문하지 않은 노드 중에서 가장 비용이 적은 노드는 5번째 노드입니다.

	위와 같이 5를 거쳐서 3으로 가는 경우 경로의 비용이 3이므로 
	기존의 4보다 더 저렴합니다. 따라서 노드 3으로 가는 비용을 
	3으로 바꾸어주시면 됩니다. 또한 5를 거쳐서 6으로 가는 경우 
	경로의 비용이 4로 기존의 무한보다 더 저렴합니다. 
	따라서 노드 6으로 가는 비용을 4로 바꾸어주시면 됩니다.

	0	2	3	1	2	4
	
	이후에 방문하지 않은 노드 중에서 가장 저렴한 노드 3을 방문합니다.

	최소 비용 갱신은 일어나지 않습니다.
	
	0	2	3	1	2	4
	
	이제 마지막으로 남은 노드 6을 살펴봅시다.

	노드 6을 방문한 뒤에도 결과는 같습니다. 따라서 최종 배열은 다음과 같이 형성됩니다.
	
	0	2	3	1	2	4
	
	다익스트라 알고리즘은 동적 프로그래밍을 적용했다는 점에서 소스코드가 짧고 간결합니다.


#include <stdio.h>

int number = 6; // 정점의 개수 
int INF = 10000000; // 무한대, int형은 약 21억의 양수의 값을 가질 수 있다. 

// 전체 그래프를 초기화합니다. 
int a[6][6] = {
//	 1	2  3  4  5	  6
	{0, 2, 5, 1, INF, INF},
	{2, 0, 3, 2, INF, INF},
	{5, 3, 0, 3, 1, 5},
	{1, 2, 3, 0, 1, INF},
	{INF, INF, 1, 1, 0, 2},
	{INF, INF, 5, INF, 2, 0},
};
bool v[6]; // 방문한 노드입니다. 
int d[6]; // 거리입니다. 

// 가장 최소 거리를 가지는 정점을 반환합니다.
int getSmallIndex() {
	int min = INF;
	int index = 0;
	for(int i = 0; i < number; i++) {
		if(d[i] < min && !v[i]) {
			min = d[i];
			index = i;
		}
	}
	return index;
} 

void dijkstra(int start) {
	for(int i = 0; i < number; i++) {
		d[i] = a[start][i];
	}
	v[start] = true;
	for(int i = 0; i < number - 2; i++) { // -2는 맨앞과 맨뒤를 빼준다. 
		int current = getSmallIndex(); // 최소 거리가 있는 인덱스 
		v[current] = true; // 노드 방문처리 
		for(int j = 0; j < 6; j++) { // 인접한 모든 노드확인 
			// 방문하지 않은 노드라면 
			if(!v[j]) {
				// d[current] -> 현재 보고있는 노드까지의 최소비용,  
				// a[current][j] -> 그 노드를 거쳐서 그 노드에 인접한 노드로 가는 비용 
				// d[j] -> 현재 그 인접한 노드로 가는 최소 비용 
				if(d[current] + a[current][j] < d[j]) {
					d[j] = d[current] + a[current][j];
				}
			}
		}
	}
}

int main(void) {
	dijkstra(0);
	for(int i = 0; i < number; i++) {
		printf("%d ", d[i]);
	}
}


	다만 위 알고리즘은 최소 비용을 단순히 선형 탐색으로 찾도록 만들었습니다. 
	이렇게 작성하는 경우 다익스트라의 시간 복잡도가 O(N^2)으로 형성됩니다. 
	따라서 최대한 빠르게 작동시켜야 하는 경우 힙 구조를 활용하여 
	시간 복잡도 O(N * log N)을 만들 수 있습니다. 
	특히 위와 같은 소스코드는 정점의 갯수가 많은데 간선은 
	적을 때 치명적일 정도로 비효율적으로 작동할 수 있습니다.
	
	위 소스코드는 인접 리스트 방식을 활용하여 시간 복잡도 O(N * log N)으로 
	구현한 것입니다. 이 경우 정점에 비해 간선의 갯수가 비정상적으로 
	적어도 안정적으로 처리할 수 있습니다.
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int number = 6;
int INF = 10000000;

vector<pair<int, int> > a[7]; // 간선 정보입니다. 
int d[7]; // 최소 비용입니다. 

void dijkstra(int start) {
	d[start] = 0;
	priority_queue<pair<int, int> > pq; // 힙 구조입니다. 
	pq.push(make_pair(start, 0));
	// 가까운 순서대로 처리하므로 큐를 사용합니다.
	while(!pq.empty()) {
		int current = pq.top().first;
		// 짧은 것이 먼저 오도록 음수화(-)합니다. 
		int distance = -pq.top().second;
		pq.pop();
		// 최단 거리가 아닌 경우 스킵합니다. 
		if(d[current] < distance) continue;
		for(int i = 0; i < a[current].size(); i++) {
			// 선택된 노드의 인접 노드 
			int next = a[current][i].first; 
			// 선택된 노드를 인접 노드로 거쳐서 가는 비용 
			int nextDistance = distance + a[current][i].second;
			// 기존의 최소 비용보다 더 저렴하다면 교체합니다. 
			if(nextDistance < d[next]) {
				d[next] = nextDistance;
				pq.push(make_pair(next, -nextDistance));
			}
		}
	}
}

int main(void) {
	// 기본적으로 연결되지 않은 경우 비용은 무한입니다. 
	for(int i = 1; i <= number; i++) {
		d[i] = INF;
	}
	
	a[1].push_back(make_pair(2, 2));
	a[1].push_back(make_pair(3, 5));
	a[1].push_back(make_pair(4, 1));
	
	a[2].push_back(make_pair(1, 2));
	a[2].push_back(make_pair(3, 3));
	a[2].push_back(make_pair(4, 2));
	
	a[3].push_back(make_pair(1, 5));
	a[3].push_back(make_pair(2, 3));
	a[3].push_back(make_pair(4, 3));
	a[3].push_back(make_pair(5, 1));
	a[3].push_back(make_pair(6, 5));
	
	a[4].push_back(make_pair(1, 1));
	a[4].push_back(make_pair(2, 2));
	a[4].push_back(make_pair(3, 3));
	a[4].push_back(make_pair(5, 1));
	
	a[5].push_back(make_pair(3, 1));
	a[5].push_back(make_pair(4, 1));
	a[5].push_back(make_pair(6, 2));
	
	a[6].push_back(make_pair(3, 5));
	a[6].push_back(make_pair(5, 2));
	
	dijkstra(1);
	
	// 결과를 출력합니다. 
	for(int i = 1; i <= number; i++) {
		printf("%d ", d[i]);
	}
}
