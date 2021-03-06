#include <stdio.h>

/*
	버블 정렬(Bubble Sort) - 정렬알고리즘 중에서 가장 느리다. 
	
	가장 작은 값을 선택해서 앞으로 보내는 선택 정렬(Selection Sort) 알고리즘에 이어 
	버블 정렬(Bubble Sort)에 대해 알아보려고 합니다. 
	문제는 지난 시간에 만났던 문제와 동일합니다. 
	바로 일련의 숫자들을 오름차순으로 정렬하는 것입니다.
	
	다음의 숫자들을 오름차순으로 정렬하는 프로그램을 작성하세요.
	1 10 5 8 7 6 4 3 2 9
  	
	버블 정렬 또한 선택 정렬과 같이 몹시 직관적인 해결 방법입니다. 
	바로 가까이에 있는 두 숫자끼리 비교를 해서 당장 더 작은 숫자를 앞으로 보내주는 것을 반복하는 겁니다.
	옆에 있는 값과 비교해서 더 작은 값을 앞으로 보내면 어떨까?
	다시 말해 버블 정렬이란 옆에 있는 값과 비교하여 더 작은 값을 반복적으로 앞으로 보내는 정렬 방법입니다. 
	버블 정렬은 정렬 알고리즘 중에서 구현은 가장 쉽지만 가장 비효율적인 알고리즘입니다.
*/

int main(void) {
	int i, j, temp;
	int array[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
	for(i = 0; i < 10; i++) {
		for(j = 0; j < 9 - i; j++) { // 한번의 반복이 끝났을때 가장 큰값이 맨뒤로 이동하게된다. 
			// 현재 값과 옆의 값을 비교하기 때문에 9 - i로 작성시에 마지막 값까지 비교가 가능하다. 
			// 9 - i인 이유는 맨뒤부터 이미 가장 큰값이 이동해 있기 때문이다.
			if(array[j] > array[j + 1]) { // 현재 값이 옆에 값과 비교했을때 더 클경우만 서로 위치를 바꿔줌 
				temp = array[j]; // 현재 값을 넣고
				array[j] = array[j + 1]; // 현재 인덱스에 큰값을 넣준다음 
				array[j + 1] = temp; // 큰값이 있던 인덱스에 작은 값을 넣어줌 
			}
		}
	}

	for(i = 0; i < 10; i++) {
		printf("%d ", array[i]);
	}
	return 0;
}

/*
	단순히 반복적으로 두 숫자를 비교하여 앞으로 보냅니다. 
	이 과정에서 각 싸이클마다 가장 큰 값이 맨 뒤로 보내지게 됩니다. 
	컴퓨터 내부적인 연산이 가장 비효율적으로 일어나게 되어 실제 수행시간이 가장 느린 안 좋은 알고리즘이라고 할 수 있습니다. 
	시간 복잡도는 선택 정렬과 동일합니다.
	
	버블 정렬의 시간 복잡도는 O(N^2)입니다.
	=> 10 + 9 + 8+ 7 + ... + 1
	=> N * (N + 1) / 2
	=> 55
	더하기나 나누기와 같은 연산은 N이 굉장히 크다고 가정 했을때 다 의미가 없기 때문에
	=> O(N^2)
	
	선택정렬과 동일한 시간 복잡도를 가지고 있다. 
	
	하지만 실제로 버블정렬을 작동시키면  선택정렬보다 휠씬 느리게 작동함 
	이유는 버블정렬은 당장의  옆에 있는것과 비교를 해서  계속해서 자리를 바꾸는 연산을 수행하는데 
	자리를 바꾸는 연산은 총 3개의 명령어를 사용하기 때문에 실제로 컴퓨터가 작업을 해줘야하는 양이 많다. 
	
	선택정렬과 같은 경우에는 가장 작은 것을 하나 골라서 마지막에만 교체를 해주지만 
	버블정렬 같은 경우는 매번 교체를 해줘야 한다는 점에서 실제로는 훨씬 더 비효율적이다.
	그렇기 때문에 기본적으로 시간복잡도는 선택정렬과 동일하지만 실제 수행시간을 분석했을때
	선택정렬보다 훨씬 느리다는 특징을 가진다. 
	
	일반적으로 정렬알고리즘 중에서 가장느린게 버블정렬 
	
	선택정렬은 한번 반복을 할 떄마다 가장 작은 값을 min이라는 변수에 저장을 해야하는데
	버블정렬은 그럴 필요가 없어 코드는 더 간단하지만 수행시간은 선택정렬에 비해서
	오래 걸린다. 
*/
