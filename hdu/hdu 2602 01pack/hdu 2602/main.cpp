#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <memory.h>
#include <algorithm>

using namespace std;

const int maxn = 2000;
int cost[maxn], weight[maxn], N, V;
int dp[maxn];

void zeroone(int w, int c) {
	for (int i = V; i >= c; i--)
		dp[i] = max(dp[i], dp[i - c] + w);
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int kasenum;
	cin >> kasenum;
	while (kasenum--) {
		cin >> N >> V;
		for (int i = 0; i < N; i++)
			cin >> weight[i];
		for (int i = 0; i < N; i++)
			cin >> cost[i];

		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < N; i++) {
			zeroone(weight[i], cost[i]);
		}

		cout << dp[V]<<endl;
	}

	return 0;
}