// G3
#include <iostream>
#include <queue>
using namespace std;

int N, M;
int cctv[8]; // cctv 분류용
int arrow[9][4]; // 행은 cctv 배열과 같고, 열은 상, 하, 좌, 우 인덱스 순
int map[9][9];
int cnt = 0;
int dx[2] = { 1, -1 };
int dy[2] = { 1, -1 };

int main() {
	cin >> N >> M;
	// map을 채운다.
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	// arrow 초기화
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 4; j++) {
			arrow[i][j] = 0;
		}
	}

	int p = 0; // cctv 배열을 채우기 위해 선언
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] != 0 && map[i][j] != 6) {
				cctv[p] = map[i][j];
				// 감시 거리 탐색
				// 상
				for (int k = i; k > 0; k--) {
					if (map[k][j] == 6) break;
					arrow[p][0] += 1;
				}
				// 하
				for (int k = i; k < N; k++) {
					if (map[k][j] == 6) break;
					arrow[p][1] += 1;
				}
				// 좌
				for (int k = j; j > 0; j--) {
					if (map[i][k] == 6) break;
					arrow[p][2] += 1;
				}
				// 우
				for (int k = j; j < M; j++) {
					if (map[i][3] == 6) break;
					arrow[p][3] += 1;
				}
				p++;
			}
			if (map[i][j] == 0) {
				cnt++;
			}
		}
	}
}