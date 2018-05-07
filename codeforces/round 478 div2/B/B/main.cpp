#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <algorithm>

using namespace std;
typedef long long LL;

const LL maxn = 14;

LL a[maxn], b[maxn];

LL work(int ind) 
{
	memcpy(b, a, sizeof(a));
	LL t = b[ind];
	b[ind] = 0;

	for (int k = 1; k <= min(t, maxn - ind - 1); k++) {
		b[ind + k] += 1;
	}
	t -= min(t, maxn - ind - 1);
	LL x = t / maxn;
	LL y = t % maxn;

	for (int i = 0; i < maxn; i++) {
		b[i] += x;
	}
	for (int i = 0; i < y; i++) {
		b[i] += 1;
	}

	LL ans = 0;
	for (int i = 0; i < maxn; i++) {
		if (0 == b[i] % 2)
			ans += b[i];
	}
	return ans;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	for (int i = 0; i < maxn; i++)
		cin >> a[i];
	
	LL res = 0;
	for (int i = 0; i < maxn; i++) {
		if (a[i] > 0) {
			res = max(res, work(i));
		}
	}
	cout << res << endl;
}