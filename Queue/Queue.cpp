/*
	큐(Queue)
	
	큐는 대표적인 자료구조의 일종으로 
	먼저 나가는(First In First Out, FIFO) 구조를 가지고 있습니다. 
	쉽게 이해하기 위해서는 은행 창구를 떠올릴 수 있습니다. 
	먼저 번호표를 뽑은 사람이 먼저 서비스를 받게 됩니다. 
	중간에 새치기는 불가능한 것이 기본적인 큐의 구조입니다.
	
	스택과는 다르게 통로의 양 옆이 뚫려 있어서 왼쪽이 입구, 오른쪽이 출구라고 볼 수 있습니다.
	
	C++ STL Queue 라이브러리를 활용해 구현
*/

#include <iostream>
#include <queue>

using namespace std;

int main(void) {
	queue<int> q;
	q.push(7);
	q.push(5);
	q.push(4);
	q.pop();
	q.push(6);
	q.pop();
	while(!q.empty()) {
		cout << q.front() << ' ';
		q.pop();
	}
	return 0;
}

/*
	결과적으로 큐에서 앞에서부터 하나씩 빠져나와 4와 6이 출력되는 것을 볼 수 있습니다. 
	큐 또한 마찬가지로 큐 자체로는 큰 의미가 없고 하나의 자료구조로서 
	나중에 다양한 알고리즘을 설계할 때 그 토대가 되는 역할을 수행합니다. 
	
*/
