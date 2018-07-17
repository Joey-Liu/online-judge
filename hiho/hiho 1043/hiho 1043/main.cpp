#include <iostream>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

const int maxn = 100000 + 20;

int val[505], cost[505];
int N, M, dp[maxn];

int main() 
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> cost[i] >> val[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = cost[i]; j <= M; j++) {
			dp[j] = max(dp[j], dp[j - cost[i]] + val[i]);
		}
	}

	cout << dp[M] << endl;
	return 0;
}