#include <iostream>
#include <queue>
using namespace std;
#define X first
#define Y second // pair를 조금 더 빠르게 쓰기 위함

int board[502][502] = {}; // 판, 1이면 파란 칸, 0이면 빨간 칸
bool vis[502][502]; // 방문 횟수
int n = 7, m = 10; // 행과 열
int dx[4] = { 1,0,-1,0 }; // 상하좌우를 영리하게 처리
int dy[4] = { 0,1,0,-1 };

int main() {
	cin.tie(0);
	queue<pair<int, int>>Q; // pair를 통해 행과 열 비교
	vis[0][0] = 1; // 방문 표시
	Q.push({ 0,0 }); // Queue에 추가

	while(!Q.empty()){ // Queue가 빌 때 까지 상하좌우 확인
		/*
		1. Q.front()는 큐의 맨 앞에 있는 요소(두 개의 정수를 가지는 쌍)을 가져옴.
		2. 다음으로, 이 쌍을 cur에 저장
		3. Q.pop()으로 큐의 맨 앞에 있는 요소를 제거한다.
		*/
		pair<int, int> cur = Q.front(); 
		Q.pop();
		cout << '(' << cur.X << ", " << cur.Y << ") -> "; // 방문순서 출력
		/*
		실행 순서
		1. dir = 0이면, dx[0] = 1, dy[0] = 0 -> { 1, 0 } ---- 하
		2. dir = 1이면, dx[1] = 0, dy[1] = 1 -> { 0, 1 } ---- 우
		3. dir = 2이면, dx[2] = -1, dy[2] = 0 -> { -1, 0 } ---- 상
		4. dir = 3이면, dx[3] = 0, dy[3] = -1 -> { 0, -1 } ---- 좌
		반시계 방향으로 돌아감
		*/
		for (int dir = 0; dir < 4; dir++) { //x는 행 y는 열 
			int nx = cur.X + dx[dir]; // nx, ny에 현재 상하좌우 값이 깔끔하게 들어간다.
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 25와 26은 순서가 바뀌면 안된다. 행과 열 범위를 벗어나면 런타임 에러
			if (vis[nx][ny] || board[nx][ny] != 1) continue; // visited나 원하는 칸이 아니면 건너뛴다.
			vis[nx][ny] = 1;
			Q.push({ nx, ny }); // Queue에 넣을 때 방문점을 찍는다.
		}
	}
}