// G3
#include <iostream>
using namespace std;

int N, M;
int cctv[8]; // cctv 분류용
int arrow[9][4]; // 행은 cctv 배열과 같고, 열은 우, 상, 좌, 하 인덱스 순
int map[9][9];
int cnt = 0;
int p = 0; // cctv, arrow 배열 포인팅 및 cctv의 개수 체크
int result = 100000;

// 사각지대를 최소화하는 재귀연산 진행, 매개변수 idx는 arrow의 행, cctv의 인덱스에 대응
// t_cnt는 중간 값을 저장하는 매개변수
 void gamsi(int idx, int t_cnt) {
	 // break condition은 현재 맵의 cctv 개수를 초과할시이다.
	 if (idx >= p) {
		 t_cnt = cnt - t_cnt;
		 if (t_cnt < result) {
			 result = t_cnt;
			 
		 }
		 // cout << "재귀리턴 result, t_cnt, idx: " << result << " " << t_cnt << " " << idx << " \n";
		 return;
	 }
	 // CCTV의 종류를 분류하여 계산
	 if (cctv[idx] == 1) {
		 for (int i = 0; i < 4; i++) {
			 int temp = t_cnt;
			 temp += arrow[idx][i];
			 // 다음 cctv에 대한 재귀 반복
			 gamsi(idx + 1, temp);
			 //cout << "cctv_1 cnt, t_cnt, idx, temp: " << cnt << " " << t_cnt << " " << idx << " " << temp << " \n";
		 }
	 }
	 else if (cctv[idx] == 2) {
		 for (int i = 0; i < 2; i++) {
			 int temp = t_cnt;
			 temp += arrow[idx][i] + arrow[idx][(i + 2)];
			 gamsi(idx + 1, temp);
		 }
	 }
	 else if (cctv[idx] == 3) {
		 for (int i = 0; i < 4; i++) {
			 int temp = t_cnt;
			 temp += arrow[idx][i] + arrow[idx][(i + 1) % 4];
			 gamsi(idx + 1, temp);
		 }
	 }
	 else if (cctv[idx] == 4) {
		 for (int i = 0; i < 4; i++) {
			 int temp = t_cnt;
			 temp += arrow[idx][i] + arrow[idx][(i + 1) % 4] + arrow[idx][(i + 2) % 4];
			 cout << temp << "\n";
			 gamsi(idx + 1, temp);
		 }
	 }
	 else if (cctv[idx] == 5) {
		 int temp = t_cnt;
		 for (int i = 0; i < 4; i++) {
			 temp += arrow[idx][i];
		 }
		 cout << "cctv5, temp and t_cnt is: " << temp << " " << t_cnt << "\n";
		 gamsi(idx + 1, temp);
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
			if (map[i][j] == 0) {
				cnt++;
			}
		}
	}

	cout << "초기 cnt: " << cnt << "\n";

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1 || map[i][j] == 2 || map[i][j] == 3 || map[i][j] == 4 || map[i][j] == 5) {
				cctv[p] = map[i][j];
				// 감시 거리 탐색
				// 우
				map[i][j] = 7;
				for (int k = j; k < M; k++) {
					if (map[i][k] == 6) break;
					if (map[i][k] == 7) continue;
					arrow[p][0] += 1;
					// cout << "우 좌표: " << i << " " << k << "\n";
				}
				// 상
				for (int k = i; k >= 0; k--) {
					if (map[k][j] == 6) break;
					if (map[k][j] == 7) continue;
					arrow[p][1] += 1;
					// cout << "상 좌표: " << k << " " << j << "\n";
				}
				// 좌
				for (int k = j; k >= 0; k--) {
					if (map[i][k] == 6) break;
					if (map[i][k] == 7) continue;
					arrow[p][2] += 1;
					// cout << "좌 좌표: " << i << " " << k << "\n";
				}
				// 하
				for (int k = i; k < N; k++) {
					if (map[k][j] == 6) break;
					if (map[k][j] == 7) continue;
					arrow[p][3] += 1;
					// cout << "하 좌표: " << k << " " << j << "\n";
				}
				p++; // 다음 인덱스로
			}
		}
	}

	gamsi(0, 0);
	cout << result << "\n";


	// test
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 4; j++) {
			cout << arrow[i][j] << " ";
		}
		cout << "\n";
	}
}