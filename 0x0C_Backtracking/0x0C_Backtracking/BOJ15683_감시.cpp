// G3
#include <iostream>
using namespace std;

int N, M;
int cctv[8]; // cctv 분류용
int arrow[9][4]; // 행은 cctv 배열과 같고, 열은 우, 상, 좌, 하 인덱스 순
int map[9][9];
int cnt = 0;
int p = 0; // cctv, arrow 배열 포인팅 및 cctv의 개수 체크

// 사각지대를 최소화하는 재귀연산 진행, 매개변수 idx는 arrow의 행, cctv의 인덱스에 대응
// t_cnt는 중간 값을 저장하는 매개변수
 void gamsi(int idx, int t_cnt) {
	 // break condition은 현재 맵의 cctv 개수를 초과할시이다.
	 if (idx > p) {
		 t_cnt = cnt - t_cnt;
		 if (t_cnt < cnt) {
			 cnt = t_cnt;
			 return;
		 }
	 }
	 // CCTV의 종류를 분류하여 계산
	 if (cctv[idx] = 1) {
		 for (int i = 0; i < 4; i++) {
			 t_cnt += arrow[idx][i];
			 // 다음 cctv에 대한 재귀 반복
			 gamsi(idx + 1, t_cnt);
		 }
	 }
	 else if (cctv[idx] = 2) {
		t_cnt += arrow[idx][0] + arrow[idx][2];
		gamsi(idx + 1, t_cnt);
		t_cnt += arrow[idx][1] + arrow[idx][3];
		gamsi(idx + 1, t_cnt);
	 }
	 else if (cctv[idx] = 3) {
		 for (int i = 0; i < 4; i++) {
			 t_cnt += arrow[idx][i] + arrow[idx][(i + 1) % 4];
			 gamsi(idx + 1, t_cnt);
		 }
	 }
	 else if (cctv[idx] = 4) {
		 for (int i = 0; i < 4; i++) {
			 t_cnt += arrow[idx][i] + arrow[idx][(i + 1) % 4] + arrow[idx][(i + 2) % 4];
			 gamsi(idx + 1, t_cnt);
		 }
	 }
	 else if (cctv[idx] = 5) {
		 for (int i = 0; i < 4; i++) {
			 t_cnt += arrow[idx][i];
		 }
		 gamsi(idx + 1, t_cnt);
	 }
}

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

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] != 0 && map[i][j] != 6) {
				cctv[p] = map[i][j];
				// 감시 거리 탐색
				// 상
				for (int k = i; k > 0; k--) {
					if (map[k][j] == 6) break;
					arrow[p][1] += 1;
				}
				// 하
				for (int k = i; k < N; k++) {
					if (map[k][j] == 6) break;
					arrow[p][3] += 1;
				}
				// 좌
				for (int k = j; j > 0; j--) {
					if (map[i][k] == 6) break;
					arrow[p][2] += 1;
				}
				// 우
				for (int k = j; j < M; j++) {
					if (map[i][3] == 6) break;
					arrow[p][0] += 1;
				}
				p++; // 다음 인덱스로
			}
			// 0의 개수를 센다.
			if (map[i][j] == 0) {
				cnt++;
			}
		}
	}
	cout << cnt;
}