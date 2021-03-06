/*
	이분 매칭(Bipartite Matching)
	
	이분 매칭(Bipartite Matching) 알고리즘은 
	네트워크 플로우 알고리즘과 연계되는 개념입니다.
	 
	이분 매칭을 간단하게 설명하면 다음과 같습니다.
	이분 매칭은 A 집단이 B 집단을 선택하는 방법에 대한 알고리즘입니다.
	다음의 예시를 살펴보도록 합시다. 
	'사람'이라는 집단과 '노트북'이라는 두 개의 집단이 등장합니다.

	'사람' 집단에 존재하는 각 사람이 원하는 항목이 정해져 있을 때 
	가장 효과적으로 매칭시켜줄 수 있는 경우는 어떠한 경우인지 알아봅시다. 
	이를 바로 그래프 형태로 표현하는 겁니다.

	효과적으로 매칭시켜준다는 말은 다시 말해 '최대 매칭(Max Matching)'을 의미하는 것입니다. 
	모든 사람 각각이 노트북을 선택하여 가장 많이 연결되는 경우를 찾는 문제라고 볼 수 있습니다. 
	플로우로 표현해보면 네트워크 플로우와 정확히 일치하게 됩니다.

	맞습니다. 이분 매칭 알고리즘은 네트워크 플로우로 표현할 수 있습니다. 
	각 용량(Capacity)를 1로 설정한 네트워크 플로우 문제로 이해할 수 있는 것입니다. 
	다만 에드몬드 카프 알고리즘은 시간 복잡도가 O(V * E^2)였습니다. 
	이분 매칭에 한해 이것보다 더 빠르고 효율적인 알고리즘을 설계할 수 있습니다. 
	바로 단순한 형태의 깊이 우선 탐색(DFS)로 푸는 방법입니다.

	1 -> A, B, C
	2 -> A
	3 -> B

	바로 한 번 출발해봅시다. 먼저 정점 1이 A와 연결됩니다. 
	정점 1의 입장에서는 당장 A가 아무 정점에게도 
	연결이 되어 있지 않으니까 바로 A를 선택한 겁니다.

	이후에 정점 2가 들어갈 공간을 살펴봅시다. 
	이 때 가능한 경우는 A 밖에 존재하지 않는데 이미 정점 1이 점유하고 있습니다. 
	다음과 같은 상황입니다.

	이 때는 A를 점유하고 있는 정점 1에서부터 다시 출발하여, 
	A를 제외하고 다른 곳으로 연결될 수는 없는지 확인합니다. 
	확인 결과 B와 연결될 수 있으므로 B와 연결합니다.
	
	이제 정점 3을 확인해봅시다. 정점 3은 다음과 같이 B로만 연결될 수 있습니다.
	
	다만 이미 B를 정점 1이 점유하고 있는 상황입니다. 
	따라서 정점 1에게 가서 B 말고 다른 것을 선택할 수 없는지 확인합니다.
	
	정점 1에 연결된 다른 노드인 A를 확인했더니 이미 정점 2가 점유하고 있습니다. 
	이러면 다시 정점 2에게 가서 A 말고 다른 것을 선택할 수 없는지 확인합니다. 
	하지만 정점 2또한 A 말고는 연결될 곳이 없습니다. 
	그러므로 정점 1의 다른 인접 노드를 확인합니다.
	
	정점 1의 다른 인접 노드인 C를 살펴봅시다. 
	C는 아무 곳에도 연결이 되어있지 않네요. 
	따라서 이것을 선택할 수 있도록 합니다.
	
	결과 
	2 -> 1
	3 -> 2
	1 -> 3
*/

#include <iostream>
#include <vector>
#define MAX 101 // 정점의 개수는 100개로 설정 

using namespace std;

vector<int> a[MAX]; // 각 정점과 연결된 간선 정보 
int d[MAX]; // 특정한 정점(노트북)을 선택하고 있는 즉 점유하고 있는 노드의 정보 
bool c[MAX]; // 특정한 정점을 이미 처리했는지 여부를 보관 
int n = 3; 

// 매칭에 성공한 경우 True, 실패한 경우 False 
bool dfs(int x) { // 1, 2, 3 순서로 x값이 들어온다. 
	// 연결된 모든 노드에 대해서 들어갈 수 있는지 시도 
	for(int i = 0; i < a[x].size(); i++) { // 특정한 정점에 대해서 연결된 모든 노드를 다 확인 
		int t = a[x][i]; // 연결된 노드를 담는다. 
		// 이미 처리한 노드는 더 이상 볼 필요가 없음 
		if(c[t]) continue;
		c[t] = true;
		// 비어있거나 점유 노드에 더 들어갈 공간이 있는 경우 
		if(d[t] == 0 || dfs(d[t])) { 
		// 선택을 안받아서 0인 값 (비어있는지) 
		// 해당 점유하고 있는 노드에게 다른곳에 들어갈 수 있는지 물어봄 
			d[t] = x;
			return true;
		}
	}
	return false;
}

int main(void) {
	a[1].push_back(1);
	a[1].push_back(2);
	a[1].push_back(3);
	a[2].push_back(1);
	a[3].push_back(2);
	int count = 0;
	// 총 몇개까지 최대매칭이 가능한지 
	for(int i = 1; i <= n; i++) { // 최대한 우겨 넣습니다. 3번 반복 
		fill(c, c + MAX, false); // 매칭을 수행할 때마다 false로 초기화 
		if(dfs(i)) count++;
	}
	printf("%d개의 매칭이 이루어졌습니다.\n", count);
	// 어떻게 매칭되었는지 출력 
	for(int i = 1; i <= 100; i++) {
		if(d[i] != 0) {
			printf("%d -> %d\n", d[i], i);
		}
		/*
			출력 
			2 -> 1
			3 -> 2
			1 -> 3	
		*/
	}
	return 0;
}

/*
	위와 같이 깊이 우선 탐색(DFS)를 이용해 이분 매칭을 간단히 풀 때의 시간 복잡도는 O(V * E)입니다. 
	이 방법은 가장 빠른 속도의 알고리즘은 아니지만 구현이 가장 간단하고 쉽다는 점에서 
	알고리즘 대회에서 가장 많이 사용되고 있습니다.
*/
