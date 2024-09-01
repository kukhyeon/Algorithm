// S1
#include <iostream>
#include <cmath>
using namespace std;

int cnt = 0;
void recursion(int N, int r, int c ,int row, int col) {
	bool checker = true;
	int power = pow(2, N); // 2^N
	//Test
	//cout << "재귀 test row: " << row << " col " << col << endl;
	if (N == 1) { // 2x2면
		for (int i = row; i < row + 2; i++) {

			for (int j = col; j < col + 2; j++) {
				/*
				cout << "행: " << i << endl;
				cout << "열: " << j << endl;
				cout << cnt << endl;
				*/

				if (i == r && j == c) {
					cout << cnt;
					checker = false;
					break;
				}
				cnt++;
			}
			if (!checker) {
				break;
			}
		}
	}

	else {
		for (int i = 0; i < 2; i++){
			for (int j = 0; j < 2; j++) {
				recursion(N-1, r, c, row + i * (power / 2), col + j * (power / 2));
			}
		}
	}
};

int main() {
	int N, r, c;
	cin >> N >> r >> c;
	recursion(N, r, c, 0, 0);
}