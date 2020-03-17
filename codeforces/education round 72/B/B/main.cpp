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
typedef pair<LL, LL> PLL;

const int maxn = 100000 + 10;
int nums[maxn];
PLL blows[maxn];

bool cmp(PLL p1, PLL p2) {
	return (p1.first - p1.second) > (p2.first - p2.second);
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int casenum = 0;
	LL N, heads, max_slu;

	cin >> casenum;
	while (casenum--) {
		cin >> N >> heads;
		max_slu = -1;
		for (int i = 0; i < N; i++) {
			cin >> blows[i].first >> blows[i].second;
			max_slu = max(max_slu, blows[i].first);
		}
		if (max_slu >= heads) {
			cout << 1 << endl;
			continue;
		}

		sort(blows, blows + N, cmp);
		int hurt = blows[0].first - blows[0].second;
		if (hurt <= 0) {
			cout << -1 << endl;
		}
		else {
			LL res = 1;
			heads -= max_slu;
			res += LL(ceil(double(heads) / hurt));
			cout << res << endl;

		}

	}
	

	return 0;
}