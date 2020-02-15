/*
	이진 트리의 구현과 순회(Traversal) 방식
	
	기본적으로 가장 많이 사용되는 비선형 자료구조는 이진 트리(Binary Tree)입니다. 
	이진 트리는 트리 자료구조를 활용한 대표적인 예시로 
	데이터의 탐색 속도 증진을 위해 사용하는 구조입니다. 
	이전에 힙 정렬(Heap Sort)을 구현할 때 간단하게 이진 트리에 대해 
	다루어 본 적이 있습니다. 이번 시간에는 보다 본격적으로 다루어보도록 하겠습니다. 
	실제로 트리를 제대로 구현하기 위해서는 포인터(Pointer)를 사용해야 합니다. 
	포인터를 이용해 특정한 루트(Root)에서 자식 노드로 접근할 수 있기 때문입니다.

	하나의 노드는 모두 왼쪽 자식과 오른쪽 자식을 가질 수 있도록 설계가 되어있습니다. 
	왜 이렇게 반드시 '포인터'를 사용해서 왼쪽 자식과 오른쪽 자식을 
	가리킬 수 있도록 하는 이유는 힙 정렬을 구현할 때는 
	'완전 이진 트리(Complete Binary Tree)'가 사용되었기 때문에 
	배열로 표현할 수 있지만 완전 이진 트리가 아닌 
	이진 트리는 배열로 표현하기 어렵기 때문입니다. 
	
	포인터를 사용해 이진 트리를 구현하는 경우 굉장히 유동적으로 
	트리 자료구조를 활용할 수 있습니다. 
	
	이진 트리에서 데이터를 탐색하는 방법은 크게 세 가지 방법이 있습니다.
	
	1. 전위 순회(Preorder Traversal)

	하나의 노드에 방문했을 때 다음의 순서를 따릅니다.
	
	(1) 먼저 자기 자신을 처리합니다.
	(2) 왼쪽 자식을 방문합니다.
	(3) 오른쪽 자식을 방문합니다.
	
	2. 중위 순회(Inorder Traversal)
	
	하나의 노드에 방문했을 때 다음의 순서를 따릅니다.
	
	(1) 왼쪽 자식을 방문합니다.
	(2) 먼저 자기 자신을 처리합니다.
	(3) 오른쪽 자식을 방문합니다.
	
	3. 후위 순회(Postorder Traversal)
	
	(1) 왼쪽 자식을 방문합니다.
	(2) 오른쪽 자식을 방문합니다.
	(3) 먼저 자기 자신을 처리합니다.
	
	예를 들어 위 예제에서 전위 순회를 이용하면 방문 순서는 다음과 같습니다.

	1 - 2 - 4 - 8 - 9 - 5 - 10 - 11 - 3 - 6 - 12 - 13 - 7 - 14 - 15
	
	중위 순회는 다음과 같습니다.
	
	8 - 4 - 9 - 2 - 10 - 5 - 11 - 1 - 12 - 6 - 13 - 3 - 14 - 7 - 15
	
	마지막으로 후위 순회는 다음과 같습니다.
	
	8 - 9 - 4 - 10 - 11 - 5 - 2 - 12 - 13 - 6 - 14 - 15 - 7 - 3 - 1
	
	구현한 소스코드는 배열로 구현한 것이 아니라 포인터를 이용해 
	구현했다는 점에서 완전 이진 트리가 아니더라도 안정적으로 작동합니다.
*/

#include <iostream>

using namespace std;

int number = 15;

// 하나의 노드 정보를 선언합니다. 
typedef struct node *treePointer;
typedef struct node {
	int data;
	treePointer leftChild, rightChild;
} node;

// 전위 순회를 구현합니다.
void preorder(treePointer ptr) {
	if(ptr) {
		cout << ptr->data << ' ';
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
}

// 중위 순회를 구현합니다. 
void inorder(treePointer ptr) {
	if(ptr) {
		inorder(ptr->leftChild);
		cout << ptr->data << ' ';
		inorder(ptr->rightChild);
	}
}

// 후위 순회를 구현합니다.
void postorder(treePointer ptr) {
	if(ptr) {
		postorder(ptr->leftChild);
		postorder(ptr->rightChild);
		cout << ptr->data << ' ';
	}
} 

int main(void) {
	node nodes[number + 1];
	for(int i = 1; i <= number; i++) {
		nodes[i].data = i;
		nodes[i].leftChild = NULL;
		nodes[i].rightChild = NULL;
	}
	for(int i = 1; i <= number; i++) {
		if(i % 2 == 0)
			nodes[i / 2].leftChild = &nodes[i];
		else
			nodes[i / 2].rightChild = &nodes[i];
	}
	preorder(&nodes[1]);
	return 0;
}
