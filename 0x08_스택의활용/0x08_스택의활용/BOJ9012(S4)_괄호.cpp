#include <iostream>
#include <stack>
using namespace std;

int main() {
	int num;
	cin >> num;

	for (int i = 0; i < num; i++) {
		stack<char> S;
		string pars;
		cin >> pars;
		
		for (auto c : pars) {
			if (c == '(') {
				S.push(c);
			}
			else if (c == ')') {
				if (!S.empty() && S.top() == '(') {
					S.pop();
				}
				else {
					S.push(c);
				}
			}
		}
		if (S.empty()) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
}