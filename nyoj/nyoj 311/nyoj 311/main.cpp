#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <memory.h>

using namespace std;

const int maxn = 100010;
const int inf = 0x3f3f3f3f;
int dp[maxn], M, V, c, w;

void work()
{
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= V; i++)
		dp[i] = -inf;

	for (int i = 0; i < M; i++) {
		cin >> c >> w;
		for (int j = c; j <= V; j++) {
			dp[j] = max(dp[j], dp[j - c] + w);
		}
	}

}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int kasenum = 0;
	cin >> kasenum;
	while (kasenum--) {
		cin >> M >> V;
		work();
		if (dp[V] >= 0) {
			cout << dp[V] << endl;
		} 
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
}