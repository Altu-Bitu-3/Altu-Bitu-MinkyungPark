#include<iostream>
#include<queue>


using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	queue<int> q;

	cin >> n;
	//큐 삽입
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	//요세푸스 순열 출력
	cin >> k;
	cout << '<';
	while (q.size() != 1) {
		for (int i = 1; i < k; i++) { //k-1만큼 반복
			q.push(q.front()); // 맨 앞을 맨 뒤로 push
			q.pop(); // 맨 앞 제거
		}
		cout << q.front() << ", ";
		q.pop();
	}
	//마지막 출력
	cout << q.front() << '>';

	return 0;
}