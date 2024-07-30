/*주어진 길이 N의 배열 arr에서 합이 100인 서로 다른 위치의 두 원소가 존재하면 1, 존재하지 않으면 0을 반환하는 함수 func2를 작성하라*/
#include <iostream>
using namespace std;

void func2(int arr[], int N) {
	int i = 0;
	int j = N - 1;
	int cnt = 0;
	while (i < j) {
		if (arr[i] + arr[j] > 100) {
			j--;
		}
		else if (arr[i] + arr[j] < 100) {
			i++;
		}
		else { // 두 원소의 합이 100이면
			i++;
			j++;
			cnt++;
		}
	}
	cout << cnt;
}

int main() {
	func2({ 1,52,48 }, 3);
	func2({ 50,42 }, 2);
	func2({ 4, 13, 63, 87 }, 4);

}
////