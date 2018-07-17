#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>

using namespace std;

typedef long long LL;


LL quick_mul(LL a, LL b, LL c) {
	LL res = 0, base = a;
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
	LL res = 1, base = a;
	while (b) {
		if (b & 1)
			res = quick_mul(res, base, c);
		base = quick_mul(base, base, c);
		b >>= 1;
	}

	return res;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	LL n, k, p;
	cin >> n >> k >> p;
	LL res = quick_exp(k, n, p);
	cout << res << endl;
	return 0;
}