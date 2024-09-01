// S3
#include <iostream>
#include <deque>
using namespace std;

int arr[10];
deque<int> ans;
bool visited[10];

void recursion(int N, int M, int cnt) {
	if (cnt == M) {
		for (int num : ans) {
			cout << num << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			ans.push_back(arr[i]);
			recursion(N, M, cnt + 1);
			ans.pop_back();
			visited[i] = false;
		}
	}
}

int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		arr[i] = i; 
	}

	for (int i = 0; i < 10; i++) {
		visited[i] = false;
	}

	recursion(N, M, 0);
}