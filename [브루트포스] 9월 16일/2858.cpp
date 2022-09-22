#include<iostream>

using namespace std;

int l, w; // 전역변수로 가로 세로 길이 변수 선언

void size(int r, int b) { // 방의 크기를 찾기 위한 size 함수
	for(l=3;;l++){ // 최소크기가 3 x 3 이므로 l = 3 부터 시작
		for (w = l; w >= 3; w--) { // w=l 일 때 부터 w의 최소 길이 3까지 하나씩 줄여가며 반복
			int tempR, tempB; // 현재 계산한 크기를 저장
			tempB = (l - 2) * (w - 2); // 가로 세로 둘 씩 뺀 나머지 넓이가 갈색 크기
			tempR = l * w - tempB; // 넓이에서 갈색을 뺀만큼이 빨간색 크기

			if (tempR == r && tempB == b) { // 계산 값이 전달된 인자와 같다면 return
				return;
			}
		}

	}
	return;

}

int main() {
	int r, b;

	cin >> r >> b;

	size(r, b);

	cout << max(l, w) << ' ' << min(l, w);

	return 0;
}