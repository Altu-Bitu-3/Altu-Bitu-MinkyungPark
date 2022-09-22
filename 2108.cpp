#include<iostream> // 입출력 받기 위한 헤더파일
#include<vector> // vector 쓰기 위한 헤더파일
#include<algorithm> //sort함수를 쓰기 위한 헤더파일
#include<cmath> // 올림, 반올림, 내림 등의 연산을 쓰기 위한 헤더파일
/*
	cmath에서는 올림(ceil), 반올림(round), 내림(floor) 연산 등을 제공합니다
*/
/*
* 힌트: 각 값을 구하기 위해 어떤 작업이 필요할까요? 앞에서 배운 내용을 복습해 봅시다~
* 입력값의 범위에 주목해주세요!
* -0을 나타내는 자료형은 없어요.
*/
using namespace std; // std 클래스에 정의되어 있는 함수들을 사용하기 위해 선언

const int SCOPE = 4000; //입력되는 정수의 최대 절댓값
typedef pair<int, int> pi; //pair : 사용자가 지정한 두 개의 타입 데이터를 저장하는데 사용하는 클래스

// 비교함수
bool cmp(const pi& a, const pi& b) { // sort에서 쓸 비교함수, pi 형 인자 두 개를 받아옴
	//개수(second)에 대해 내림차순, 값(first)에 대해 오름차순으로 정렬
	if (a.second != b.second) { //개수(second)가 다를 경우
		return a.second > b.second; // 개수에 대해 내림차순으로 정렬
	}
	return a.first < b.first; // 개수가 같을 경우 값에 대해 오름차순으로 정렬
}

int findMode(vector<pi>& frequency) { //정렬된 벡터에서 최빈값을 찾아 반환하는 함수
	//최빈값이 여러 개라면 두번째로 작은 값을 반환

	//개수에 대해 내림차순, 값에 대해 오름차순으로 정렬
	sort(frequency.begin(), frequency.end(), cmp); // sort함수를 이용하여 frequency 벡터를 정렬한다. 정렬방식은 cmp 함수를 만들어서 설정해줌.

	//최빈값이 여러개인지 확인
	if (frequency[0].second == frequency[1].second) { //빈도수가 같은 수가 있다면
		return frequency[1].first; //두번째로 작은값을 반환해야하므로 오름차순 정렬되어있는 벡터의 두번째 값 반환
	}
	return frequency[0].first; //빈도수가 가장 많은 수가 유일하다면 제일 첫 번째 값 반환
}

int main() { // 산술평균, 중앙값, 최빈값, 범위를 출력하는 main 함수
	int n; // 수의 개수를 입력받아 저장할 변수, n은 홀수이다.
	double sum = 0.0; // 입력된 숫자의 합, 산술평균을 구할 때 이용하므로 double형으로 선언

	cin >> n; // 입력할 수의 개수를 입력받음
	vector<int> v(n); // 크기 n만큼의 벡터 선언, 사용자가 입력하는 수를 차례로 저장할 벡터이다.
	vector<pi> frequency(2 * SCOPE + 1); // 음수와 양수, 0이 있기 때문에(절댓값 *2 +1)의 크기로 만든다.
	// 정수의 값와 해당 정수 개수를 pair로 묶어서 저장
	//기본적으로 0으로 초기화된다
	//각 pair는 first, second로 접근 가능

	for (int i = 0; i < n; i++) { // n번 입력을 반복해서 받는다.
		cin >> v[i]; // i번 째 벡터에 수를 입력받아 저장한다.
		sum += v[i]; // sum에 더하여 입력된 수의 합을 구한다.
		frequency[v[i] + SCOPE].first = v[i]; //first: 값
		frequency[v[i] + SCOPE].second++; //second: 개수
	}
	sort(v.begin(), v.end()); // 사용자가 입력한 수를 오름차순 정렬

	//출력
	cout << (int)round(sum / n) << '\n'; //산술평균: -0 안나오게 유의, round로 반올림한 후 int로 형변환
	cout << v[n / 2] << '\n'; //중앙값, 오름차순으로 정렬되어있는 벡터의 중간 인덱스 접근하여 출력
	cout << findMode(frequency) << '\n';	//최빈값, findMode함수를 호출하여 frequency 벡터를 정렬하고 최빈값 return받아 출력
	cout << v[n - 1] - v[0] << '\n'; //범위 정렬된 벡터의 최대값에서 최소값을 빼서 출력

	return 0;
}