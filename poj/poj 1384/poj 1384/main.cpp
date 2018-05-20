#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <algorithm>

using namespace std;

const int maxn = 505;
const int inf = 0x3f3f3f3f;
int dp[10005];

int E, F, W, N, p[maxn], we[maxn];

void work()
{
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= W; i++)
		dp[i] = inf;

	for (int i = 1; i <= N; i++) {
		for (int j = we[i]; j <= W; j++) {
			dp[j] = min(dp[j], dp[j - we[i]] + p[i]);
		}
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int kasenum;
	cin >> kasenum;
	while (kasenum--) {
		cin >> E >> F;
		W = F - E;
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> p[i] >> we[i];
		}
		work();
		if (dp[W] >= inf)
			cout << "This is impossible." << endl;
		else {
			cout << "The minimum amount of money in the piggy-bank is ";
			cout << dp[W] << "." << endl;
		}
	}
	return 0;
}