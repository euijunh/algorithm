/*
	백준 2752번 문제 
	https://www.acmicpc.net/problem/2752
	세 숫자 정렬
	시간제한 : 1 초
	메모리제한 : 128 MB
	
	문제
	동규는 세수를 하다가 정렬이 하고싶어졌다.
	숫자 세 개를 생각한 뒤에, 이를 오름차순으로 정렬하고 싶어 졌다.
	숫자 세 개가 주어졌을 때, 가장 작은 수, 그 다음 수, 가장 큰 수를 
	출력하는 프로그램을 작성하시오.
	
	입력
	숫자 세 개가 주어진다. 
	이 숫자는 1보다 크거나 같고, 1,000,000보다 작거나 같다. 
	이 숫자는 모두 다르다.
	
	출력
	제일 작은 수, 그 다음 수, 제일 큰 수를 차례대로 출력한다. 
	
	예제입력
	3 1 2

	예제출력
	1 2 3

	선택정렬 사용 
*/

#include <stdio.h>

int array[3];

int main(void) {
	int i, j, min, index, temp;
	for(i = 0; i < 3; i++) {
		scanf("%d", &array[i]);
	}
	for(i = 0; i < 3; i++) {
		min = 1000001;
		for(j = i; j < 3; j++) {
			if(min > array[j]) {
				min = array[j];
				index = j;
			}
		}
		temp = array[i];
		array[i] = array[index];
		array[index] = temp;
	}
	for(i = 0; i < 3; i++) {
		printf("%d ", array[i]);
	}
	return 0;
}
