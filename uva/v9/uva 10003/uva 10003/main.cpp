#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>

using namespace std;

const int maxn = 50 + 20;
int len, N, point[maxn], dp[maxn][maxn];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (cin >> len && len) {
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> point[i];
		}

		point[0] = 0;
		point[++N] = len;

		memset(dp, 0x3f, sizeof(dp));
		for (int i = 0; i <= N; i++) {
			dp[i][i] = 0;
		}

		for (int i = 0; i < N; i++) {
			dp[i][i + 1] = 0;
		}

		for (int len = 2; len <= N; len++) {
			for (int i = 0; i + len <= N; i++) {
				int j = i + len;
				for (int k = i + 1; k < j; k++) {
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + point[j] - point[i]);
				}
			}
		}
		cout << "The minimum cutting is " << dp[0][N] << ".\n";
	}//while

	return 0;
}