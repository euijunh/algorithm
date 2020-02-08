/*
	백준 2751번 문제 - 시간 복잡도 O(N * logN)
	https://www.acmicpc.net/problem/2751
	100만 개 정렬
	시간제한 : 2 초
	메모리제한 : 256 MB
	
	문제
	N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.
	
	입력
	첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000,000)이 주어진다. 
	둘째 줄부터 N개의 줄에는 숫자가 주어진다. 
	이 수는 절댓값이 1,000,000보다 작거나 같은 정수이다. 수는 중복되지 않는다.
	
	출력
	첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.
	
	예제입력
	5
	5
	4
	3
	2
	1

	예제출력
	1
	2
	3
	4
	5

	병합정렬 사용 
*/
 
#include <stdio.h>
int number;
int sorted[1000000]; // 정렬 배열은 반드시 전역 변수로 선언 
int data[1000000];

void merge(int a[], int m, int middle, int n) {
	int i = m;
	int j = middle + 1;
	int k = m;
	// 작은 순서대로 배열에 삽입 
	while(i <= middle && j <= n) {
		if(a[i] <= a[j]) {
			sorted[k] = a[i];
			i++;
		} else {
			sorted[k] = a[j];
			j++;
		}
		k++;
	}
// 남은 데이터도 삽입 
	if(i > middle) {
		for(int t = j; t <= n; t++) {
			sorted[k] = a[t];
			k++;
		}
	} else {
		for(int t = i; t <= middle; t++) {
			sorted[k] = a[t];
			k++;
		}
	}
// 정렬된 배열을 삽입 
	for(int t = m; t <= n; t++) {
		a[t] = sorted[t];
	}
}

void mergeSort(int a[], int m, int n) {
	// 이외의 경우는 크기가 1개인 경우 
	if(m < n) {
		int middle = (m + n) / 2;
		mergeSort(a, m, middle);
		mergeSort(a, middle + 1, n);
		merge(a, m, middle, n);
	}
}

int main(void) {	
	
	scanf("%d", &number);
	
	for(int i = 0; i < number; i++) {
	  scanf("%d", &data[i]);
	}
	
	mergeSort(data, 0, number - 1);
	
	for(int i = 0; i < number; i++) {
	  printf("%d\n", data[i]);
	}
} 

/*
	C++ 알고리즘 STL 라이브러리를 사용
	
	#include <stdio.h>
	#include <algorithm>
	
	int number, data[1000000];
	
	int main(void) {
	scanf("%d", &number);
	for(int i = 0; i < number; i++) {
		scanf("%d", &data[i]);
	}
	std::sort(data, data + number);
	for(int i = 0; i < number; i++) {
		printf("%d\n", data[i]);
	}
	return 0;
}
*/
