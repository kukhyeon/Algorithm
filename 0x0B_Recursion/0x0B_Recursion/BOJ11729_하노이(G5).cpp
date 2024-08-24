#include <iostream>
#include <cmath> 
using namespace std;

void move(char from, char dest) {
	cout << from << ' ' << dest << '\n';
}

void hanoi(int round, char from, char via, char dest) {
	if (round == 1) {
		move(from, dest);
	}
	else {
		hanoi(round - 1, from, dest, via);
		move(from, dest);
		hanoi(round - 1, via, from, dest); 
	}
}

int main() {
	int num;
	cin >> num;
	cout << (int)pow(2, num) - 1 << "\n";
	hanoi(num, '1', '2', '3'); 
}
