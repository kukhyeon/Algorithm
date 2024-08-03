#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	stack<char> S;
	string input;
	cin >> input;
	int Dstick = 0;
	int level = 0;

	for (int i = 0; i < input.length(); i++) { // input
		char c = input[i];
		if (c == '(') {
			if (!S.empty()) {
				if (S.top() == '(') {
					level++;
				}
			}
			S.push(c);
		}

		else if (c == ')') { // input
			if (!S.empty()) {
				if (S.top() == '(') {
					if (i > 2 && input[i - 2] == '(') { // laser
						Dstick += level;
						level--;
					}
					else {
						Dstick += level+1;
					}
				}

				else if (S.top() == ')') {
					Dstick += 1;
					if (level > 0) {
						level--;
					}
				}
				S.push(c);
			}
		}
	}
	cout << Dstick;
}