#include <iostream>
#include <stdio.h>
#include <string>
#include <memory.h>
#include <algorithm>

using namespace std;
typedef long long LL;

int main()
{
	freopen("in.txt", " r", stdin);
	freopen("out.txt", "w", stdout);
	LL n, m, a, b;
	cin >> n >> m >> a >> b;

	LL t = n % m;
	if (0 == t) {
		cout << 0 << endl;
	}
	else {
		LL x = t * b;
		LL y = (m - t) * a;
		cout << min(x, y) << endl;

	}

	return 0;
}