/*
	KMP(Knuth-Morris-Pratt) 알고리즘

	KMP 알고리즘으로 대표적인 문자열(String) 매칭 알고리즘입니다. 
	기본적으로 문자열 매칭 알고리즘이란 특정한 글이 있을 때 
	그 글 안에서 하나의 문자열을 찾는 알고리즘입니다. 
	KMP에 대해서 다루기 전에 먼저 단순 비교 문자열 매칭 알고리즘을 보겠습니다. 
	단순 비교 알고리즘은 말 그대로 하나씩 확인하는 
	알고리즘으로 가장 간단한 형태의 알고리즘입니다.

	1. 단순 비교 문자열 매칭 알고리즘
	
	긴 글(Parent)이 ABCDEF이고 찾을 문자열이 DEF라면 다음과 같은 방식으로 찾을 수 있습니다.
	
	긴           글	B	C	D	E	F
	찾을 문자열		D	E			
	
	먼저 찾을 문자열인 DE를 가장 앞 부분에 위치시키고 확인합니다. 
	매칭이 이루어지지 않았으므로 한 칸 이동시킵니다. 
	이후에는 다음과 같이 비교를 할 수 있게 됩니다.
	
	긴           글	B	C	D	E	F
	찾을 문자열			D	E		
	
	마찬가지로 매칭이 이루어지지 않았으므로 
	한 칸 더 이동하여 다음과 같이 배치하여 확인합니다.
	
	긴           글	B	C	D	E	F
	찾을 문자열				D	E	
	
	위와 같이 매칭한 경우 정확히 매칭이 이루어진 것을 알 수 있습니다. 
	이러한 방식을 이용하면 O(N * M)의 시간 복잡도를 가지게 됩니다. 
	효율적이지는 않지만 매우 직관적이고 코드 작성이 쉽습니다.

#include <iostream>

using namespace std;

int findString(string parent, string pattern) {
	int parentSize = parent.size();
	int patternSize = pattern.size();
	for(int i = 0; i <= parentSize - patternSize; i++) {
		bool finded = true;
		for(int j = 0; j < patternSize; j++) {
			if(parent[i + j] != pattern[j]) {
				finded = false;
				break;
			}
		}
		if(finded) {
			return i;
		}
	}
	return -1;
}

int main(void) {
	string parent = "Hello World";
	string pattern = "llo W";
	int result = findString(parent, pattern);
	if(result == -1) {
		printf("찾을 수 없습니다.");
	} else {
		printf("%d번째에서 찾았습니다.", result + 1);
	}
	return 0; 
}

3번째에서 찾았습니다. 출력 

----------------

	2. KMP(Knuth-Morris-Pratt)
	
	위와 같이 단순하게 모든 경우를 다 비교하는 경우는 
	최악의 경우 엄청난 시간이 소요될 수 있습니다. 
	예를 들어 길이가 10,000,000인 글에서 길이가 1,000인 부분 문자열을 
	찾으려는 경우 연산 양이 10,000,000,000이기 때문입니다. 
	따라서 모든 경우를 다 비교하지 않아도 부분 문자열을 
	찾을 수 있는 KMP 알고리즘을 사용해야 합니다.

	KMP 알고리즘은 접두사와 접미사의 개념을 활용하여 
	'반복되는 연산을 얼마나 줄일 수 있는지'를 판별하여 
	매칭할 문자열을 빠르게 점프하는 기법입니다. 
	일단 접두사와 접미사는 말 그대로 앞에 있는 문자열과 
	뒤에 있는 문자열을 의미합니다. 
	예를 들어 abacaaba가 있을 때 다음과 같습니다.

	a b a c a a b a
	접두사   접미사
	a b a    a b a
	
	우리가 구해야 할 것은 위와 같이 접두사와 접미사가 일치하는 최대 길이입니다.

	길이	문자열		최대 일치 길이
	1		a			0
	2		ab			0
	3		aba			1
	4		abac		0
	5		abaca		1
	6		abacaa		1
	7		abacaab		2
	8		abacaaba	3

	위와 같이 접두사와 접미사를 구하게 되면 접두사와 접미사가 일치하는 경우에 한해서는 
	점프(Jump)를 수행할 수 있다는 점에서 몹시 효율적입니다. 
	위와 같은 접두사와 접미사의 최대 일치 길이를 구하는 방법은 아래와 같습니다. 
	
#include <iostream>
#include <vector> 

using namespace std;

vector<int> makeTable(string pattern) {
	int patternSize = pattern.size();
	vector<int> table(patternSize, 0);
	int j = 0;
	for(int i = 1; i < patternSize; i++) {
		while(j > 0 && pattern[i] != pattern[j]) {
			j = table[j - 1];
		}
		if(pattern[i] == pattern[j]) {
			table[i] = ++j;
		}
	}
	return table;
}

int main(void) {
	string pattern = "abacaaba";
	vector<int> table = makeTable(pattern);
	for(int i = 0; i < table.size(); i++) {
		printf("%d ", table[i]);
	}
	return 0; 
}


	위와 같이 하나씩 접두사와 접미사를 늘려가며 비교하다가 일치하지 않는 
	경우가 발생하면 일치했던 부분까지 되돌아가서 다시 검사를 
	하는 방식으로 빠르게 '최대 일치 길이' 테이블을 구축할 수 있습니다. 
	이제 이렇게 테이블을 구축한 뒤에는 다음과 같이 문자열 매칭을 수행할 수 있습니다.
	
	긴           글: ababacabacaabacaaba
	찾을 문자열	   : abacaaba
	
	위와 같이 긴 글과 찾을 문자열이 있을 때 테이블이 구축이 
	되어있을 때 다음과 같이 찾을 수 있습니다.
	
	
	a	b	a	b	a	c	a	b	a	c	a	a	b	a	c	a	a	b	a
	a	b	a	c	a	a	b	a			
									
	먼저 긴 글과 찾을 문자열을 하나씩 비교합니다.
	
	a	b	a	b	a	c	a	b	a	c	a	a	b	a	c	a	a	b	a
	a	b	a	c	a	a	b	a											
	a	b	a	b	a	c	a	b	a	c	a	a	b	a	c	a	a	b	a
	a	b	a	c	a	a	b	a		
										
	계속 같은 문자가 나오므로 넘어갑니다.
	
	a	b	a	b	a	c	a	b	a	c	a	a	b	a	c	a	a	b	a
	a	b	a	c	a	a	b	a	
											
	위와 같이 서로 다른 문자가 발견되면 일치하는 
	다음과 같이 접두사 크기에 한해서만 
	부분 문자열의 인덱스를 이동시킵니다. 
	
	a	b	a	b	a	c	a	b	a	c	a	a	b	a	c	a	a	b	a
	a	b	a	c	a	a	b	a				
								
	기본적으로 ab까지는 여전히 일치하다는 점을 이용한 것입니다.
	
	a	b	a	b	a	c	a	b	a	c	a	a	b	a	c	a	a	b	a
	a	b	a	c	a	a	b	a	
											
	다시 위와 같이 하나씩 비교합니다. 이제 이런식으로 일치하지 않을 때는 
	접두사가 일치하는 한 가장 큰 길이만큼만 이동시켜 나갑니다. 
	결과적으로 계속 진행하여 다음과 같은 경우에서 끝납니다.
	
	a	b	a	b	a	c	a	b	a	c	a	a	b	a	c	a	a	b	a
	a	b	a	c	a	a	b	a	
											
	또한 발견한 경우에도 접두사가 일치하는 한 가장 큰 길이만큼만 
	이동시키는 식으로 반복하면 매칭되는 모든 문자열을 찾을 수도 있습니다.
*/

