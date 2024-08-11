#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

#define X first
#define Y second

int board[1002][1002];
int dist[1002][1002]; // 각 좌표의 최소 거리를 저장할 배열
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
    int n, m;
    cin >> m >> n;

    queue<pair<int, int>> Q;

    // 거리 배열 초기화
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 1) {
                Q.push({ i, j });
                dist[i][j] = 0; // 익은 토마토는 거리 0으로 설정
            }
            else {
                dist[i][j] = -1; // 초기 거리값을 -1로 설정
            }
        }
    }

    // BFS 실행
    while (!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (board[nx][ny] != 0 || dist[nx][ny] != -1) continue; // 익지 않은 토마토가 아니거나, 이미 방문한 경우
            dist[nx][ny] = dist[cur.X][cur.Y] + 1; // 거리 갱신
            Q.push({ nx, ny });
        }
    }

    int maxnum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dist[i][j] == -1 && board[i][j] == 0) { // 익지 않은 토마토가 있는 경우
                cout << -1; // 모든 토마토가 익지 못한 경우
                return 0;
            }
            maxnum = max(maxnum, dist[i][j]);
        }
    }
    cout << maxnum;
}
