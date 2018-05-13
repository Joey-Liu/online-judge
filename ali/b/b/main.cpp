#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 10000 + 10;
vector<int> edges[MAXN];
LL dp[MAXN];

LL solve(int i) {
	if (dp[i] != -1) 
		return dp[i];

	LL tot = 1;
	for (int nxt : edges[i]) {
		tot += solve(nxt);
	}
	return dp[i] = tot;
}


int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	int m, a, b;
	cin >> m >> a;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		edges[a].push_back(b);
	}

	LL ret = 0;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++) {
		if (dp[i] == -1)
			solve(i);
		ret = max(ret, dp[i]);
	}
	cout << ret - 1 << endl;
	return 0;
}
