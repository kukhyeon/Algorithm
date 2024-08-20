#include <iostream>
using namespace std;
/*
	모듈러 곱셈 연산
	(a mod n * b mod n) mod n = (a * b) mod n에서 a = b이면,
	(a mod n * a mod n) mod n = (a * a) mod n = a^2 mod n
*/
unsigned long long mod_exp(unsigned long long base, unsigned long long exp, unsigned long long mod) {
	int result = 1;
	// 재귀 종료 조건
	if (exp == 0) {
		return 1;
	}
	// 재귀 종료 조건2
	if (exp == 1) {
		return base % mod;
	}
	// 이진수 exp의 자리에 1이 존재하는지 확인
	if (exp % 2 == 1) {
		result = (result * base) % mod;
	}
	// 모듈러 곱셈 법칙에 의해 A^2 % C = {(A % C) * (A % C)} % C 이니까,
	// 다음의 자릿수 후보를 업데이트 해줌
	base = (base * base) % mod;
	// 재귀 반환
	result = (result * mod_exp(base, exp / 2, mod)) % mod;

	return result;
}

int main() {
	unsigned long long base, exp, mod;
	cin >> base >> exp >> mod;
	cout << mod_exp(base, exp, mod);
}