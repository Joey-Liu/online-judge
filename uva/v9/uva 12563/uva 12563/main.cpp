#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;

const int maxn = 180 * 50 + 678 + 10;

int n, t;
int tim[50 + 10];
int dp[50 + 10][maxn], cnt[50 + 10][maxn];

void work()
{
	memset(dp, 0, sizeof(dp));
	memset(cnt, 0, sizeof(cnt));
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= t; j++) {
			dp[i][j] = dp[i - 1][j];
			cnt[i][j] = cnt[i - 1][j];
			if (j >= tim[i]) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - tim[i]] + tim[i]);
				cnt[i][j] = max(cnt[i][j], cnt[i - 1][j - tim[i]] + 1);
			}
		}
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int kasenum, kase = 0;
	cin >> kasenum;
	while (kasenum--) {
		cin >> n >> t;
		int ti = t;
		for (int i = 1; i <= n; i++) {
			cin >> tim[i];
		}
		t -= 1;
		work();
		int ans = dp[n][t] + 678;

		cout << "Case " << ++kase << ": " << cnt[n][t] + 1 << " " << ans << endl;
	}//while kasenum
	return 0;
}