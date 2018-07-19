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

using namespace std;
typedef long long LL;
typedef pair<LL, LL> PLL;

const int maxn = 200000 + 50;

int N;
vector<PLL> seg(maxn);
vector<LL> point;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> seg[i].first >> seg[i].second;
		seg[i].second++;
		point.push_back(seg[i].first);
		point.push_back(seg[i].second);
	}

	sort(point.begin(), point.end());
	int len = unique(point.begin(), point.end()) - point.begin();
	point.resize(len);

	int cnt[maxn * 2] = { 0 };

	for (int i = 0; i < seg.size(); i++) {
		int inda = lower_bound(point.begin(), point.end(), seg[i].first) - point.begin();
		int indb = lower_bound(point.begin(), point.end(), seg[i].second) - point.begin();
		cnt[inda]++;
		cnt[indb]--;
	}

	for (int i = 1; i < point.size(); i++) {
		cnt[i] += cnt[i - 1];
	}
	
	LL ans[maxn] = { 0 };
	for (int i = 0; i < len - 1; i++) {
		ans[cnt[i]] += point[i + 1] - point[i];
	}

	for (int i = 1; i <= N; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}