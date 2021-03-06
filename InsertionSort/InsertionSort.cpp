#include <stdio.h>

/*
	삽입 정렬(Insertion Sort)
	
	앞서 다룬 정렬 알고리즘(선택, 버블) 모두 시간 복잡도 O(N^2)을 가진다는 점에서 비효율적인 알고리즘에 속합니다. 
	이번 시간에 다루게 될 삽입 정렬(Insertion Sort)은 어떨까요? 문제는 지난 시간과 동일합니다.
	
	다음의 숫자들을 오름차순으로 정렬하는 프로그램을 작성하세요.
	1 10 5 8 7 6 4 3 2 9
  	
	삽입 정렬은 위 문제를 풀 때 "각 숫자를 적절한 위치에 삽입하는 방법"으로 문제를 해결합니다. 
	다른 정렬 방식들은 무조건 위치를 바꾸는 방식(이미 정렬이 되있는 상태라 해도)이었다면 
	삽입 정렬은 '필요할 때만' 위치를 바꾸게 됩니다.
	이러한 특성 때문에 실제로는 선택정렬, 버블정렬보다 더빠르다. 
	또한 삽입정렬 같은 경우는 특정한 경우에서는 굉장히 빠르게  작동하기 떄문에  
	시간복잡도 O(N^2)을 가지는 세가지 정렬알고리즘 중에서는 가장 강력한 알고리즘이다. 
	
	삽입정렬은 앞에 있는 원소들이 이미 정렬이 되어있다고 가정을 한다.
	이런 특성때문에 선택,버블정렬 보다는 조금더 효율적이다.
	
	_ 1 _ 10 _ 5 8 7 6 4 3 2 9
	1 5 10 8 7 6 4 3 2 9
	_ 1 _ 5 _ 10 _ 8 7 6 4 3 2 9
	1 5 8 10 7 6 4 3 2 9
	적절한 위치로 바꿔 준다. 
	
	1 5 8 10 7 6 4 3 2 9
	6을 기준으로 봤을때 왼쪽은 이미 정렬이 되어있기 때문에 필요한 만큼만 이동하면 되기
	때문에 선택,버블정렬보다는 휠씬 효율적이다. 연산자체가 적다.
	적절한 위치에 삽입하는 알고리즘
	
	각 숫자를 적절한 위치에 삽입하면 어떨까?
	
	바로 알고리즘을 확인해보도록 합시다. 
	삽입 정렬은 비교적 느린 정렬 알고리즘에 속하지만 쉽게 생각할 수 없는, 조금은 복잡한 구조를 가지고 있습니다.
*/

int main(void) {
	int i, j, min, index, temp;
	int array[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
	for(i = 0; i < 9; i++) {
		j = i; // 현재 정렬할 원소를 넣어줌 
		while(j >= 0 && array[j] > array[j + 1]) {
			// 오른쪽에 있는 값과 비교해 왼쪽에 있는 값이 더크다면 서로위치를 바꿔줌 (선택,버블보다 빠른이유:멈출포인트가 있다)
			// 거의 정렬된' 상태라면 빠른 속도 
			// j >= 0 인덱스가 -1이 되는 것을 방지 (array[-1] 방지)
			// 현재의 값을 왼쪽의 값과 비교해서 왼쪽의 값이 더크다면 계속해서 자리를 바꿔줌 그래서 왼쪽은 항상 정렬된상태 
			temp = array[j];
			array[j] = array[j + 1];
			array[j + 1] = temp;
			j--;
		}
	}
	// 정렬된 소스코드 출력 
	for(i = 0; i < 10; i++) {
		printf("%d ", array[i]);
	}
	return 0;
}

/*
	삽입 정렬은 기본적으로 '정렬이 되어있다고 가정'을 한다는 점에서 특정한 경우에 따라 굉장히 빠른 속도를 자랑합니다. 
	일단 소스코드상 반복문이 두 번 들어가있다는 점에서 복잡도는 O(N^2)입니다.
	
	삽입 정렬의 시간 복잡도는 O(N^2)입니다.
	
	하지만 한 번 다음의 경우를 생각해보도록 합시다.
	
	다음의 숫자들을 오름차순으로 정렬하는 프로그램을 작성하세요.
	2 3 4 5 6 7 8 9 10 1
	
	만약 데이터가 위와 같이 '거의 정렬된' 상태라면 어떤 알고리즘이 가장 효율적일까요? 
	바로 지금 우리가 공부하고 있는 삽입 정렬입니다. 
	삽입 정렬은 필요할 때에 한해서만 삽입을 진행하기 때문에 데이터가 이미 거의 정렬된 상태에 한해서는 
	어떤 알고리즘보다도 빠르다는 특징을 가지고 있습니다.
	
	보충 자료
	삽입 정렬을 완전히 이해하기 위해서 삽입 정렬이 수행되는 과정을 일일이 출력하는 프로그램을 작성해 볼 수 있습니다. 
	다음과 같이 여러 개의 숫자가 들어왔을 때 이를 삽입 정렬하는 과정을 출력해보세요.
	
	< 예시 입력 >
	
	10
	26 5 37 1 61 11 59 15 48 19
	
	< 예시 출력 >
	
	26 
	5 26 
	5 26 37 
	1 5 26 37 
	1 5 26 37 61 
	1 5 11 26 37 61 
	1 5 11 26 37 59 61 
	1 5 11 15 26 37 59 61 
	1 5 11 15 26 37 48 59 61 
	1 5 11 15 19 26 37 48 59 61
	
	< 정답 소스코드 >
	
	위와 같은 경우는 아예 특정 위치에서 시작해서 왼쪽으로 이동하며 자신보다 작은 것을 만날 때 그 위치에 원소를 삽입하면 됩니다. 
	따라서 기존의 소스코드를 약간 수정하여 정답을 도출할 수 있습니다.
	
	int n;
	int array[101];

	int main(void) {
		int i, j, temp, n;
		scanf("%d", &n);
		for(i = 0; i < n; i++) {
			scanf("%d", &array[i]);
		}
		for(i = 0; i < n; i++) {
			j = i;
			while(j > 0 && array[j - 1] > array[j]) {
				temp = array[j - 1];
				array[j - 1] = array[j];
				array[j] = temp;
				j--;
			}
			for(j = 0; j <= i; j++) {
				printf("%d ", array[j]);
			}
			printf("\n");
		}
		return 0;
	}
*/
