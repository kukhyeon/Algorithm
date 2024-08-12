﻿#include<iostream>
#include<queue>
using namespace std;

#define X first
#define Y second

char board[1002][1002];
int F_time[1002][1002]; // 각 좌표의 최소 거리를 저장할 배열
int J_time[1002][1002];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
	int raw, cal;
	cin >> raw >> cal;

	queue<pair<int, int>> FQ;
	queue<pair<int, int>> JQ;

	for (int i = 0; i < raw; i++) {
		for (int j = 0; j < cal; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'F') {
				FQ.push({ i, j });
				F_time[i][j] = 0;
			}
			else if (board[i][j] == 'J') {
				JQ.push({ i, j });
				J_time[i][j] = 0;
			}
			else {
				F_time[i][j] = -1;
				J_time[i][j] = -1;
			}
		}
	}

	// 불에 대한 BFS
	while (!FQ.empty()) {
		pair<int, int> cur = FQ.front(); FQ.pop();
		for (int dir = 0; dir < 4; dir++) {
			int new_X = cur.X + dx[dir];
			int new_Y = cur.Y + dy[dir];
			if (new_X < 0 || new_X >= raw || new_Y < 0 || new_Y >= cal) continue;
			if (board[new_X][new_Y] != '.' || F_time[new_X][new_Y] != -1) continue;
			F_time[new_X][new_Y] = F_time[cur.X][cur.Y] + 1;
			FQ.push({ new_X, new_Y });
		}
	}

	// 지훈에 대한 BFS
	while (!JQ.empty()) {
		pair<int, int> cur = JQ.front(); JQ.pop();
		for (int dir = 0; dir < 4; dir++) {
			int new_X = cur.X + dx[dir];
			int new_Y = cur.Y + dy[dir];
			if (new_X < 0 || new_X >= raw || new_Y < 0 || new_Y >= cal) continue;
			if (board[new_X][new_Y] != '.' || J_time[new_X][new_Y] != -1) continue;
			J_time[new_X][new_Y] = J_time[cur.X][cur.Y] + 1;
			JQ.push({ new_X, new_Y });
		}
	}

	// 탈출점에 대한 정보를 찾아야 한다. 탈출점은 '.'이며 row-1 || cal-1를 무조건 좌표로 갖는다.
}