#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <algorithm>

using namespace std;

const int maxn = 1000 + 10;
int dp[maxn][maxn];
int N, V;
int weight[maxn], vol[maxn];

void work() 
{
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= V; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j >= vol[i])
				dp[i][j] = max(dp[i][j], dp[i - 1][j - vol[i]] + weight[i]);
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
		cin >> N >> V;
		for (int i = 1; i <= N; i++)
			cin >> weight[i];
		for (int i = 1; i <= N; i++)
			cin >> vol[i];
		work();
		cout << dp[N][V] << endl;
	}
	return 0;
}