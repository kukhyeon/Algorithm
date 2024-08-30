// S2
#include <iostream>
using namespace std;

int arr[2189][2189];
int result1 = 0, result2 = 0, result3 = 0;

void paper(int N, int BC1, int BC2) {
	bool checker = true;
	int firstValue = arr[BC1][BC2];
	for (int i = BC1; i < BC1 + N; i++) {
		for (int j = BC2; j < BC2 + N; j++) {
			if (arr[i][j] != firstValue) {
				checker = false;
				break;
			}
		}
	}
	if (checker) {
		if (firstValue == -1) {
			result1++;
		}
		else if (firstValue == 0) {
			result2++;
		}
		else if (firstValue == 1) {
			result3++;
		}
	}
	else {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				paper(N / 3, BC1 + i * N / 3, BC2 + j * N / 3);
			}
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int N;
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N - 1; j++) {
			int num;
			cin >> num;
			arr[i][j] = num;
		}
	}
	paper(N, 0, 0);
	cout << result1 << '\n' << result2 << '\n' << result3;
}
