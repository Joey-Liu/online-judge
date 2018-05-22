#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

typedef long long LL;
const int maxn = 100 + 5;
LL ans[maxn], v[maxn], a, b;

LL gcd(LL a, LL b) {
	while (b) {
		LL t = a;
		a = b;
		b = t % b;
	}
	return a;
}

LL get_first(LL aa, LL bb) {
	return bb / aa + 1;
}

bool better(int d) {
	for (int i = d; i >= 0; i--) {
		if(ans[i] != v[i]) {
			if (ans[i] == -1 || v[i] < ans[i])
				return true;
		}
	}
	return false;
}

bool dfs(int d, int layer, LL aa, LL bb, LL prev) {
	if (layer == d) {
		if (bb % aa) return false;
		v[d] = bb / aa;
		if (v[d] < v[d - 1])
			return false;
		if (better(d)) {
			memcpy(ans, v, sizeof(LL) * (d + 1));
			return true;
		}
		return false;
	}
	
	bool ok = false;
	LL from = max(prev, get_first(aa, bb));
	for (LL i = from; ; i++) {
		if ((layer - 1 + d) * bb <= aa * i)
			break;
		LL na = i * aa - bb;
		LL nb = bb * i;
		v[d] = i;
		LL g = gcd(na, nb);
		if (dfs(d + 1, layer, na / g, nb/ g, i + 1)) {
			ok = true;
		}
	}
	return ok;
}

int main()
{
	int kasenum;
	cin >> kasenum;
	while (kasenum--) {
		cin >> a >> b;
		memset(ans, -1, sizeof(ans));
		memset(v, -1, sizeof(v));
		int layer;
		for (layer = 1;layer < maxn; layer++) {
			if (dfs(1, layer, a, b, get_first(a, b))) {
				break;
			}
		}

		for (int i = 1; i <= layer; i++)
			cout << " " << ans[i];
		cout << endl;
	}
	return 0;
}