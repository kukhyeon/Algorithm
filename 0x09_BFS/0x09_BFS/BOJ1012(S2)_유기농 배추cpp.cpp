#include <iostream>
#include <queue>

using namespace std;
#define X first
#define Y second

int table[52][52] = {};
bool vis[52][52] = {};
int dx[4] = { 1,0,-1,0 }; 
int dy[4] = { 0,1,0,-1 };

int main() {
	int N, M, K, TC;
	cin >> TC;
	for (int i = 0; i < TC; i++) {
		cin >> M >> N >> K;
		int cnt = 0;
		fill(&table[0][0], &table[0][0] + 52 * 52, 0);
		fill(&vis[0][0], &vis[0][0] + 52 * 52, false); 

		for (int j = 0; j < K; j++) {
			int r, c;
			cin >> c >> r;
			table[r][c] = 1;
		}
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (vis[j][k] == 0 && table[j][k] == 1) {
					cnt++;
					queue<pair<int, int>> Q;
					vis[j][k] = 1;
					Q.push({ j, k });
					while (!Q.empty()) {
						pair<int, int> cur = Q.front(); 
						Q.pop();
						for (int dir = 0; dir < 4; dir++) {
							int nx = cur.X + dx[dir];
							int ny = cur.Y + dy[dir];
							if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
								continue;
							}
							if (vis[nx][ny] == 1 || table[nx][ny] != 1) {
								continue;
							}
							vis[nx][ny] = 1;
							Q.push({ nx, ny });
						}
					}
				}
			}
		}
		cout << cnt << "\n";
	}
}