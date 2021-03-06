/*
	힙 정렬(Heap Sort)
	
	힙 정렬(Heap Sort)은 병합 정렬(Merge Sort)와 퀵 정렬(Quick Sort)만큼 빠른 정렬 알고리즘입니다. 
	또한 실제로 고급 프로그래밍 기법으로 갈 수록 힙(Heap)의 개념이 자주 등장하기 때문에 
	반드시 알고 넘어가야 할 정렬 알고리즘이기도 합니다. 힙 정렬은 힙 트리 구조(Heap Tree Structure)를 
	이용하는 정렬 방법입니다. 즉 정렬의 기초 아이디어는 다음과 같습니다.
	
	힙(Heap)을 이용해 데이터를 정렬하면 어떨까?
	
	따라서 가장 먼저 힙(Heap)이 무엇인지 알아야 합니다. 
	그리고 힙을 알기 전에는 이진 트리(Binary Tree)에 대해서 알고 있을 필요가 있습니다. 
	이진 트리란 컴퓨터 안에서 데이터를 표현할 때 데이터를 각 노드(Node)에 담은 뒤에 노드를 
	두 개씩 이어 붙이는 구조를 말합니다. 이 때 트리 구조에 맞게 부모 노드에서 자식 노드로 가지가 뻗힙니다. 
	이진 트리는 모든 노드의 자식 노드가 2개 이하인 노드입니다.

	여기서 트리(Tree)라는 것은 말 그대로 가지를 뻗어나가는 것처럼 데이터가 
	서로 연결되어있다는 것입니다. 트리는 그 형태에 따라서 종류가 굉장히 다양한데 
	우리는 일단 자식 노드가 2개 이하인 이진 트리에 대해서만 알면 됩니다. 
	위와 같이 이진 트리가 어떻게 생겼는지 알아보았으니 
	이제 완전 이진 트리(Complete Binary Tree)에 대해 알아보도록 합시다.  

	완전 이진 트리는 데이터가 루트(Root) 노드부터 시작해서 자식 노드가 왼쪽 자식 노드, 
	오른쪽 자식 노드로 차근차근 들어가는 구조의 이진 트리입니다. 
	즉 완전 이진 트리는 이진 트리의 노드가 중간에 비어있지 않고 빽빽히 가득 찬 구조입니다. 
	예를 들어 데이터가 1부터 7까지 총 7개라면 이것을 트리에 삽입하면 다음과 같은 순서로 
	들어갑니다. 항상 왼쪽 자식 노드부터 데이터가 들어갑니다.
	
	이제 완전 이진 트리에 대해서도 알아보았으므로 힙(Heap)에 대해 알아보도록 합시다. 
	힙은 최솟값이나 최댓값을 빠르게 찾아내기 위해 완전 이진 트리를 기반으로 하는 트리입니다. 
	힙에는 최대 힙과 최소 힙이 존재하는데 최대 힙은 '부모 노드'가 '자식 노드'보다 
	큰 힙이라고 할 수 있습니다. 일단 힙 정렬을 하기 위해서는 정해진 
	데이터를 힙 구조를 가지도록 만들어야 합니다. 
	
	최대 힙은 부모 노드의 값이 자식 노드보다 커야 합니다. 
	
	다만 트리(Tree) 안에서 특정 노드 때문에 최대 힙이 붕괴되는 경우가 있습니다. 
	전체로 보면 중간에 있는 특정 데이터를 가지는 노드 때문에 
	최대 힙이 아니지만 그 위 쪽으로 보았을 때는 최대 힙이 형성되고, 
	아래쪽으로 보았을 때는 최대 힙이 형성되지 않는 경우가 만들어질 수 있습니다. 
	
	힙 정렬을 수행하기 위해서는 힙 생성 알고리즘(Heapify Algorithm)을 사용합니다. 
	힙 생성 알고리즘은 특정한 '하나의 노드'에 대해서 수행하는 것입니다. 
	또한 해당 '하나의 노드를 제외하고는 최대 힙이 구성되어 있는 상태'라고 
	가정을 한다는 특징이 있습니다.
	
	힙 생성 알고리즘(Heapify Algorithm)은 특정한 노드의 두 자식 중에서 
	더 큰 자식과 자신의 위치를 바꾸는 알고리즘입니다. 
	또한 위치를 바꾼 뒤에도 여전히 자식이 존재하는 경우 또 자식 중에서 
	더 큰 자식과 자신의 위치를 바꾸어야 합니다. 자식이 더이상 존재하지 않을 때 까지요. 

	힙 생성 알고리즘은 전체 트리를 힙 구조를 가지도록 만든다는 점에서 
	굉장히 중요한 알고리즘입니다. 이러한 힙 생성 알고리즘의 시간 복잡도는 몇 일까요? 
	한 번 자식 노드로 내려갈 때마다 노드의 갯수가 2배씩 증가한다는 점에서 O(log N)입니다. 
	예를 들어 데이터의 갯수가 1024개라면 대략 10번 정도만 내려가도 된다는 거에요. 
	이제 한 번 실제 힙 정렬 과정을 수행해보도록 합시다. 
	
	다음의 데이터를 오름차순 정렬하세요.
	7 6 5 8 3 5 9 1 6
	
	기본적으로 완전 이진 트리를 표현하는 가장 쉬운 방법은 배열에 그대로 삽입하는 겁니다. 
	현재 정렬할 데이터의 갯수가 9개이기 때문에 인덱스 0부터 8까지 차례대로 담아주는 것입니다.
	
	0 1 2 3 4 5 6 7 8
	7 6 5 8 3 5 9 1 6
	
	다시 말해서 완전 이진 트리에 삽입이 되는 순서대로 인덱스를 붙여주는 겁니다. 
	위 배열을 완전 이진 트리 형태로 출력하면 다음과 같습니다.
	
					7
			6				5
		8		3		5		9
	1		6
	
	말 그대로 배열에 있는 인덱스가 그대로 차례대로 트리로 표현된 것입니다. 
	완전 이진 트리를 배열로 표현하고, 배열을 다시 완전 이진 트리로 
	표현할 수 있어야 합니다. 위와 같은 상황에서 모든 원소를 기준으로 
	힙 생성 알고리즘을 적용하셔서 전체 트리를 힙 구조로 만들어주시면 됩니다. 
	이 때 데이터의 갯수가 N개 이므로 전체 트리를 힙 구조로 만드는 
	복잡도는 O(N * log N)입니다. ( 사실상 모든 데이터를 기준으로 힙 생성 알고리즘을 
	쓰지 않아도 되기 때문에 O(N)에 가까운 속도를 낼 수 있습니다. )
	
					9
			8				7
		6		3		5		5
	1		6
	
	그래서 결과적으로는 위와 같이 최대 힙이 구성됩니다. 
	고작 O(N * logN)으로 위와 같이 만들 수 있는 겁니다. 
	이제부터 실제로 우리가 원하던 정렬을 직관적으로 수행할 수 있습니다. 
	루트(Root)에 있는 값을 가장 뒤쪽으로 보내면서 힙 트리의 크기를 1씩 빼주는 겁니다. 
	
					6
			8				7
		6		3		5		5
	1		9
	
	9와 6을 바꾼 뒤에 9는 정렬이 완료된 것으로 처리합니다. 
	이제 9를 제외하고 나머지 8개 원소를 기준으로 또 힙 생성 알고리즘(Heapify)를 
	수행합니다. 결과는 다음과 같습니다. 
	
					8
			6				7
		6		3		5		5
	1		9
	
	이제 다시 가장 큰 숫자인 8이 루트에 존재합니다. 이것을 가장 뒤 쪽의 원소와 서로 바꿉니다.
	
					1
			6				7
		6		3		5		5
	8		9
	
	그럼 위와 같이 8과 9가 가장 뒤에 배열되어 정렬이 이루어졌습니다. 
	이제 이 과정을 반복하시면 됩니다. 힙 생성 알고리즘의 시간 복잡도는 
	O(log N)이고 전체 데이터의 갯수가 N개이므로 시간 복잡도는 O(N * log N)이라고 
	할 수 있습니다. 또한 아까전에 계산했던 맨 처음에 힙 구조를 만드는 복잡도는 
	O(N * log N)이었습니다. 한 마디로 전체 힙 정렬의 전체 시간 복잡도는 O(N * log N)입니다. 
	
	힙 정렬의 전체 시간 복잡도는 O(N * log N)입니다.
		
*/

