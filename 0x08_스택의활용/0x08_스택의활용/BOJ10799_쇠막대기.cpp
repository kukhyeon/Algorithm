#include <iostream>
#include <stack>
using namespace std;

int main() {
	stack<char> S;
	string input;
	cin >> input;
	int Dstick = 0;
	int level = 0;

	for (auto c : input) { // input
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
					Dstick += level;
				}

				else if (S.top() == ')') {
					Dstick += 1;
					if (level > 0) {
						level--;
					}
				}
			}
		}
	}
	cout << Dstick;
}