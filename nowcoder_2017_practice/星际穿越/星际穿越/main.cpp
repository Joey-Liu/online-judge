#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef long long LL;

LL h;
bool work(LL num) {
	if (num * num + num <= h)
		return true;
	return false;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> h;

	LL lp = 0, rp = 1e+9 + 5;
	while (lp < rp) {
		LL mid = lp + (rp - lp) / 2;

		if (work(mid)) {
			lp = mid + 1;
		}
		else {
			rp = mid;
		}
	}
	cout << lp - 1 << endl;
	return 0;
}