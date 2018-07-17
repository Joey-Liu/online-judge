#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <algorithm>

using namespace std;

const int maxn = 10000 + 50;
const int inf = 0x3f3f3f3f;
int dp[maxn];

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int cost[] = { 150, 200, 350 };
	int kasenum;
	cin >> kasenum;

	while (kasenum--) {
		int V;
		cin >> V;

		memset(dp, 0x3f, sizeof(dp));
		for (int i = 0; i < 150; i++)
			dp[i] = i;

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j <= V; j++) {
				if (j < cost[i])
					continue;

				dp[j] = min(dp[j], dp[j - cost[i]]);
			}//for int j
		}
		cout << dp[V] << endl;
	}//while
	return 0;
}