#include <iostream>
#include <vector>
using namespace std;

vector<int> mods;

int main() {
	unsigned long long bottom, power, mod;
	cin >> bottom >> power >> mod;
	int result;
	for (int i = 0; i < power; i++) {
		bottom *= bottom;
		mods.push_back(bottom % mod);
		if (i > 0 && mods[0] == mods[i]) {
			result = power % mods.size();
			break;
		}
	}
	if (mods.size() == 1) {
		cout << mods[0];
	}
	else {
		cout << mods[result];
	}
}