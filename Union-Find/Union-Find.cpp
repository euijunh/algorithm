/*
	Union-Find(합집합 찾기)
	
	Union-Find(유니온-파인드)는 대표적인 그래프 알고리즘입니다. 
	바로 '합집합 찾기'라는 의미를 가진 알고리즘인데요. 
	서로소 집합(Disjoint-Set) 알고리즘이라고도 부릅니다. 
	구체적으로 여러 개의 노드가 존재할 때 두 개의 노드를 선택해서, 
	현재 이 두 노드가 서로 같은 그래프에 속하는지 판별하는 알고리즘입니다.
	
	여러 개의 노드가 서로 자유분방하게 존재한다고 생각해봅시다. 
	이와 같이 모두 연결되지 않고 각자 자기 자신만을 집합의 원소로 가지고 
	있을 때를 다음과 같이 표현할 수 있습니다. 모든 값이 자기 자신을 
	가리키도록 만드는 겁니다. 아래 표에서 첫 번째 행은 '노드 번호'를 의미하고 
	두 번째 행은 '부모 노드 번호'를 의미합니다. 
	즉, 자신이 어떠한 부모에 포함되어 있는지를 의미합니다.
	
	1	2	3	4	5	6	7	8
	1	2	3	4	5	6	7	8
	
	이 때 위와 같이 1과 2가 연결되었다고 해봅시다. 
	이러한 '연결성'을 우리가 프로그래밍 언어로 어떻게 표현할 수 있을 지에 
	대한 내용이 바로 Union-Find라고 생각하시면 이해가 쉽습니다.
	
	1	2	3	4	5	6	7	8
	1	1	3	4	5	6	7	8
	
	바로 위와 같이 표현됩니다. 2번째 인덱스의 값에 '1'이 들어가는 겁니다. 
	이렇게 부모를 합칠 때는 일반적으로 더 작은 값 쪽으로 합칩니다. 
	바로 이것을 합침(Union)이라고 하는 겁니다.
	
	그렇다면 위와 같이 2와 3도 연결되었다면 어떻게 표현될까요?
	
	1	2	3	4	5	6	7	8
	1	1	2	4	5	6	7	8
	
	위와 같이 표현됩니다. 
	다만, 여기에서 한 가지 의아한 점이 발견됩니다. 
	바로 '1과 3이 연결되었는지는 어떻게 파악할 수 있는지'입니다. 
	1과 3은 부모가 각각 1과 2로 다르기 때문에 '부모 노드'만 보고는 
	한 번에 파악할 수 없습니다. 
	그렇기 때문에 재귀 함수가 사용됩니다.
	
	3의 부모를 찾기 위해서는 먼저 3이 가리키고 있는 2를 찾는 겁니다. 
	그러면 2의 부모가 1을 가리키고 있으므로 
	그제서야 '결과적으로 3의 부모는 1이 되는 구나!'하고 파악할 수 있습니다. 
	이러한 과정은 재귀적으로 수행될 때 가장 효과적이고 직관적으로 언어를 
	작성할 수 있습니다. 그래서 결과적으로 합침(Union) 연산이 
	다 수행되고 나면 다음과 같이 표가 구성됩니다.
	
	1	2	3	4	5	6	7	8
	1	1	1	4	5	6	7	8
	
	노드 1, 2, 3의 부모가 모두 1이기 때문에 이 세 가지 노드는 
	모두 같은 그래프에 속한다고 할 수 있습니다. 
	이것이 바로 Union-Find의 전부입니다. 
	Find 알고리즘은 두 개의 노드의 부모 노드를 확인하여 
	현재 같은 집합에 속하는지 확인하는 알고리즘입니다.
	
	1	2	3	4	5	6	7	8
	1	1	1	4	5	5	6	7
*/

#include <stdio.h>

int getParent(int parent[], int x) {
	if(parent[x] == x) return x;
	return parent[x] = getParent(parent, parent[x]);
}

// 각 부모 노드를 합칩니다. 
void unionParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if(a < b) parent[b] = a;
	else parent[a] = b;
}

// 같은 부모 노드를 가지는지 확인합니다. 
int findParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if(a == b) return 1;
	else return 0;
}

int main(void) {
	int parent[11];
	for(int i = 1; i <= 10; i++) {
		parent[i] = i;
	}
	unionParent(parent, 1, 2);
	unionParent(parent, 2, 3);
	unionParent(parent, 3, 4);
	unionParent(parent, 5, 6);
	unionParent(parent, 6, 7);
	unionParent(parent, 7, 8);
	printf("1과 5는 연결되어있나요? %d\n", findParent(parent, 1, 5));
	unionParent(parent, 1, 5);
	printf("1과 5는 연결되어있나요? %d\n", findParent(parent, 1, 5));
}

/*
	이러한 Union-Find 알고리즘은 다른 고급 그래프 알고리즘의 
	베이스가 된다는 점에서 반드시 알고 있어야 하는 알고리즘입니다. 
	Union-Find를 응용한 알고리즘으로는 
	크루스칼 알고리즘(Kruskal Algorithm)이 있습니다. 
*/
