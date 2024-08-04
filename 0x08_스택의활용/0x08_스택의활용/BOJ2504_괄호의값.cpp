#include<iostream>
#include<stack>
using namespace std;

int main() {
    stack<char> S;
    int temp = 1;
    int result = 0;

    string input;
    cin >> input;

    for (int i = 0; i < input.length(); i++) {
        char c = input[i];
        if (c == '(') {
            S.push(c);
            temp *= 2;
        }
        else if (c == '[') {
            S.push(c);
            temp *= 3;
        }
        else if (c == ')') {
            if (S.empty() || S.top() != '(') {
                result = 0;
                break;
            }
            if (input[i - 1] == '(') {
                result += temp;
            }
            S.pop();
            temp /= 2;
        }
        else if (c == ']') {
            if (S.empty() || S.top() != '[') {
                result = 0;
                break;
            }
            if (input[i - 1] == '[') {
                result += temp;
            }
            S.pop();
            temp /= 3;
        }
    }

    if (!S.empty()) {
        result = 0;
    }

    cout << result;
    return 0;
}
