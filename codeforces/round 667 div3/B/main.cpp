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
LL a, b, x, y, n;

LL work1(LL a, LL b, LL x, LL y, LL n) {
	LL left = min(a - x, n);
	a -= left;
	b -= min(n - left, b - y);
	return a * b;
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
		for (int i = 0; i < 5; i++) {
			cin >> nums[i];
		}

		LL r1 = work1(nums[0], nums[1], nums[2], nums[3], nums[4]);
		LL r2 = work1(nums[1], nums[0], nums[3], nums[2], nums[4]);
		cout << min(r1, r2) << endl;
	}//while

	return 0;
}