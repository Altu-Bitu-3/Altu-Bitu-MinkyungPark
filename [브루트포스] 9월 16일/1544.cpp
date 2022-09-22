#include<iostream>
#include<string>
#include<algorithm>
#include<set>

using namespace std;

void findWord(set<string>& word,string s) {
	for (auto iter : word) {
		if (iter.size() != s.size()) {// 새로 입력받은 단어와 set에 들어있는 단어의 갯수가 다를 경우
			continue;
		}
		for (int i = 0; i < s.size(); i++) {
			if (iter == s) { // 문자열이 word에 저장되어 있는 iter와 같으면 insert없이 return
				return;
			}
			rotate(s.begin(), s.begin() + 1, s.end()); // rotate 함수를 이용하여 문자열의 시작을 맨 끝으로 보낸다.
		}
	}
	word.insert(s); // set 을 다 돌았는데도 같은 문자열을 찾지 못했다면 새로 insert
	return;
}

int main() {
	int n;
	string s;
	cin >> n;

	set<string> word;

	for (int i = 0; i < n; i++) {
		cin >> s;

		findWord(word, s);
	}

	cout << word.size();

	return 0;
}