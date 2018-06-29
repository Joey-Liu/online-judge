#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

typedef long long LL;
typedef pair<LL, LL> PLL;

const int maxn = 200000 + 10;

LL N, ans[maxn];
PLL seg[maxn];
vector<LL> coord;

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> seg[i].first >> seg[i].second;
		seg[i].second++;
		coord.push_back(seg[i].first);
		coord.push_back(seg[i].second);
	}

	sort(coord.begin(), coord.end());
	int len = unique(coord.begin(), coord.end()) - coord.begin();
	coord.resize(len);

	int cnt[maxn << 1];
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < N; i++) {
		LL p = lower_bound(coord.begin(), coord.end(), seg[i].first) - coord.begin();
		LL q = lower_bound(coord.begin(), coord.end(), seg[i].second) - coord.begin();
		cnt[p]++;
		cnt[q]--;
	}

	for (int i = 1; i < len; i++) {
		cnt[i] += cnt[i - 1];
	}

	for (int i = 0; i < len - 1; i++) {
		ans[cnt[i]] += coord[i + 1] - coord[i];
	}

	for (int i = 1; i <= N; i++) {
		cout << ans[i] << endl;
	}
	return 0;
}