#include <iostream>
using namespace std;

const int MX = 1000005;
int dat[MX] = {}; // 데이터를 저장할 공간
int pos = 0; // 맨 위를 가리킴 = 스택 내 원소의 수와 같다.

void push(int x) {
	dat[pos++] = x;
}

void pop() {
	dat[pos] = 0; // 굳이 초기화 안해도 됨
	if (pos != 0) pos--;
}

int top() {
	return dat[pos-1];
}

void test() {

}

int main(void) {
	test();
}