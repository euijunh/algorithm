/*
	백준 11047번 문제 
	https://www.acmicpc.net/problem/11047
	동전 0
	시간제한 : 1 초
	메모리제한 : 256 MB
	
	문제
	준규가 가지고 있는 동전은 총 N종류이고, 각각의 동전을 매우 많이 가지고 있다.

	동전을 적절히 사용해서 그 가치의 합을 K로 만들려고 한다. 
	이때 필요한 동전 개수의 최솟값을 구하는 프로그램을 작성하시오.
	
	입력
	첫째 줄에 N과 K가 주어진다. (1 ≤ N ≤ 10, 1 ≤ K ≤ 100,000,000)

	둘째 줄부터 N개의 줄에 동전의 가치 Ai가 오름차순으로 주어진다. 
	(1 ≤ Ai ≤ 1,000,000, A1 = 1, i ≥ 2인 경우에 Ai는 Ai-1의 배수)
	
	출력
	첫째 줄에 K원을 만드는데 필요한 동전 개수의 최솟값을 출력한다.
	
	예제입력
	10 4200
	1
	5
	10
	50
	100
	500
	1000
	5000
	10000
	50000

	예제출력
	6
	
	예제입력2
	10 4790
	1
	5
	10
	50
	100
	500
	1000
	5000
	10000
	50000
	
	예제출력2
	12
	
	이 문제는 위 거스름돈 문제의 업그레이드 버전이라고 할 수 있습니다. 
	거스름 돈으로 줄 수 있는 화폐의 종류 또한 입력으로 받기 때문입니다. 
	따라서 화폐의 종류를 담을 수 있는 배열을 하나 생성한 뒤에 배열에 담고, 
	거슬러 줄 때는 하나씩 차례대로 처리하면 됩니다. 
	다만 항상 화폐의 가치가 큰 것부터 나누어주어야 하므로 
	처리할 때는 순서를 거꾸로 하여 처리해야 합니다.
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> a;

int main(void) {
	int n, k;
	cin >> n >> k;
	int result = 0;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a.push_back(x);
	}
	// 큰 동전부터 계산 
	for(int i = a.size() - 1; i >= 0; i--) {
		result += k / a[i];
		k %= a[i];
	}
	cout << result;
	return 0;
}
