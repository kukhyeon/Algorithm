// S2
#include <iostream>
using namespace std;

int arr[2189][2189] = {};
int result1 = 0, result2 = 0, result3 = 0;

void paper(int N, int row, int cal) {
	bool checker = true;
	int firstValue = arr[row][cal];
	for (int i = row; i < row + (N); i++) {
		for (int j = cal; j < cal + (N); j++) {
			if (arr[i][j] != firstValue) {
				//Test
				//cout << i << ' ' << j << " firstValue: " << firstValue << "\n";
				//cout << "arr[i][j]: " << arr[i][j] << "\n";
				checker = false;
				break;
			}
		}
		if (!checker) break;
	}
	if (checker) {
		if (firstValue == -1) {
			//Test
			//cout << row << " " << cal << " N: " << N << "\n";
			result1++;
		}
		else if (firstValue == 0) {
			//Test
			//cout << row << " " << cal << " N: " << N << "\n";
			result2++;
		}
		else if (firstValue == 1) {
			//Test
			//cout << row << " " << cal << " N: " << N << "\n";
			result3++;
		}
	}
	else {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				paper(N / 3, row + i * N / 3, cal + j * N / 3);
			}
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int num;
			cin >> num;
			arr[i][j] = num;
		}
	}
	paper(N, 0, 0);
	cout << result1 << '\n' << result2 << '\n' << result3;
}
