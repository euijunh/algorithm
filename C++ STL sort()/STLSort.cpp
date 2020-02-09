/*
	C++ STL sort() 함수
	
	우리가 공부를 해서 정렬 알고리즘을 구현해서 다양한 프로그래밍 대회 및 실무에서 활용할 수는 있을 것입니다. 
	하지만 이미 정렬은 컴퓨터 공학의 오래된 연구 분야이므로 이미 아주 훌륭한 정렬 관련 라이브러리가 존재합니다. 
	굳이 우리가 만들 필요 없이 가져다 쓰면 되는 것입니다. 문법만 알고 있다면 알아서 우수한 시간복잡도로 실행됩니다.
	그래서 문법만 공부하면 됩니다. 

	( 물론 내부 정렬 원리를 모르고 무작정 라이브러리를 가져다 쓰는 것은 옳지 못하므로 
	퀵 정렬, 병합 정렬에 대해 이해가 우선입니다. ) 
	
	sort() 함수의 기본 사용법
	sort() 함수는 C++의 algorithm 헤더에 포함되어 있습니다. 
	기본 사용법은 다음과 같습니다.
*/
/*
#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int a[10] = {9, 3, 5, 4, 1, 10, 8, 6, 7, 2};
	sort(a, a + 10);
	for(int i = 0; i < 10; i++) {
		cout << a[i] << ' ';
	}
}
*/
/*
	이제부터 C++ 문법을 씁니다. 
	C++은 C와 굉장히 흡사한 구조를 가지고 있고,
	C에 객체 지향 프로그래밍 기법을 더한 문법입니다. 
	
	sort() 함수는 기본적으로 오름차순 정렬을 수행합니다. 
	위와 같이 배열의 시작점 주소와 마지막 주소를 적으면 됩니다. 
	단순히 sort(a, a + 10);를 해주는 것만으로도 총 10개의 원소가 있는 배열 a를 정렬해주는 것입니다.
*/
/*
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
	return a < b;
} 

int main(void) {
	int a[10] = {9, 3, 5, 4, 1, 10, 8, 6, 7, 2};
	sort(a, a + 10, compare);
	for(int i = 0; i < 10; i++) {
		cout << a[i] << ' ';
	}
}
*/
/*
	  위 소스코드는 기본적인 sort() 함수의 숨겨진 부분까지 쓴 것입니다. 
	sort() 함수가 좋은 이유는 정렬의 기준을 자신이 원하는 형태로 설정할 수 있다는 점입니다. 
	위와 같이 compare() 함수를 만들어서 sort()의 세 번째 인자 값으로 넣게 되면, 해당 함수의 반환 값에 
	맞게 정렬이 동작합니다. 
	
	sort() 함수는 기본적으로 오름차순으로 정렬되기 떄문에 
	위 소스코드의 실행 결과는 앞서 다룬 소스코드와 동일합니다. 
*/
/*
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
	return a > b;
} 

int main(void) {
	int a[10] = {9, 3, 5, 4, 1, 10, 8, 6, 7, 2};
	sort(a, a + 10, compare);
	for(int i = 0; i < 10; i++) {
		cout << a[i] << ' ';
	}
}
*/
/*
	위와 같이 변수 a와 b를 비교하는 부분에서 반환 값만 큰(Greater, >)으로 바꾸어주시면 
	내림차순 정렬로 변환되는 것을 확인할 수 있습니다. 
	(크다는 것의 기준은 '왼쪽이 오른쪽에 비해서'를 기준으로 삼습니다.) 
	즉, 두 개의 데이터를 비교함에 있어서 왼쪽에 있는 것이 더 클 수 있도록 정렬하겠다는 소리입니다. 
	따라서 내림차순 정렬이 수행되는 것입니다.

	데이터를 묶어서 정렬하는 방법

	 기본적으로 위와 같은 단순 데이터 정렬 기법은 실무에서 사용하기에 적합하지 않습니다. 
	실무에서 프로그래밍을 할 때는 모든 데이터들이 객체로 정리되어 내부적으로 
	여러 개의 변수를 포함하고 있기 때문입니다. 
	이 경우 가장 중요한 정렬 방식은 '특정한 변수를 기준으로' 정렬하는 것입니다. 
	
	아래의 소스코드를 보겠습니다. 
*/
/*
#include <iostream>
#include <algorithm>

using namespace std;

class Student {
public:
	string name;
	int score;
	Student(string name, int score) {
		this->name = name;
		this->score = score;
	}
	// 정렬 기준은 '점수가 작은 순서' 
	bool operator <(Student &student) {
		return this->score < student.score;
	}
};

bool compare(int a, int b) {
	return a > b;
} 

int main(void) {
	Student students[] = {
		Student("홍길동", 90),
		Student("이민우", 93),
		Student("강한울", 97),
		Student("이국수", 87),
		Student("남도일", 92)
	};
	sort(students, students + 5);
	for(int i = 0; i < 5; i++) {
		cout << students[i].name << ' ';
	}
}
*/
/*
	위 소스코드를 보면 왜 실생활에서 가장 많이 사용된다는 것인지 알 수 있습니다. 
	위 소스코드는 점수를 기준으로 학생을 정렬해서 이름을 출력하는 겁니다. 
	이를 퀵 정렬, 병합 정렬 등의 함수 안에서 구현하고자 하면 굉장히 복잡해질 수 있는데, 
	sort() 함수의 문법을 지키면서 구현하는 것은 위와 같이 클래스를 이용해 작업하면 됩니다. 
	출력 결과는 다음과 같습니다.
	
	이국수 홍길동 남도일 이민우 강한울 
*/



