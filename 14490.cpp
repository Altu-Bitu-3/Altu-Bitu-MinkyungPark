#include<iostream> // iostream 파일을 포함하도록 지시
#include<string> // string 파일을 포함하도록 지시

using namespace std; // std 클래스에 정의되어 있는 함수들을 사용하기 위해 선언해준다.

//유클리드 호제법
int gcdRecursion(int a, int b){ // 정수 a,b를 받아와서 둘의 최대공약수를 반환해주는 함수. 이때 a>b이며 유클리드 호제법을 사용한다.
	if (b == 0) { // 유클리드 호제법은 a와 b의 최대공약수를 구하기 위하여 b와 a를 b로 나눈 나머지를 구하는 방식을 이용한다. 나머지가 0이 될 때까지 연산을 계속 반복한다.
		return a; // b가 0 일 경우, 그 때 a가 처음 두 수의 최대공약수이므로  a를 return 한다.
	}
	return gcdRecursion(b, a % b); // b가 0이 아니라면 gcdRecursion 함수를 재귀적으로 호출하여 return 한다. 
	//b와 a를 b로 나눈 나머지를 인자로 넘겨준다. 이때 넘겨주는 값의 순서는 나머지보다 b가 크므로 b, a%b이다.
	//b가 0일 때 재귀함수는 종료된다.
}

int main() { //n:m을 입력받아 두 수를 최대한으로 약분하여 출력하는 main 함수
	string s; // n:m을 입력받아 저장 할 문자열 s
	int index; // ":"의 위치를 저장할 문자열
	cin >> s; // n:m을 입력받아 s에 저장한다.

	//n,m 추출하기
	index=s.find(":"); // string::find() 함수는 찾는 문자의 첫번째 인덱스를 리턴한다. 
	int n = stoi(s.substr(0, index)); // substr: 문자열 자르는 함수, 0부터 index 길이만큼 자른다.stoi: string to int
	// : 이전의 문자를 정수로 변경
	int m = stoi(s.substr(index + 1)); // index+1 부터 마지막까지 자른다.
	// : 이후의 문자를 정수로 변경

	//최대공약수 구하기
	int g = gcdRecursion(max(n, m), min(n, m)); // n,m중 큰 수를 첫번째 인자로 넘겨주고 작은 수를 두번째 인자로 넘겨줌

	//출력
	cout << n / g << ":" << m / g; // n과 m을 g로 약분하여 출력

	return 0;
}