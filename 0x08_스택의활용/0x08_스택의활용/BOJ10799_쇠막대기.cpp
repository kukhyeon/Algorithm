#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	stack<char> S;
	string input;
	cin >> input;
	int Dstick = 0;

	for (int i = 0; i < input.length(); i++) { // input
		char c = input[i];
		if (c == '(') {
			S.push(c);
		}

		else if (c == ')') { // input
			if (!S.empty()) {
				if (S.top() == '(') {
					S.pop();
					if (i > 0 && input[i - 1] == '(') {
						Dstick += S.size();
					}
					else {
						Dstick += 1;
					}
				}
			}
		}
	}
	cout << Dstick;
}