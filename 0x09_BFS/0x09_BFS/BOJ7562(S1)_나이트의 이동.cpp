#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

#define X first
#define Y second

int table[302][302] = {};
int dx[8] = { 2, 1, -1, -2, 2, 1, -1, -2 };
int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };


int main() {
	int TC, I, N, M, N2, M2;
	cin >> TC;
	for (int i = 0; i < TC; i++) {
		cin >> I;
		cin >> N >> M;
		cin >> N2 >> M2;
		fill(&table[0][0], &table[0][0] + 302 * 302, -1);
		table[N][M] = 0;
		queue<pair<int, int>> Q;
		Q.push({ N, M });
		while (!Q.empty()) {
			pair<int, int> cur = Q.front();
			Q.pop();
			for (int dir = 0; dir < 8; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];

				if (nx < 0 || nx >= I || ny < 0 || ny >= I) {
					continue;
				}
				if (table[nx][ny] != -1) {
					continue;
				}
				table[nx][ny] = table[cur.X][cur.Y] + 1;
				Q.push({ nx, ny });
			}
		}
		cout << table[N2][M2] << '\n';
	}
}

/*	
				if (nx == N2 && ny == M2) {
					cout << table[cur.X][cur.Y] + 1 << '\n';
					// 큐 초기화
					queue<pair<int, int>> Q;
					break;
				}
*/