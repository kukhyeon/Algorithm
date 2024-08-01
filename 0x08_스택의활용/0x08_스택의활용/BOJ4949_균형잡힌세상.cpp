#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	while (true) {
		string input;
		getline(cin, input, '.');
		cin.ignore();
		if (input == "\n" || input.empty()) break;

		stack<char> S;
		bool balanced = true;

		for (auto i : input) {
			if (i == '[' || i == '(') {
				S.push(i);
			}
			else if (i == ']' || i == ')') {
				if (S.empty()) {
					balanced = false;
					break;
				}
				if (i == ']' && S.top() == '[' || i == ')' && S.top() == '(') {
					S.pop();
				}
				else {
					balanced = false;
					break;
				}
			}
		}
		if (!S.empty()) {
			balanced = false;
		}
		if (balanced) {
			cout << "yes\n";
		}
		else {
			cout << "no\n";
		}
	}
}
