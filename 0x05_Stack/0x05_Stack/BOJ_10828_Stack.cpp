#include <iostream>
#include <string>
using namespace std;

const int MX = 1000005;

class Stack {
	int* dat;
	int p = 0;
public:
	Stack() {
		dat = new int[MX];
		p = 0;
	}
	~Stack() {
		delete[] dat;
	}
	void push(int x);
	int pop();
	int size();
	bool empty();
	int top();
};

void Stack::push(int x) {
	if (p < MX) {
		dat[p] = x;
		p++;
	}
}

int Stack::pop() {
	if (p > 0) {
		int temp = dat[p - 1];
		p--;
		return temp;
	}
	return -1;
}

int Stack::size() {
	return p;
}

bool Stack::empty() {
	return p == 0;
}

int Stack::top() {
	if (p > 0) return dat[p - 1];
	return -1;
}

int main() {
	Stack stack;
	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		string command;
		cin >> command;
		if (command == "push") {
			int value;
			cin >> value;
			stack.push(value);
		}
		else if (command == "pop") {
			cout << stack.pop() << endl;
		}
		else if (command == "size") {
			cout << stack.size() << endl;
		}
		else if (command == "empty") {
			cout << stack.empty() << endl;
		}
		else if (command == "top") {
			cout << stack.top() << endl;
		}
	}
	return 0;
}
