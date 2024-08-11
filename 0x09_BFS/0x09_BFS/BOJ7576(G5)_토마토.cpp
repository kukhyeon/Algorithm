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
bool vis[1002][1002]; // 방문 배열 초기화

int main() {
    int n, m;
    cin >> m >> n;

    // 거리 배열 초기화
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            dist[i][j] = -1;
        }
    }
    queue<pair<int, int>> Q;
    // 각 익은 토마토에서 BFS 실행
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            /*
                만약 익은 토마토가 board에 존재한다면, 익은 좌표에서 대하여 BFS를 실행한다.
                현재의 거리 값과 이전의 거리 값을 비교하는 조건문을 통해 dist 배열을 업데이트 한다. 
            */
            if (board[i][j] == 1) {
                Q.push({ i, j }); 
                vis[i][j] = true;
                dist[i][j] = 0;
                while (!Q.empty()) {
                    pair<int, int> cur = Q.front(); Q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        // 이미 방문했거나 0이 아닌 값은 건너뛴다. 
                        if (vis[nx][ny] || board[nx][ny] != 0) continue;
                        vis[nx][ny] = true;
                        if (dist[nx][ny] == -1) {
                            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                        }
                        if (dist[nx][ny] > dist[cur.X][cur.Y] + 1) {
                            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                        }
                        Q.push({ nx, ny });
                    }
                }
                //vis 초기화
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        vis[i][j] = false;
                    }
                }
            }
        }
    }
    int maxnum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dist[i][j] == -1 && board[i][j] == 0) { // 익지 않은 토마토가 있는 경우
                cout << -1; // 모든 토마토가 익지 못한 경우
                return 0;
            }
            if (maxnum < dist[i][j]) {
                maxnum = dist[i][j];
            }
        }
    }
    cout << maxnum;
}