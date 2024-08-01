#include<iostream>
using namespace std;

const int MX = 1000005;
int dat[2 * MX + 1];
int head = MX, tail = MX;

void push_front(int x) {
	dat[--head] = x;
}

void push_back(int x) {
	dat[tail++] = x;
}

void pop_front() {
	if (head < tail) head++;
}

void pop_back() {
	if (tail > head) tail--;
}

int front() {
	if(tail > head) return dat[head];
}

int back() {
	if(head < tail) return dat[tail - 1];
}

int test() {

}

int main() {
	test();
}