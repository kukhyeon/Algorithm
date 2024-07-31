#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
	list<string>editor = {}; // 영어 소문자만 가능, MAX 6*10^5
	string text;
	cin >> text;
	editor.push_back(text);
	auto cursor = editor.begin();

	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		string order;
		cin >> order;
		if (order[0] == 'L') {
			if (cursor != editor.begin()) {
				cursor--;
			}
		}
		else if (order[0] == 'D') {
			if (cursor != editor.end()) {
				cursor++;
			}
		}
		else if (order[0] == 'B') {
			if (cursor != editor.begin()) {
				cursor--;
				cursor = editor.erase(cursor);
			}
		}
		else if (order[0] == 'P') {
			char word = order[order.size() - 1];
			editor.insert(cursor,word);
		}
	}
}