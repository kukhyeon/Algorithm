#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define X first
#define Y second

int main() {
	int raw, cal;
	cin >> raw;
	cin >> cal;
	int** board = new int* [raw];  // 힙 메모리로 이동, raw개의 int* 타입 포인터 배열 할당
	for (int i = 0; i < raw; i++) { // 각 행에 대해 다시 메모리를 할당
		board[i] = new int[cal]();
	}
	bool** vis = new bool* [raw];  // 힙 메모리로 이동, raw개의 int* 타입 포인터 배열 할당
	for (int i = 0; i < raw; i++) { // 각 행에 대해 다시 메모리를 할당
		vis[i] = new bool[cal]();
	}
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };

	int paint;
	for (int i = 0; i < raw; i++) {
		for (int j = 0; j < cal; j++) {
			cin >> paint;
			board[i][j] = paint;
			if (i == 0 && j == 0) {
				vis[0][0] = paint;
			}
		}
	}

	cin.tie(0);
	queue<pair<int, int>> Q;

	int cnt = 0;
	int maxnum = 0;
	for (int i = 0; i < raw; i++) {
		for (int j = 0; j < cal; j++) {
			if (vis[i][j] || board[i][j] != 1) { // 수정 1: 조건 추가
				continue;
			}
			Q.push({ i,j });
			vis[i][j] = 1; // 수정 1: 방문 표시 추가
			int temp = 1; // 수정 1: temp 초기화 위치 변경

			if (board[i][j] == 1) {
				Q.push({ i, j });
				while (!Q.empty()) {
					pair<int, int> cur = Q.front(); Q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || nx >= raw || ny < 0 || ny >= cal)continue;
						if (vis[nx][ny] == 1 || board[nx][ny] != 1) continue;
						vis[nx][ny] = 1;
						temp++;
						Q.push({ nx, ny });
					}
				}
				cnt++;
				if (temp > maxnum) {
					maxnum = temp;
				}
			}
		}
	}

	cout << cnt << '\n' << maxnum;

	// 동적 할당된 메모리 해제
	for (int i = 0; i < raw; i++) {
		delete[] board[i];
		delete[] vis[i];
	}
	delete[] board;
	delete[] vis;
}