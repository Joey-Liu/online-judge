#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <algorithm>

using namespace std;
const int maxn = 500 + 50;

typedef int LL;

LL W[maxn], V[maxn], N, B;
LL dp[5000 + 50];
LL tot_v = 0, tot_w = 0;

bool work(LL tar) {
	memset(dp, 0x3f, sizeof(dp));
	dp[0] = 0;
	dp[tot_v] = tot_w;

	for (int i = 0; i < N; i++) {
		for (LL j = tar; j >= V[i]; j--) {
			dp[j] = min(dp[j], dp[j - V[i]] + W[i]);
		}
	}
	return dp[tar] <= B;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T;
	cin >> T;
	for (int kasenum = 0; kasenum < T; kasenum++) {
		tot_v = 0; tot_w = 0;
		cin >> N >> B;
		for (int i = 0; i < N; i++) {
			cin >> W[i] >> V[i];
			tot_v += V[i];
			tot_w += W[i];
		}
		
		memset(dp, 0x3f, sizeof(dp));
		dp[0] = 0;
		for (int i = 0; i < N; i++) {
			for (int j = tot_v; j >= V[i]; j--) {
				dp[j] = min(dp[j], dp[j - V[i]] + W[i]);
			}
		}

		for (int ind = tot_v; ind >= 0; ind--) {
			if (dp[ind] <= B) {
				cout << ind << endl;
				break;
			}
		}
	}
	return 0;
}