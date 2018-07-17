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

int N;
const int maxn = 200000 + 50;
int dp[maxn], c[maxn];

vector<int> color[maxn];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> N;

	for (int i = 1; i <= N; i++) {
		int t;
		cin >> t;
		color[t].push_back(i);
		c[i] = t;
	}

	memset(dp, 0, sizeof(dp));
	for (int i = 2; i <= N; i++) {
		dp[i] = dp[i - 1] + 1;
		int pos = lower_bound(color[c[i]].begin(), color[c[i]].end(), i) - color[c[i]].begin();

		if (pos - 1 >= 0 && pos - 1 < color[c[i]].size()) {
			dp[i] = min(dp[color[c[i]][pos - 1]] + 1, dp[i]);
		}
	}
	cout << dp[N] << endl;
	return 0;
}