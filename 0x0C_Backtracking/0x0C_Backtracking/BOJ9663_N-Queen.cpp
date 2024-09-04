#include <iostream>
using namespace std;

int visited[20];
int visited_right[40];
int visited_left[40];
int cnt = 0;

void recursion(int N, int row) {
	if (row == N) {
		cnt++;
		return;
	}
	else {
		for (int i = 0; i < N; i++) {
			if (visited[i] || visited_right[row-i+N-1] || visited_left[row+i]) {
				continue;
			}
			visited[i] = 1;
			visited_right[row-i+N-1] = 1;
			visited_left[row+i] = 1;
			// 다음 행으로 
			recursion(N, row + 1);
			// visit 해제
			visited[i] = 0;
			visited_right[row - i + N - 1] = 0;
			visited_left[row + i] = 0;

		}
	}
}

int main() {
	int N;
	cin >> N;
	recursion(N, 0);
	cout << cnt;
}