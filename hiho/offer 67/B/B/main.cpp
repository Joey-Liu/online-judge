#include <iostream>
#include <stdio.h>
#include <string>
#include <memory.h>

using namespace std;

typedef long long LL;

LL N, K, P;

LL quick_mul(LL a, LL b, LL c) {

	LL base = a, res = 0;
	while (b) {
		if (b & 1) {
			res = (res + base) % c;
		}

		base = base * 2 % c;
		b >>= 1;
	}
	return res;
}

LL quick_exp(LL a, LL b, LL c) {
	LL base = a, res = 1;
	while (b) {
		if (b & 1) {
			res = quick_mul(res, base, c);
		}

		base = quick_mul(base, base, c);
		b >>= 1;
	}
	return res;
}

int main()
{
	cin >> K >> N >> P;
	cout << quick_exp(N, K, P) << endl;
	return 0;
}