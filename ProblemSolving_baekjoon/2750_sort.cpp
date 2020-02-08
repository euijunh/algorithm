/*
	백준 2750번 문제 
	수 정렬하기
	시간제한 : 1 초
	메모리제한 : 128 MB
	
	문제
	N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.
	
	입력
	첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000)이 주어진다. 
	둘째 줄부터 N개의 줄에는 숫자가 주어진다. 
	이 수는 절댓값이 1,000보다 작거나 같은 정수이다. 수는 중복되지 않는다.
	
	출력
	첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다. 
	
	예제입력제 
	5
	5
	2
	3
	4
	1 
	
	일반적으로 온라인 체점 시스템은 대략 1초에 1억번정도 연산이 가하다고 가정하고 풀면 된다. 
	그러므로 가장 기초적이고 비효율적인 선택정렬로 풀이해도 문제가 없다. 
*/

#include <stdio.h>
int arr[1001];

int main(void) {
int i, j, min, index, arr_len, temp;
	scanf("%d", &arr_len);

	for(i = 0; i < arr_len; i++){
		scanf("%d", &arr[i]);
	}

	for(i = 0; i < arr_len; i++){
		min = 99999;
		for(j = i; j < arr_len; j++){
			if(min > arr[j]){
				min = arr[j];
				index = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[index];
		arr[index] = temp;
	}

	for(i = 0; i < arr_len; i++){
		printf("%d \n", arr[i]);
	}
}