/*
	위에서  클래스(Class)를 정의해서 여러 개의 변수가 존재하는 상황에서 
	'특정한 변수'를 기준으로 정렬하는 방법에 대해 알아보았습니다. 
	그러나 클래스를 정의하는 방식은 프로그래밍 속도 측면에서 별로 유리하지 않습니다. 
	실제 대회에서 문제 하나를 풀기 위해 클래스를 정의하고 있는 것은 적절치 못합니다. 
	쉽게 말해 클래스를 이용하는 방식은 실무에 적합한 방식이며, 일반적으로 프로그래밍 대회와 같이 
	빠른 개발이 필요할 때는 페어(Pair) 라이브러리를 사용하는 것이 더 효율적입니다. 
*/
/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	vector<pair<int, string> > v;
	v.push_back(pair<int, string>(90, "강한울"));
	v.push_back(pair<int, string>(85, "이민우"));
	v.push_back(pair<int, string>(82, "홍길동"));
	v.push_back(pair<int, string>(98, "남도일"));
	v.push_back(pair<int, string>(79, "이국수"));
	
	sort(v.begin(), v.end());
	for(int i = 0; i < v.size(); i++) {
		cout << v[i].second << ' ';
	}
	return 0;
}
*/
/*
	위 소스코드는 벡터(Vector) 라이브러리와 페어(Pair) 라이브러리를 이용해 위에서 
	배열과 클래스를 이용했던 방식을 대체한 겁니다. 
	주로 이렇게 소스코드의 길이를 짧게 해주는 기법을 숏코딩(Short Coding)이라고 합니다. 
	작성한 소스코드의 시간 복잡도가 동일하다면, 
	프로그래밍 대회에서는 소스코드가 짧을 수록 남들보다 앞서있을 수 있습니다.

	벡터(Vector) STL은 마치 배열과 같이 작동하는데 원소를 선택적으로 삽입(Push) 및 삭제(Pop)을 할수 있답니다. 
	즉 단순한 배열을 보다 사용하기 쉽게 개편한 자료구조라고 할 수 있습니다. 
	페어(Pair) STL은 한 쌍의 데이터를 처리할 수 있도록 해주는 자료구조라고 할 수 있습니다. 
	이러한 STL을 적절하게 혼용하는 방법이 소스코드를 획기적으로 단축시킬 수 있습니다.
	
	위에서는 변수가 2개일 때 '한 개'의 변수를 기준으로 정렬하는 방법에 대해 알아보았습니다. 
	이번에는 이어서 변수가 3개일 때 '두 개'의 변수를 기준으로 정렬하는 방법에 대해서 알아보겠습니다. 
	바로 다음의 문제를 풀어보겠습니다. 
	
	학생을 나타낼 수 있는 정보가 이름, 성적, 생년월일일 때 학생을 성적 순서대로 나열하고자 한다. 
	다만 성적이 동일한 경우 나이가 더 어린 학생이 더 우선순위가 높다.
	
	위 요구사항을 처리하는 프로그램은 어떻게 작성할 수 있을까요? 바로 기준이 두 개인 것입니다. 
	이 경우 또한 벡터(Vector)와 페어(Pair) STL을 이용해서 몹시 짧은 코드로 작성할 수 있습니다.

	< 학생 명단 >
	
	학생 1: 강한울/90점/1996-12-22
	학생 2: 이민우/97점/1993-05-18
	학생 3: 홍길동/95점/1993-02-03
	학생 4: 남도일/90점/1992-12/07
	학생 5: 이국수/88점/1990-03-02
	
	정상적으로 위 학생들을 정렬하려면 먼저 성적에 따라서 정렬을 하고, 
	성적이 같은 경우 나이가 더 어린 사람이 먼저 출력되면 됩니다. 
	예를 들어 강한울과 남도일은 모두 90점이지만 더 나이가 어린 강한울이 먼저 출력이 되어야 합니다. 
	소스코드를 작성하면 다음과 같습니다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<string, pair<int, int> > a,
			 pair<string, pair<int, int> > b) {
	if(a.second.first == b.second.first) {
		return a.second.second > b.second.second;
	} else {
		return a.second.first > b.second.first;
	}
} 

int main(void) {
	vector<pair<string, pair<int, int> > > v;
	v.push_back(pair<string, pair<int, int> >("강한울", make_pair(90, 19961222)));
	v.push_back(pair<string, pair<int, int> >("이민우", make_pair(97, 19930518)));
	v.push_back(pair<string, pair<int, int> >("홍길동", make_pair(95, 19930203)));
	v.push_back(pair<string, pair<int, int> >("남도일", make_pair(90, 19921207)));
	v.push_back(pair<string, pair<int, int> >("이국수", make_pair(88, 19900302)));
	
	sort(v.begin(), v.end(), compare);
	for(int i = 0; i < v.size(); i++) {
		cout << v[i].first << ' ';
	}
	return 0;
}

/*
	실행 결과는 다음과 같습니다.
	 이민우 홍길동 강한울 남도일 이국수 
	
	sort() 함수는 이 정도로 세 개의 변수까지만 자유자재로 다룰 수 있는 정도면 
	실제 실무에서나 혹은 프로그래밍 대회에서나 정렬 때문에 골머리를 앓는 경우는 없습니다. 
*/






