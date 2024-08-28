// N = 열, M = 행, K = TC
// 왼쪽 아래 꼭짓점, 오른쪽 위 꼭짓점
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
#define X first
#define Y second

int table[102][102];
int dist[102][102];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int y, x, K, x1, y1, x2, y2;
	cin >> y >> x >> K;

	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			table[i][j] = 0;
		}
	}
		// 직사각형 맵핑, 직사각형은 -1로 표시
	for (int i = 0; i < K; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = y1; j < y2; j++) {
			for (int k = x1; k < x2; k++) {
				table[j][k] = -1;
			}
		}
	}

	vector<int> areas;
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			if (table[i][j] == 0) {
				queue<pair<int, int>> Q;
				Q.push({ i,j });
				table[i][j] = 1;
				int area_size = 0;
				while (!Q.empty()) {
					pair<int, int> cur = Q.front();
					Q.pop();
					area_size++;

					for (int dir = 0; dir < 4; dir++) {  
						int nx = cur.X + dx[dir]; 
						int ny = cur.Y + dy[dir];
						if (nx < 0 || nx >= y || ny < 0 || ny >= x) continue; 
						if (table[nx][ny] != 0) continue; 
						table[nx][ny] = 1;
						Q.push({ nx, ny }); 
					}
				}
				areas.push_back(area_size);
			}
		}
	}
	cout << areas.size() << '\n';
	sort(areas.begin(), areas.end());
	for (int i = 0; i < areas.size(); i++) {
		cout << areas[i] << ' ';
	}
}