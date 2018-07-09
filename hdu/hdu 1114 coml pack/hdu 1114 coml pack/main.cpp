#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <memory.h>
#include <algorithm>

using namespace std;

const int maxn = 10000 + 50;
const int inf = 0x3f3f3f3f;
int E, F, weight[maxn], val[maxn], W, N;
int dp[maxn];
bool vis[maxn];


void comple(int w, int v) {
	for (int i = w; i <= W; i++) {
		dp[i] = min(dp[i], dp[i - w] + v);
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

		for (int i = 0; i < N; i++) {
			cin >> val[i] >> weight[i];
		}
		
		memset(vis, false, sizeof(vis));
		memset(dp, 0x3f, sizeof(dp));
		vis[0] = true;
		dp[0] = 0;

		for (int i = 0; i < N; i++) {
			comple(weight[i], val[i]);
		}//for int i
		if (dp[W] == inf) {
			cout << "This is impossible." << endl;
		}
		else {
			cout << "The minimum amount of money in the piggy-bank is ";
			cout << dp[W] << ".\n";
		}
	}//while

	return 0;
}