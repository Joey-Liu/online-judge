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
#include <math.h>
#include <functional>
#include <limits.h>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;

const int maxn = 100000 + 10;
int nums[maxn];

bool check(LL n, LL s) {
	LL tmp = 0;
	while (n) {
		tmp += n % 10;
		n /= 10;
	}
	return tmp <= s;
}

LL mypow(int n) {
	LL res = 1;
	for (int i = 0; i < n; i++) {
		res *= 10;
	}
	return res;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int kasenum;
	cin >> kasenum;
	while (kasenum--) {
		LL n, s, sum = 0, old_n;
		cin >> n >> s;
		old_n = n;
		vector<LL> vi;
		while (n) {
			int t = n % 10;
			vi.emplace_back(t);
			n /= 10;
		}
		n = old_n;

		LL tmp = mypow(vi.size());
		LL res = tmp - n;
		LL pre_sum = 0;
		for (int i = vi.size() - 1; i >= 0; i--) {
			LL a = mypow(i) * (vi[i] + 1L);
			LL tmp = pre_sum + a;
			if (check(tmp, s)) {
				res = min(res, tmp - n);
			}
			pre_sum += mypow(i) * vi[i];
		}
		if (check(n, s)) {
			res = 0;
		}

		cout << res << endl;



	}

	return 0;
}