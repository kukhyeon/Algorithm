#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	cin.ignore();
	stack<char> S;
	while (true) {
		string input;
		getline(cin, input, '.');
		int len = input.length();
		for (int i = 0; i < len; i++) {
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