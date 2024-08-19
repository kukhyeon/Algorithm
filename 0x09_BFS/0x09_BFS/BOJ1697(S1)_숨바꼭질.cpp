#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int num = 100001;
int line[num]; // 방점으로 사용

int dx[3] = { -1, 1, 2 };

int main() {
	cin.tie(0);
	queue<int> Q;
	int N, K;
	cin >> N >> K;

	memset(line, -1, sizeof(line));
	line[N] = 0;
	Q.push(N);

	while (!Q.empty()) {
		int preQ = Q.front();
		Q.pop();
		for (int dir = 0; dir < 3; dir++) {
			int nx;
			if (dir == 2) {
				nx = preQ * dx[dir];
			}
			else {
				nx = preQ + dx[dir];
			}
			if (nx < 0 || nx >= num) continue;
			if (line[nx] != -1) continue;
			line[nx] = line[preQ] + 1;
			Q.push(nx);
		}
	}
	cout << line[K];
}