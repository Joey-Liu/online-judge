#include <iostream>
#include <stdio.h>
#include <string>
#include <memory.h>

using namespace std;

typedef long long LL;

LL N, K, P;

LL quick_exp(LL a, LL b, LL c) {
	LL res = 1;
	a %= c;
	LL base = a;

	while (b) {
		if (b & 1) {
			res = (res * base) % c;
		}
		base = base * base % c;
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