#include <stdio.h>

int number = 9;
int heap[9] = {7, 6, 5, 8, 3, 5, 9, 1, 6};

int main(void) {
	// 힙을 구성 
	for(int i = 1; i < number; i++) {
		int c = i;
		do {
			int root = (c - 1) / 2;
			if(heap[root] < heap[c]) {
				int temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			c = root;
		} while (c != 0);
	}
	// 크기를 줄여가며 반복적으로 힙을 구성
	for (int i = number - 1; i >= 0; i--) { 
		int temp = heap[0];
		heap[0] = heap[i];
		heap[i] = temp;
		int root = 0;
		int c = 1;
		do {
			c = 2 * root + 1;
			// 자식 중에 더 큰 값을 찾기 
			if(c < i - 1 && heap[c] < heap[c + 1]) {
				c++;
			}
			// 루트보다 자식이 크다면 교환 
			if(c < i && heap[root] < heap[c]) {
				temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			root = c;
		} while (c < i);
	} 
	// 결과 출력 
	for(int i = 0; i < number; i++) {
		printf("%d ", heap[i]);
	}
}

/*
	힙 정렬은 병합 정렬과 다르게 별도로 추가적인 배열이 필요하지 
	않다는 점에서 메모리 측면에서 몹시 효율적입니다. 
	또한 항상 O(N * log N)을 보장할 수 있다는 점에서 몹시 강력한 
	정렬 알고리즘입니다. 이론적으로는 퀵 정렬, 병합 정렬보다 더 
	우위에 있다고 할 수 있습니다. 하지만 단순히 속도만 가지고 비교하면 
	퀵 정렬이 평균적으로 더 빠르기 때문에 힙 정렬이 일반적으로 많이 사용되지는 않습니다.
	
	보충 자료
	
	최대 힙을 활용한 오름차순 정렬에서 힙 생성 함수(Heapify)는 특정한 노드를 
	기준으로 위쪽으로 올라가는 상향식 구현 방식과 아래쪽으로 내려가는 
	하향식 구현 방식이 있습니다. 두 방식 모두 시간 복잡도는 동일하다는 특징이 있습니다. 
	위 본문에서는 상향식 구현 방식을 보여주었는데 하향식 구현 방식도 스스로 고민해서 
	작성해보는 연습을 해보는 것이 좋을 것 같습니다. 
	
	< 예시 입력 >

	10
	10 26 5 37 1 61 11 59 15 48 19
	
	위와 같이 10개의 원소가 들어왔을 때 다음과 같은 
	정렬 과정이 출력되도록 하는 프로그램을 작성하세요. 
	이 때 힙 생성을 함에 있어서 하향식으로 구현을 해야 정상적으로 답이 출력됩니다.
	
	< 예시 출력 >

	61 48 59 26 19 11 37 15 1 5
	59 48 37 26 19 11 5 15 1 61	
	48 26 37 15 19 11 5 1 59 61	
	37 26 11 15 19 1 5 48 59 61
	26 19 11 15 5 1 37 48 59 61	
	19 15 11 1 5 26 37 48 59 61	
	15 5 11 1 19 26 37 48 59 61	
	11 5 1 15 19 26 37 48 59 61	
	5 1 11 15 19 26 37 48 59 61	
	1 5 11 15 19 26 37 48 59 61
	
	< 정답 소스코드 >
*/
/*
#include <iostream>
#include <vector>

using namespace std;

int number;
int heap[1000001];

void heapify(int i) {
	// 왼쪽 자식 노드를 가리킵니다. 
	int c = 2 * i + 1;
	// 오른쪽 자식 노드가 있고, 왼쪽 자식노드보다 크다면 
	if(c < number && heap[c] < heap[c + 1]) {
		c++;
	}
	// 부모보다 자식이 더 크다면 위치를 교환합니다. 
	if(heap[i] < heap[c]) {
		int temp = heap[i];
		heap[i] = heap[c];
		heap[c] = temp;
	} 
	// number / 2까지만 수행하면 됩니다. 
	if(c <= number / 2) heapify(c);
}

int main(void) {
	cin >> number;
	for(int i = 0; i < number; i++) {
		int x;
		cin >> heap[i];
	}
	// 힙을 생성합니다. 
	for(int i = number / 2; i >= 0; i--) {
		heapify(i);
	}
	// 정렬을 수행합니다. 
	for (int i = number - 1; i >= 0; i--) { 
		for(int j = 0; j < number; j++) {
			cout << heap[j] << ' ';
		}
		cout << '\n';
		int temp = heap[0];
		heap[0] = heap[i];
		heap[i] = temp;
		int root = 0;
		int c = 1;
		do {
			c = 2 * root + 1;
			if(c < i - 1 && heap[c] < heap[c + 1]) c++;
			if(c < i && heap[root] < heap[c]) {
				temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			root = c;
		} while (c < i);
	}
}
*/

