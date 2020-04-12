/*
	백준 1541번 문제 
	https://www.acmicpc.net/problem/1541
	잃어버린 괄호
	시간제한 : 2 초
	메모리제한 : 128 MB
	
	문제
	세준이는 양수와 +, -, 그리고 괄호를 가지고 길이가 최대 50인 식을 만들었다. 
	그리고 나서 세준이는 괄호를 모두 지웠다.
	그리고 나서 세준이는 괄호를 적절히 쳐서 이 식의 값을 최소로 만들려고 한다.
	괄호를 적절히 쳐서 이 식의 값을 최소로 만드는 프로그램을 작성하시오.
	
	입력 
	첫째 줄에 식이 주어진다. 식은 ‘0’~‘9’, ‘+’, 그리고 ‘-’만으로 이루어져 있고, 
	가장 처음과 마지막 문자는 숫자이다. 
	그리고 연속해서 두 개 이상의 연산자가 나타나지 않고, 
	5자리보다 많이 연속되는 숫자는 없다. 수는 0으로 시작할 수 있다.
	
	출력
	첫째 줄에 정답을 출력한다
	
	예제입력
	55-50+40

	예제출력
	-35
	
	이 문제를 해결하기 위해서는 마이너스(Minus)가 한 번이라도 등장한 시점부터는 
	그 뒤로 이어진 모든 숫자들은 그 부호에 상관없이 모두 마이너스로 처리할 수 있다는 특징이 있습니다. 
	따라서 마이너스가 등장하기 전까지는 숫자들을 양수로 더해주고, 
	마이너스가 등장한 순간부터는 항상 음수로 더해주도록 하여 결과 값을 출력하면 됩니다. 
*/

#include <iostream>
#include <string>

using namespace std;

string a;

int main(void) {
	cin >> a;
	int result = 0;
	string temp = "";
	bool minus = false;
	for(int i = 0; i <= a.size(); i++) {
		if(a[i] == '+' || a[i] == '-' || a[i] == '\0') {
			if(minus == true)
				result += -stoi(temp);
			else
				result += stoi(temp);
			temp = "";
			if(a[i] == '-')	minus = true;
			continue;
		}
		temp += a[i];
	}
	printf("%d", result);
	return 0;
}
