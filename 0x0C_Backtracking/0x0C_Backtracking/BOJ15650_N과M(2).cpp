// S3
#include <iostream>
using namespace std;

int N, M;
int num[9]; // index = 0 to 8
int visited[9]; // index = 0 to 8

// 상태 이상 트리, cnt는 0부터 M까지 성장, bc는 1부터 N까지 성장
void ctree(int cnt, int bc) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << num[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = bc; i <= N; i++) {
		if (!visited[i]) {
			num[cnt] = i;        // 현재 선택한 숫자를 배열에 저장
			ctree(cnt + 1, i + 1); // 다음 숫자는 현재 숫자 이후부터 선택
		}
	}
}

int main() {
	cin >> N >> M;
	// index = 0 to 8
	for (int i = 0; i < 9; i++) {
		visited[i] = false;
	}
	ctree(0, 1);
}