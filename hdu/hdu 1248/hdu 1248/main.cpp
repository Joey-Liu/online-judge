#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <memory.h>
#include <algorithm>

using namespace std;

const int maxn = 10000 + 50;

int dp[maxn];
const int cost[] = { 150, 200, 350 };

int work(int S) {
	if (dp[S] != -1)
		return dp[S];

	dp[S] = S;
	for (int i = 0; i < 3; i++) {
		if(S >= cost[i])
			dp[S] = min(dp[S], work(S - cost[i]));
	}
	return dp[S];
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int kasenum;
	cin >> kasenum;
	while (kasenum--) {
		int S;
		cin >> S;
		memset(dp, -1, sizeof(dp));

		int ans = work(S);
		cout << ans << endl;
	}
	return 0;
}