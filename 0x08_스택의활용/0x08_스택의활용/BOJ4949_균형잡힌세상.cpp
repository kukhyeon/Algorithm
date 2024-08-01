#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	while (true) {
		string input;
		getline(cin, input, '.');
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
				if (input[i] == ']' && S.top() == '[' || input[i] == ')' && S.top() == '(') {
					S.pop();
				}
				else {
					balanced = false;
					break;
				}
			}
		}
		if (balanced) {
			cout << "yes\n";
		}
		else {
			cout << "no\n";
		}
		cin.ignore();
	}
}
