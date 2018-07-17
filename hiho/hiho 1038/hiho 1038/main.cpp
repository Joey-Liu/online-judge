#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <algorithm>

using namespace std;
const int maxn = 100000 + 10;

int dp[500 + 10][maxn];
int N, M, val[500 + 10], cost[500 + 10];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> cost[i] >> val[i];
	}

	for (int j = M; j >= cost[N - 1]; j--) {
		dp[N - 1][j] = val[N - 1];
	}

	for (int i = N - 2; i >= 0; i--) {
		for (int j = M; j >= 0; j--) {
			if (j >= cost[i])
				dp[i][j] = max(val[i] + dp[i + 1][j - cost[i]], dp[i + 1][j]);
			else
				dp[i][j] = dp[i + 1][j];
		}
	}
	cout << dp[0][M] << endl;
	return 0;
}