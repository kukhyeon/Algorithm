#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
    list<char> editor; // 영어 소문자만 가능, MAX 6*10^5
    string text;
    cin >> text;

    for (char c : text) {
        editor.push_back(c);
    }

    auto cursor = editor.end();

    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        char order;
        cin >> order;
        if (order == 'L') {
            if (cursor != editor.begin()) {
                cursor--;
            }
        }
        else if (order == 'D') {
            if (cursor != editor.end()) {
                cursor++;
            }
        }
        else if (order == 'B') {
            if (cursor != editor.begin()) {
                cursor--;
                cursor = editor.erase(cursor);
            }
        }
        else if (order == 'P') {
            char word;
            cin >> word;
            editor.insert(cursor, word);
        }
    }

    for (char c : editor) {
        cout << c;
    }
    cout << endl;

    return 0;
}
