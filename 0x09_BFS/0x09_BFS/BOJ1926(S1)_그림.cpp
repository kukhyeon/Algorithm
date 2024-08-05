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

	for (int i = 0; i < raw; i++) {
		for (int j = 0; j < cal; j++) {
			cin >> board[i][j];
		}
	}

	cin.tie(0);
	queue<pair<int, int>> Q;

	int cnt = 0;
	int maxnum = 0;

	for (int i = 0; i < raw; i++) {
		for (int j = 0; j < cal; j++) {
			if (board[i][j] == 1 && !vis[i][j]) {
				cnt++;
				Q.push({ i, j });
				vis[i][j] = 1;
				int temp = 0;
\
				while (!Q.empty()) {
					pair<int, int> cur = Q.front(); Q.pop();
					temp++;
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || nx >= raw || ny < 0 || ny >= cal) {
							continue;
						}
						if (vis[nx][ny] == 1 || board[nx][ny] != 1) {
							continue;
						}
						vis[nx][ny] = 1;
						Q.push({ nx, ny });
					}
				}
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