#include<iostream>
#include<deque>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	deque<int> dq;
	int n,num=1;


	cin >> n;
	vector<int> v(n);
	for (int i=0; i < n; i++) { // 기술 입력
		cin >> v[i];
	}

	reverse(v.begin(), v.end()); // 기술 거꾸로

	// 거꾸로 기술을 사용하며 1~5까지 덱에 삽입
	for (int i = 0; i < n; i++) {
		int temp;
		if (v[i] == 1) { // 기술이 1 일 때,
			dq.push_front(num); // 맨 앞에 push
			num++;
		}
		if (v[i] == 2) { // 기술이 2 일 때,
			temp = dq.front(); // 맨 앞 원소를 변수에 저장
			dq.pop_front(); // 맨 앞 원소 삭제
			dq.push_front(num); // 앞에 num 삽입
			dq.push_front(temp); // 변수에 저장해 놓았던 원소 다시 맨 앞에 삽입
			num++;
		}
		if (v[i] == 3) { // 기술이 3 일 때,
			dq.push_back(num); // 맨 뒤에 push
			num++;
		}
	}

	while (!dq.empty()) { // 출력
		cout << dq.front() << ' ';
		dq.pop_front();
	}

	return 0;
}