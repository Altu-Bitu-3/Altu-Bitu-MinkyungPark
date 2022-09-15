#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	long tip = 0;
	cin >> n;
	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end(), greater<>());

	for (int i = 0; i < n; i++) {
		if (arr[i] - i < 0)
			break;
		tip += (arr[i] - i);
	}

	cout << tip;

	return 0;

}