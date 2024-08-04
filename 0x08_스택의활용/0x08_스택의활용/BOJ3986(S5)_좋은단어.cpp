#include <stack>
#include <iostream>
#include <string>
using namespace std;

int main() {
	int num;
	cin >> num;
	int goodword = 0;
	for (int i = 0; i < num; i++) {
		stack<char> S;
		string input;
		cin >> input;
		for (auto c : input) {
			if (!S.empty() && S.top() == c) {
					S.pop();
			}
			else {
				S.push(c);
			}
		}
		if (S.empty()) {
			goodword++;
		}
	}
	cout << goodword;
}