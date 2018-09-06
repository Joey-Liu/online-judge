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

LL gcd(LL a, LL b) {
	LL c;
	while (b) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}


long long N, K, a, g;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	cin >> N >> K;
	cin >> g;
	for (LL i = 1; i < N; i++) {
		cin >> a;
		g = gcd(g, a);
	}

	set<LL> si;
	for (LL i = 1; i <= K; i++) {
		si.insert((i * g) % K);
	}
	cout << si.size() << endl;
	for (auto it = si.begin(); it != si.end(); it++) {
		cout << *it << " ";
	}
	return 0;
}