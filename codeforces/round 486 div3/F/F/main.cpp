#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;
const int maxn = 2000 + 5;
const int INF = 0x3f3f3f3f;
int A, N, M;
vector<bool> rained(maxn, false);
vector<vector<int> > dp(maxn, vector<int>(maxn, INF));
vector<pair<int, int>> umb(maxn, make_pair(INF, -1));
vector<int> cost(maxn, INF);

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> A >> N >> M;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		for (int j = a; j < b; j++) {
			rained[j] = true;
		}
	}

	for (int i = 0; i < M; i++) {
		int x, c;
		cin >> x >> c;
		umb[x] = min(umb[x], make_pair(c, i));
		cost[i] = c;
	}
	dp[0][M] = 0;
	for (int i = 0; i < A; i++) {
		for (int j = 0; j <= M; j++) {
			if (INF == dp[i][j])
				continue;
			if(j < M)
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + cost[j]);
			if (rained[i] == false)
				dp[i + 1][M] = min(dp[i + 1][M], dp[i][j]);
			if (umb[i].second != -1)
				dp[i + 1][umb[i].second] = min(dp[i + 1][umb[i].second], dp[i][j] + umb[i].first);
		}
	}

	int ans = INF;
	for (int i = 0; i <= M; i++) {
		ans = min(dp[A][i], ans);
	}
	if (ans == INF)
		cout << -1 << endl;
	else
		cout << ans << endl;
	return 0;
}