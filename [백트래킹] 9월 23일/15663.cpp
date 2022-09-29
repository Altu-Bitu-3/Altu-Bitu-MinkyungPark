#include<iostream>
#include<vector>
#include<algorithm>
/*
 참고 블로그: https://m.blog.naver.com/js568/221857286945
 참고 내용:
 sort() 함수를 이용해서 정렬
 길이가 같은 바로 직전 수열의 마지막 항만 다른지 확인
*/

using namespace std;

const int SIZE = 8;

int n, m;
vector<int> num(SIZE);
vector<bool> check(SIZE);

void backtracking(int cnt,vector<int> &arr) {
	int pre = 0; // 이전 수열의 마지막 항을 저장하기 위한 변수
	if (cnt == m) { // 개수가 조건 m과 같으면 출력
		for (int i = 0; i < m; i++) {
			cout << num[i] << ' ';
		}
		cout << '\n';

		return;
	}
	for (int i = 0; i < n; i++) {
		if (!check[i] && arr[i] != pre) { //현재 탐색 원소와 이전 수열 마지막 항이 같지 않을 때 추가
			check[i] = true;
			num[cnt] = arr[i];
			pre = num[cnt];
			backtracking(cnt + 1,arr);
			check[i] = false;
		}

	}

}

int main() {
	cin >> n >> m;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	sort(arr.begin(), arr.end()); // 오름차순으로 정렬

	backtracking(0,arr);

	return 0;
}