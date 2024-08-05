#include <iostream>
#include <queue>
using namespace std;
#define X first
#define Y second // pair를 조금 더 빠르게 쓰기 위함

int board[502][502] = {}; // 판, 1이면 파란 칸, 0이면 빨간 칸
bool vis[502][502]; // 방문 횟수
int n = 7, m = 10; // 행과 열
int dx[4] = { 1,0,-1,0 }; // 상하좌우를 영리하게 처리
int dy[4] = { 0,1,-1,0 };

int main() {
	cin.tie(0);
	queue<pair<int, int>>Q;
	vis[0][0] = 1; // 방문 표시
	Q.push({ 0,0 }); // Queue에 추가

	while(!Q.empty()){ // Queue가 빌 때 까지 상하좌우 확인
		pair<int, int> cur = Q.front(); Q.pop();
		cout << '(' << cur.X << ", " << cur.Y << ") -> "; // 방문순서 출력
		for (int dir = 0; dir < 4; dir++) { //x는 행 y는 열 
			int nx = cur.X + dx[dir]; // nx, ny에 현재 상하좌우 값이 깔끔하게 들어간다.
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 25와 26은 순서가 바뀌면 안된다. 행과 열 범위를 벗어나면 런타임 에러
			if (vis[nx][ny] || board[nx][ny] != 1) continue; // visited나 원하는 칸이 아니면 건너뛴다.
			vis[nx][ny] = 1;
			Q.push({ nx, ny });
		}
	}
}