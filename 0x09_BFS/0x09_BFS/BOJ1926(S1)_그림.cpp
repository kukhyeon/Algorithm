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
	int** board = new int* [raw];  // 힙 메모리로 이동
	for (int i = 0; i < raw; i++) {
		board[i] = new int[cal]();
	}
	bool** vis = new bool* [raw];  // 힙 메모리로 이동
	for (int i = 0; i < raw; i++) {
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
	if (vis[0][0]) {
		Q.push({ 0,0 });
	}

	//test
	int cnt = 0;
	for (int i = 0; i < raw; i++) {
		for (int j = 0; j < cal; j++) {
			if (vis[i][j]) {
				continue;
			}
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
						Q.push({ nx, ny });
					}
				}
				if (Q.empty()) {
					cnt++;
				}
			}
		}
	}
	cout << cnt;
	// 동적 할당된 메모리 해제
	for (int i = 0; i < raw; i++) {
		delete[] board[i];
		delete[] vis[i];
	}
	delete[] board;
	delete[] vis;
}