#include <iostream>
#include <vector> 

using namespace std;

// 접두사와 접미사의 촤대길이 구하는 함수 
vector<int> makeTable(string pattern) {
	int patternSize = pattern.size(); // 찾는 문자열의 길이 
	vector<int> table(patternSize, 0); // 문자열의 크기만큼 0으로 초기화 
	int j = 0;
	// 모든 문자를 하나씩 검사를 하면서  
	for(int i = 1; i < patternSize; i++) {
		while(j > 0 && pattern[i] != pattern[j]) {
			// j가 0이 아니면서 i번째 문자와 j번째 문자가 일치하지 않는다면
			// j위치에서 1을 뺀 인덱스의 테이블 값으로 j값을 변경 
			j = table[j - 1];
		}
		// i번째 인덱스의 값과 j번째 인덱스의 값이 일치할 경우 
		if(pattern[i] == pattern[j]) {
			// 현재 j 위치에 1을 더한 값이 테이블의 i번째 인덱스의 값으로 들어감 
			table[i] = ++j;
		}
	}
	return table;
}

void KMP(string parent, string pattern) {
	vector<int> table = makeTable(pattern);
	int parentSize = parent.size(); // 전체 문자열의 길이 
	int patternSize = pattern.size(); // 찾는 문자열의 길이 
	int j = 0;
	for(int i = 0; i < parentSize; i++) {
		while(j > 0 && parent[i] != pattern[j]) { // 일치하지 않는 경우 
			// j를 현재 위치에서 1을 뺀 값이 가르키는 값으로 바꿔줌, 이전단계의 값으로 이동 
			j = table[j - 1];
		}
		if(parent[i] == pattern[j]) {
			if(j == patternSize - 1) { // 모든 문자열이 매치이 된 경우 
				printf("%d번째에서 찾았습니다.\n", i - patternSize + 2);
				// 테이블에서 j가 가르키는 위치만큼 점프를 할 수 있도록 j 값을 갱신
				// 매칭이 이루어지는 모든 위치를 찾기 위해서이다. 
				j = table[j];
			} else {
				j++;
			}
		}
	}
}

int main(void) {
	string parent = "ababacabacaabacaaba";
	string pattern = "abacaaba";
	KMP(parent, pattern);
	return 0; 
}
