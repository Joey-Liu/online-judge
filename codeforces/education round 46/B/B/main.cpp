#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long LL;
typedef pair<LL, LL> PII;
const LL maxn = 100000 + 20;



LL N, M, A[maxn];
vector<PII> d1, d2;
LL pre_sum_1[maxn], pre_sum_2[maxn];
LL suf_sum_1[maxn], suf_sum_2[maxn];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	LL pre = 0, cur;
	bool flag = false;
	d1.push_back(make_pair(0, 0));
	d2.push_back(make_pair(0, 0));

	for (LL i = 0; i < N; i++) {
		cin >> cur;
		if (!flag)
			d1.push_back(make_pair(pre, cur));
		else
			d2.push_back(make_pair(pre, cur));
		pre = cur;
		flag = !flag;
	}
	cur = M;
	if (!flag)
		d1.push_back(make_pair(pre, cur));
	else
		d2.push_back(make_pair(pre, cur));


	for (LL i = 1; i < d1.size(); i++) {
		pre_sum_1[i] = pre_sum_1[i - 1] + d1[i].second - d1[i].first;
	}
	for (LL i = 1; i < d2.size(); i++) {
		pre_sum_2[i] = pre_sum_2[i - 1] + d2[i].second - d2[i].first;
	}

	suf_sum_1[d1.size() - 1] = d1.back().second - d1.back().first;
	for (LL i = d1.size() - 2; i >= 1; i--) {
		suf_sum_1[i] = suf_sum_1[i + 1] + d1[i].second - d1[i].first;
	}

	suf_sum_2[d2.size() - 1] = d2.back().second - d2.back().first;
	for (LL i = d2.size() - 2; i >= 1; i--) {
		suf_sum_2[i] = suf_sum_2[i + 1] + d2[i].second - d2[i].first;
	}

	LL ans = pre_sum_1[d1.size() - 1];
	for (LL i = 1; i < d1.size(); i++) {
		LL tmp = pre_sum_1[i] - 1 + suf_sum_2[i];
		ans = max(tmp, ans);
	}

	cout << ans << endl;
	return 0;
}