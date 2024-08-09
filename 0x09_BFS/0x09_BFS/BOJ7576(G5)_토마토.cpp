#include<iostream>
#include<queue>
using namespace std;
#define X first
#define Y second

/*
	N은 상자의 세로 칸의 수, M은 상자의 가로 칸의 수 (2 <= M, N <= 1000)
	정수 1은 익은 토마토, 정수 0은 익지 않은 토마토, 정수 -1은 토마토가 들어있지 않다.
	하루가 지나면 이미 익어있는 토마토들의 인접한 토마토들은 익는다. 
	모든 토마토들이 며칠이 지나면 다 익는지 최소 일수를 출력한다.
*/

 /*
 익은 토마토의 좌표 개수에 대하여 반복하며, 거리 좌표를 더 작은 숫자로 업데이트 한다.
 거리 2차원 배열에서 가장 높은 값을 가지는 좌표를 찾아서 거리 값 출력 < 최소 날짜가 되겠다
 */

int board[1002][1002];
int n, m; 
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
	int d[1002][1002] = {}; // 각 좌표에 시작점과의 거리를 저장하는 2차원 배열 초기화
	cin.tie(0);
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int num;
			cin >> num;
			board[i][j] = num;
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 1) {
				queue<pair<int, int>> Q;
				Q.push({ i, j });
				bool vis[1002][1002] = {};
				vis[i][j] = true;
				d[i][j] = 1; // 시작점의 거리
				while (!Q.empty()) {
					pair<int, int> cur = Q.front();
					int d_t[1002][1002] = {};
					Q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];

						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (vis[nx][ny] || board[nx][ny] != 0) continue;

						vis[nx][ny] = true;
						d_t[nx][ny] = d_t[cur.X][cur.Y] + 1; // board에 좌표에 대응하는, 시작점과의 최소 거리를 저장
						Q.push({ nx, ny });
						if (d_t[nx][ny] > 0 && d[nx][ny] > d_t[nx][ny]) { // 본 거리 좌표에 최소 거리를 새롭게 업데이트
							d[nx][ny] = d_t[nx][ny];
						}
					}
				}
			}
		}
	}
	cout << d[n - 1][m - 1] - 1;
}