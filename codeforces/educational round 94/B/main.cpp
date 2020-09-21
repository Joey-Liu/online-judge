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

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int kasenum;
	LL p, f, cnt_sa, cnt_wb, sa, wb;
	cin >> kasenum;
	while (kasenum--) {
		cin >> p >> f;
		cin >> cnt_sa >> cnt_wb;
		cin >> sa >> wb;

		if (sa > wb) {
			swap(sa, wb);
			swap(cnt_sa, cnt_wb);
		}

		LL res = -1;

		for (int i = 0; i <= cnt_sa; i++) {
			int x1 = i;
			if (x1 * sa > p) {
				continue;
			}
			LL first_left = p - x1 * sa;
			LL y1 = min(first_left / wb, cnt_wb);

			LL n1 = x1 + y1;
			
			LL left_sa = cnt_sa - x1;
			LL left_wb = cnt_wb - y1;

			LL x2 = min(f / sa, left_sa);
			LL second_left = f - x2 * sa;
			LL y2 = min(second_left / wb, left_wb);

			LL tmp = x1 + y1 + x2 + y2;
			res = max(tmp, res);


		}
		cout << res << endl;

	}
	return 0;
}