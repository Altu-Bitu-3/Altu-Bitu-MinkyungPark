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
	for (int i=0; i < n; i++) { // ��� �Է�
		cin >> v[i];
	}

	reverse(v.begin(), v.end()); // ��� �Ųٷ�

	// �Ųٷ� ����� ����ϸ� 1~5���� ���� ����
	for (int i = 0; i < n; i++) {
		int temp;
		if (v[i] == 1) { // ����� 1 �� ��,
			dq.push_front(num); // �� �տ� push
			num++;
		}
		if (v[i] == 2) { // ����� 2 �� ��,
			temp = dq.front(); // �� �� ���Ҹ� ������ ����
			dq.pop_front(); // �� �� ���� ����
			dq.push_front(num); // �տ� num ����
			dq.push_front(temp); // ������ ������ ���Ҵ� ���� �ٽ� �� �տ� ����
			num++;
		}
		if (v[i] == 3) { // ����� 3 �� ��,
			dq.push_back(num); // �� �ڿ� push
			num++;
		}
	}

	while (!dq.empty()) { // ���
		cout << dq.front() << ' ';
		dq.pop_front();
	}

	return 0;
}