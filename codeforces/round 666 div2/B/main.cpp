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
LL nums[maxn];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	LL N, amx = -1, f1 = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
		amx = max(amx, nums[i]);
		f1 += (nums[i] - 1);
	}
	sort(nums, nums + N);

	LL c = 1, res = 0x3f3f3f3f3f3f3f3f;
	while (true) {
		LL t = 1;
		for (int i = 0; i < N - 1; i++) {
			t *= c;
			if (t > f1 + amx) {
				break;
			}
		}
		if (t > f1 + amx) {
			break;
		}

		LL cur = 1, tmp = 0;
		for (int i = 0; i < N; i++) {
			tmp += abs(cur - nums[i]);
			cur *= c;
		}
		res = min(res, tmp);
		c += 1;
	}

	cout << res << endl;


	return 0;
}