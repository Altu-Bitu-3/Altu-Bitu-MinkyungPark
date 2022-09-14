#include<iostream>
#include<queue>


using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	queue<int> q;

	cin >> n;
	//ť ����
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	//�似Ǫ�� ���� ���
	cin >> k;
	cout << '<';
	while (q.size() != 1) {
		for (int i = 1; i < k; i++) { //k-1��ŭ �ݺ�
			q.push(q.front()); // �� ���� �� �ڷ� push
			q.pop(); // �� �� ����
		}
		cout << q.front() << ", ";
		q.pop();
	}
	//������ ���
	cout << q.front() << '>';

	return 0;
}