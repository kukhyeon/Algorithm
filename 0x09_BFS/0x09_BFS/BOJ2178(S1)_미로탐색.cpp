#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
#define X first
#define Y second

vector<vector<int>> board(102, vector<int>(102)); // 2차원 벡터 선언
bool vis[102][102]; // 방문 횟수
int n, m;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int BFS(queue<pair<int, int>> Q, int bread) {
	while (!Q.empty()) { // Q가 비어있지 않을 때 까지
		pair<int, int> cur = Q.front();
		Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (vis[nx][ny] || board[nx][ny] != 1) continue;
			vis[nx][ny] = 1;
			bread++;
			Q.push({ nx, ny });
			if (Q.size() > 1) {
				int min = 102;
				for (int i = 0; i< Q.size(); i++) {
					int temp = BFS(Q, 0);
					if (temp > 0 && min > temp) {
						min = temp;
					}
				}
				return bread + min;
			}
		}
	}
}

int main() {
	cin.tie(0);
	cin >> n >> m;
	vector<string> inputs(n);
	for (int i = 0; i < n; i++) {
		string ip;
		cin >> ip;
		inputs[i] = ip;
	}

	queue<pair<int, int>> Q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			board[i][j] = inputs[i][j] - '0'; // 문자를 숫자로 변환
		}
	}
	Q.push({ 0, 0 });
	cout << BFS(Q, 1);
}