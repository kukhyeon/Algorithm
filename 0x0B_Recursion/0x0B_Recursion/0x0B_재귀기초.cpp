#include<iostream>
using namespace std;

// 1~N까지의 수를 출력하는 재귀함수
void recursion1(int num) {
	if (num > 0) {
		recursion1(num -= 1);
		cout << num + 1;
	}
}

// 1~N까지의 수를 합하는 재귀함수
int recursion2(int num) {
	if (num > 0) {
		num += recursion2(num - 1);
	}
	return num;
}

int main() {
	recursion1(10);
	cout << '\n' << recursion2(10);
}