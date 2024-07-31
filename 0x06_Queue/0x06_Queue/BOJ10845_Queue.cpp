#include <iostream>
#include <string>
using namespace std;

const int MX = 1000005;

class Queue {
	int* dat;
	int front_idx, back_idx;
public:
	Queue() {
		dat = new int[MX];
		front_idx = 0;
		back_idx = 0;
	}
	~Queue() {
		delete[] dat;
	}
	void enqueue(int x);
	int dequeue();
	int size();
	bool empty();
	int front();
	int back();
};

void Queue::enqueue(int x) {
	if (back_idx < MX) {  // 배열 범위 초과 방지
		dat[back_idx] = x;
		back_idx++;
	}
}

int Queue::dequeue() {
	if (front_idx < back_idx) {
		int temp = dat[front_idx];
		front_idx++;
		return temp;
	}
	return -1;
}

int Queue::size() {
	return back_idx - front_idx;
}

bool Queue::empty() {
	return front_idx == back_idx;
}

int Queue::front() {
	if (front_idx < back_idx) return dat[front_idx];
	return -1;
}

int Queue::back() {
	if (front_idx < back_idx) return dat[back_idx - 1];
	return -1;
}

int main() {
	Queue queue;
	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		string command;
		cin >> command;
		if (command == "push") {
			int value;
			cin >> value;
			queue.enqueue(value);
		}
		else if (command == "pop") {
			cout << queue.dequeue() << endl;
		}
		else if (command == "size") {
			cout << queue.size() << endl;
		}
		else if (command == "empty") {
			cout << queue.empty() << endl;
		}
		else if (command == "front") {
			cout << queue.front() << endl;
		}
		else if (command == "back") {
			cout << queue.back() << endl;
		}
	}
	return 0;
}
