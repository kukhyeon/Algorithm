#include <iostream>
#include <stack>
using namespace std;

int main() {
	stack<int> stack;
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
			if (stack.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << stack.top() << endl;
				stack.pop();
			}
		}
		else if (command == "size") {
			cout << stack.size() << endl;
		}
		else if (command == "empty") {
			cout << stack.empty() << endl;
		}
		else if (command == "top") {
			if (stack.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << stack.top() << endl;
			}
		}
	}
	return 0;
}
