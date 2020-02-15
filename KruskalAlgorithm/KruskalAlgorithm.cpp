/*
	크루스칼 알고리즘(Kruskal Algorithm)
	
	크루스칼 알고리즘은 가장 적은 비용으로 모든 노드를 연결하기 위해 사용하는 알고리즘입니다. 
	그래프의 모든 정점을 최소 비용으로 연결하는 
	최소 비용 신장 트리를 만들기 위한 대표적인 알고리즘입니다. 
	흔히 여러 개의 도시가 있을 때 각 도시를 도로를 이용해 연결하고자 할 때 
	비용을 최소한으로 하고자 할 때 실제로 적용되는 알고리즘입니다.

	크루스칼 알고리즘의 동작 원리는 다음과 같다.

	간선들을 가중치의 오름차순으로 정렬한다.
	간선들을 그 순서대로 하나씩 선택하되, 
	이미 선택된 간선들과 사이클이 형성되면 선택하지 않는다.
	N - 1 개의 간선이 선택되면 종료한다.

	신장트리 (Spanning Tree)는 
	그래프 중 모든 정점이 간선으로 연결되어 있고, 
	간선들 사이에 사이클이 없는 그래프를 말한다.
	
	최소 비용 신장트리 (Minimum Spanning Tree)는 
	그래프에서 가능한 신장트리들 중에서 가중치의 합이 최소인 신장트리를 말한다.

	- 노드 = 정점 = 도시
	- 간선 = 거리 = 비용
	
	크루스칼 알고리즘의 핵심 개념은 무엇일까요? 바로 다음과 같습니다.
	
	간선을 거리가 짧은 순서대로 그래프에 포함시키면 어떨까?
	
	일단 모든 노드를 최대한 적은 비용으로 '연결만' 시키면 되기 때문에 
	모든 간선 정보를 오름차순으로 정렬한 뒤에 비용이 적은 
	간선부터 차근차근 그래프에 포함시키면 되는 것입니다!

	모든 간선들을 '거리(비용)'을 기준으로 먼저 오름차순 정렬을 수행합니다. 
	이제부터 다음의 알고리즘에 맞게 그래프를 연결하시면 가장 적은 비용으로 
	모든 노드를 연결한 그래프인 '최소 비용 신장 트리'가 만들어집니다.		
	
	1. 정렬된 순서에 맞게 그래프에 포함시킵니다.
	2. 포함시키기 전에는 사이클 테이블을 확인합니다.
	3. 사이클을 형성하는 경우 간선을 포함하지 않습니다.

	여기에서 사이클이라는 것은 말 그대로 그래프가 서로 연결되어 사이클을 형성하는 경우입니다. 
	최소 비용 신장 트리에서는 사이클이 발생하면 안 됩니다. 
	애초에 모든 노드를 이어붙이기만 하면 되는데 사이클이 발생할 이유가 없습니다.
	
	사이클이 발생하는지의 여부는 Union-Find 알고리즘을 적용합니다. 

	실행 후에 사이클 테이블의 모든 값이 1이 되면서 
	최소 비용 신장 트리가 만들어진 것을 알 수 있습니다. 
	나머지 남은 간선 4개는 모두 스킵(Skip) 처리되면서 결과적으로 다음과 같이 완성됩니다.
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 부모 노드를 가져옴 
int getParent(int set[], int x) {
	if(set[x] == x) return x;
	return set[x] = getParent(set, set[x]);
} 

// 부모 노드를 병합 
void unionParent(int set[], int a, int b) {
	a = getParent(set, a);
	b = getParent(set, b);
	// 더 숫자가 작은 부모로 병합
	if(a < b) set[b] = a;
	else set[a] = b;
} 

// 같은 부모를 가지는지 확인
int find(int set[], int a, int b) {
	a = getParent(set, a);
	b = getParent(set, b);
	if(a == b) return 1;
	else return 0;
}
 
// 간선 클래스 선언 
class Edge {
public:
	int node[2];
	int distance; // 거리 
	// 생성자 
	Edge(int a, int b, int distance) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}
	// 거리를 기준으로 오름차순으로 정렬 
	bool operator <(Edge &edge) {
		return this->distance < edge.distance;
	}
};

int main(void) {
	int n = 7; // 정점의 개수 
	int m = 11; // 간선의 개수 
	
	vector<Edge> v;
	v.push_back(Edge(1, 7, 12));
	v.push_back(Edge(1, 4, 28));
	v.push_back(Edge(1, 2, 67));
	v.push_back(Edge(1, 5, 17));
	v.push_back(Edge(2, 4, 24));
	v.push_back(Edge(2, 5, 62));
	v.push_back(Edge(3, 5, 20));
	v.push_back(Edge(3, 6, 37));
	v.push_back(Edge(4, 7, 13));
	v.push_back(Edge(5, 6, 45));
	v.push_back(Edge(5, 7, 73));
	
	// 간선의 비용으로 오름차순 정렬 
	sort(v.begin(), v.end());
	
	// 각 정점이 포함된 그래프가 어디인지 저장 
	int set[n];
	for(int i = 0; i < n; i++) {
		set[i] = i;
	}
	
	// 거리의 합을 0으로 초기화 
	int sum = 0;
	for(int i = 0; i < v.size(); i++) {
		// 동일한 부모를 가르키지 않는 경우, 즉 사이클이 발생하지 않을 때만 선택 
		if(!find(set, v[i].node[0] - 1, v[i].node[1] - 1)) {
			sum += v[i].distance; 
			unionParent(set, v[i].node[0] - 1, v[i].node[1] - 1);
		}
	}
	
	printf("%d\n", sum);
}

/*
	크루스칼 알고리즘의 시간 복잡도는 정렬 알고리즘과 동일합니다.
	크루스칼 알고리즘은 사실상 정렬 알고리즘과 Union-Find 알고리즘의 합이라고 할 수 있으므로 
	정렬 알고리즘의 시간 복잡도와 동일하다고 판단해도 큰 무리가 없습니다.
*/
