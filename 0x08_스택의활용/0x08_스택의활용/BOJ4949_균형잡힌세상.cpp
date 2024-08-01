#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	while (true) {
		string input;
		getline(cin, input, '.');

		stack<char> S;
		bool balanced = true;

		for (auto i :input) {
			if (input[i] == '[' || input[i] == '(') {
				S.push(input[i]);
			}
			else if (input[i] == ']' || input[i] == ')') {
				if (input[i] == ']' && S.top() == '[') {
					S.pop();
				}
				else if (input[i] == ')' && S.top() == '(') {
					S.pop();
				}
				else {
					S.push(input[i]);
				}
			}
		}
		if (S.empty()) {
			cout << "yes\n";
			break;
		}
	}
}