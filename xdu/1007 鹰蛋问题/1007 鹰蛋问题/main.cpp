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

const int maxn = 1000 + 20;

int dp[maxn][maxn], N, K;


int work(int i, int j) {
	if (-1 != dp[i][j])
		return dp[i][j];

	int ans = 0x3f3f3f3f;
	for (int k = 1; k <= i; k++) {
		int t = max(work(k - 1, j - 1), work(i - k, j)) + 1;
		ans = min(t, ans);
	}
	return dp[i][j] = ans;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	while (cin >> K >> N) {
		memset(dp, -1, sizeof(dp));
		for (int i = 1; i <= N; i++) {
			dp[i][1] = i;
		}

		for (int j = 1; j <= K; j++) {
			dp[1][j] = 1;
		}
		for (int j = 0; j <= K; j++) {
			dp[0][j] = 0;
		}

		for (int i = 1; i <= N; i++) {
			dp[i][0] = 0x3f3f3f3f;
		}

		int ans = work(N, K);
		cout << ans << endl;
	}//while

	return 0;
}