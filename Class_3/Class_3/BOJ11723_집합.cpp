//S5
#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int M;
    cin >> M;
    unordered_set<int> S; 

    for (int i = 0; i < M; i++) {
        string input;
        int x;
        cin >> input;

        if (input == "add") {
            cin >> x;
            S.insert(x); // 중복되지 않도록 자동 처리
        }
        else if (input == "remove") {
            cin >> x;
            S.erase(x); // 존재하지 않으면 아무 일도 일어나지 않음
        }
        else if (input == "check") {
            cin >> x;
            if (S.find(x) != S.end()) {
                cout << '1' << '\n';
            }
            else {
                cout << '0' << '\n';
            }
        }
        else if (input == "toggle") {
            cin >> x;
            if (S.find(x) != S.end()) {
                S.erase(x); // 존재하면 제거
            }
            else {
                S.insert(x); // 존재하지 않으면 추가
            }
        }
        else if (input == "all") {
            S.clear();
            for (int j = 1; j <= 20; j++) { // 1부터 20까지 추가
                S.insert(j);
            }
        }
        else if (input == "empty") {
            S.clear(); // 모든 요소 제거
        }
    }

    return 0;
}
