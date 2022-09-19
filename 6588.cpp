#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

void is_Prime(int n, vector<bool>& is_prime) {
	//0과 1은 소수가 아니므로 false
	is_prime[0] = is_prime[1] = false;
	// 2~제곱근 n 까지 검사
	for (int i = 2; i <= sqrt(n); i++) {
		if (is_prime[i]) { //i가 소수이면
			for (int j = i * i; j <= n; j += i) {
				is_prime[j] = false; // i의 배수 false
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<bool> is_prime(1e6 + 1,true);
	int n;
	is_Prime(1e6 + 1, is_prime); // 배열의 소수를 구해놓는다.
	while (true) { // 무한루프
		int a,b;
		bool find = false;
		cin >> n;
		if (n == 0) { // 0이 입력되면 반복문 종료
			break;
		}
		for (int i = 1; i < n / 2; i++) {
			a = 2 * i + 1; //3 이상의 홀수
			b = n - a;
			if (is_prime[a] && is_prime[b]) { // a와 b가 둘다 소수면 출력후 find를 true로 바꾸고 break
				cout << n << " = " << a << " + " << b <<'\n';
				find = true;
				break;
			}
		}
		if (!find) { // 만약 찾지 못했을 경우 문자열 출력
			cout << "Goldbach's conjecture is wrong.";
		}
	}
	return 0;
}
