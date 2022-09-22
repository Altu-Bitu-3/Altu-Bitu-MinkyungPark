#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

string palindrome(vector<int> &alpha) { // 팰린드롬을 출력할 함수
	int odd = 0;
	string str=""; // 팰린드롬을 저장할 문자열
	string odd_str =""; // 홀수만큼 나오는 문자열을 저장할 문자열
	string str2 = ""; // 팰린드롬 앞부분을 거꾸로 정렬하여 저장할 문자열
	for (int i = 0; i < alpha.size(); i++) {
		if (alpha[i] % 2 == 1) { // 한 알파벳이 홀수번 나왔을 때
			if (++odd > 1) { // 홀수번 나온 횟수를 저장하고 1 초과일 경우 반복문 종료
				break;
			}
			odd_str += (i+'A'); // 홀수가 하나만 나왔다면 odd_str에 문자 저장
			alpha[i] -= 1; // 홀수번 나온 문자배열을 하나 줄여 짝수로 맞추어준다.
		}
	}
	if (odd > 1) { // odd가 2 이상일 경우 팰린드롬이 될 수 없으므로 I'm Sorry Hansoo 출력
		return "I'm Sorry Hansoo";
	}
	for (int i = 0; i < alpha.size(); i++) { // 아닐 경우 팰린드롬 문자열인 str에 사전순서대로 삽입
		if (alpha[i] > 0) { // 원래 문자열에서 그 알파벳이 1번 이상 나왔을 경우
			for (int j = 0; j < (alpha[i] / 2); j++) { // 알파벳 횟수의 1/2 만큼을 str에 저장
				str += (i + 'A');
			}
		}	
	}

	str2 = str; // str2에 str을 대입하고
	reverse(str2.begin(), str2.end()); // str2를 거꾸로 정렬한다.
	str += odd_str; // 중간 문자열을 넣고 (홀수번 나온 문자)
	str += str2; // str 과 str2를 병합하면 팰린드롬 문자열 완성
	
	return str;
}

int main() {
	string str;
	vector<int> alpha(26);
	cin >> str; // 문자열을 입력받는다.

	for (int i = 0; i < str.size(); i++) {
		alpha[str[i] - 'A']++; // alpha의 인덱스는 정수이기 때문에 문자에서 대문자 A만큼 빼주면 정수가 인덱스 접근 가능.
	}
	
	cout << palindrome(alpha);
	return 0;
}