#include <iostream>
using namespace std;

int power(int bottom, int exp) {
	if (exp > 1) {
		bottom *= power(bottom, exp - 1);
	}
	return bottom;
}

int main() {
	cout << power(6, 100);
}