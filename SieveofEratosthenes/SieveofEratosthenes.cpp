/*
	에라토스테네스의 체 Sieve of Eratosthenes
	
	에라토스테네스의 체는 가장 대표적인 소수(Prime Number) 판별 알고리즘입니다. 
	소수란 '양의 약수를 두 개만 가지는 자연수'를 의미하며 2, 3, 5, 7, 11, ... 등이 존재합니다. 
	이러한 소수를 대량으로 빠르고 정확하게 구하는 방법이 에라토스 테네스의 체라고 할 수 있습니다. 
	일단 에라토스테네스의 체를 공부하기 전에 간단하게 소수를 판별하는 알고리즘을 작성해봅니다. 

#include <stdio.h>

bool isPrimeNumber(int x) {
	for(int i = 2; i < x; i++) {
		if(x % i == 0) return false;
	}
	return true;
}

int main(void)
{
	printf("%d", isPrimeNumber(97));
	return 0;
}

	위와 같이 알고리즘을 작성하는 경우 소수 판별 알고리즘의 시간 복잡도는 O(N)입니다. 
	모든 경우의 수를 다 돌며 약수 여부를 확인한다는 점에서 몹시 비효율적입니다. 
	사실은 O(N^(1/2))로 손쉽게 계산할 수 있습니다. 
	왜냐하면 예를 들어 8의 경우 2 * 4 = 4 * 2와 같은 식으로 대칭을 이루기 때문입니다. 
	그러므로 특정한 숫자의 제곱근까지만 약수의 여부를 검증하면 됩니다.

#include <stdio.h>
#include <math.h>

bool isPrimeNumber(int x) {
	int end = (int) sqrt(x);
	for(int i = 2; i <= end; i++) {
		if(x % i == 0) return false;
	}
	return true;
}

int main(void)
{
	printf("%d", isPrimeNumber(97));
	return 0;
}

	다만 이렇게 한 두 개의 소수를 판별하는 것이 아니라 대량의 소수를 
	한꺼번에 판별하고자 할 때 사용하는 것이 바로 에라토스테네스의 체입니다. 
	에라토스테네스의 체는 가장 먼저 소수를 판별할 범위만큼 배열을 할당에 
	그 인덱스에 해당하는 값을 넣어줍니다. 예를 들어 1부터 25까지 판별한다고 해봅시다.
	
	1. 이차원 배열을 생성하여 값을 초기화합니다.
	
	2. 2부터 시작해서 특정 숫자의 배수에 해당하는 숫자들을 모두 지웁니다.
		먼저 2의 배수를 지워봅시다. (자기 자신은 지우지 않습니다.)
		이제 3의 배수를 지워봅시다. (자기 자신은 지우지 않습니다.)
	
	3. 이미 지워진 숫자의 경우 건너뜁니다.
		4는 이미 지워져있으므로 지우지 않고 건너 뜁니다. 이제 이러한 과정을 반복합시다.
		결과적으로 모두 지워졌습니다.

	4. 2부터 시작하여 남아있는 숫자들을 출력합니다.

	출력: 2 3 7 11 13 17 19 23

	따라서 성공적으로 소수를 판별할 수 있습니다.
*/

#include <stdio.h>

int number = 100000;
int a[100001];

void primeNumberSieve() {
   for(int i = 2; i <= number; i++) {
      a[i] = i;
   }
   for(int i = 2; i <= number; i++) {
      if(a[i] == 0) continue;
      for(int j = i + i; j <= number; j += i) {
         a[j] = 0;
      }
   }
   for(int i = 2; i <= number; i++) {
      if(a[i] != 0) printf("%d ", a[i]);
   }
} 

int main(void) {
   primeNumberSieve();
}
