#include <iostream> // 입출력 헤더파일 포함
#include <vector> // 벡터 헤더파일 포함

using namespace std; // iostream 편하게 쓰기 위한 namespace 선언
const int INF = 1e8; // 최댓값 정수형 상수 선언

vector<bool> visited; //방문 검사 배열
vector<vector<int>> matrix; //비용 행렬
int n, ans = INF; //최소 비용 저장 위해 미리 최댓값으로 초기화 (10 * 1,000,000)

void backtracking(int cnt, int cur_city, int cost) { // 도시의 최소 순회 비용을 구하는 백트래킹 함수
    if (cost >= ans) { // 비용이 현재 최소비용보다 클 경우
        return; // 최소비용이 아니므로 return 으로 종료
    }
    if (cnt == n) { //종료 조건 : n개의 도시를 순회했음
        //출발 도시(0)로 다시 돌아올 수 있는지 확인
        if (matrix[cur_city][0] != 0) { // 현재 도시에서 처음 출발 도시로 갈 수 있는 경우
            ans = min(ans, cost + matrix[cur_city][0]); // 최소비용 ans를 현재 최소비용과 현재 계산중인 cost와 방문도시를 더한 값 중 작은 값으로 선택하여 대입
        }
        return; // 연산 종료 후 return
    }
    for (int i = 0; i < n; i++) { //cur_city에서 도시 i로 이동
        if (matrix[cur_city][i] && !visited[i]) { //길이 있고, 아직 방문하지 않은 도시
            visited[i] = true; // 방문 했으므로 true로 바꿈
            backtracking(cnt + 1, i, cost + matrix[cur_city][i]); // 방문 도시수를 하나 증가, 방금 방문한 도시 i, 계산 중인 비용 cost에 방문 비용 더한 값을 인자로 재귀호출
            visited[i] = false; // 재귀 호출 끝나면 false로 바꾸기
        }
    }
}

/**
 * 백트래킹 풀이 (4ms)
 * 한 사이클을 만들면, 어느 도시에서 시작하든 값은 같으므로 0번 도시부터 시작하는 경우만 검사하면 된다.
 */

int main() { // 입출력할 main 함수

    cin >> n; // 도시의 수 입력
    visited.assign(n, false); // n개의 방문도시를 false로 초기화
    matrix.assign(n, vector<int>(n, 0)); // n*n 비용 행렬을 각 비용이 0으로 초기화
    for (int i = 0; i < n; i++) { // 비용 행렬을 입력받기 위한 이중 for문
        for (int j = 0; j < n; j++) { // 비용 행렬을 입력받기 위한 이중 for 문
            cin >> matrix[i][j]; // i에서 j로 가기 위한 비용을 입력
        }
    }

    //연산
    visited[0] = true; // 0번째는 처음 방문할 도시이므로 true로 설정
    backtracking(1, 0, 0); // 선택도시수, 현재 도시 index, 비용의 합을 인자로 넘겨준다.

    //출력
    cout << ans; // 함수에서 구한 최소비용 ans 출력
    return 0; // 함수가 안전하게 끝날 시 return 0
}