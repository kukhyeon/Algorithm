#include <iostream>
using namespace std;

int N, S;
int arr[22];
int visited[22];
int cnt = 0;

// sum은 값을 저장하는 변수, idx는 배열의 idx를 맵핑
void recursion(int S, int sum, int idx) {
	if (idx == N) {
		if(sum == S) cnt++;
		return;
	}
	recursion(S, sum, idx + 1);
	recursion(S, sum + arr[idx], idx + 1);
}

int main() {
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	recursion(S, 0, 0);
	if (S == 0) cnt--;
	cout << cnt;
}