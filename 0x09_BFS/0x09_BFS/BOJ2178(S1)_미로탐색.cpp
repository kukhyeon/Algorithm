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

int BFS(int sX, int sY) {
    queue<pair<int, int>> Q;
    int distance[102][102] = {}; // 각 좌표에 시작점과의 거리를 저장하는 2차원 배열 초기화
    Q.push({ sX, sY });
    vis[sX][sY] = true;
    distance[sX][sY] = 1; // 시작점의 거리

    while (!Q.empty()) {
        pair<int, int> cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (vis[nx][ny] || board[nx][ny] != 1) continue;

            vis[nx][ny] = true;
            distance[nx][ny] = distance[cur.X][cur.Y] + 1; // board에 좌표에 대응하는, 시작점과의 최소 거리를 저장
            Q.push({ nx, ny });
        }
    }
    return distance[n - 1][m - 1]; // 도착점의 거리 반환
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
	cout << BFS(0, 0);
}