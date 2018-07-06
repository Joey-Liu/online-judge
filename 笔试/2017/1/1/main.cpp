#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <limits.h>

using namespace std;

const int maxn = 50 + 20;
const int inf = INT_MAX;


int N, A[maxn], dp[maxn][maxn], pd[maxn][maxn];
bool v1[maxn][maxn], v2[maxn][maxn];
int K, D;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	while (cin >> N) {
		for (int i = 1; i <= N; i++) {
			cin >> A[i];
		}

		cin >> K >> D;
		memset(dp, -1, sizeof(dp));
		memset(pd, -1, sizeof(pd));
		memset(v1, false, sizeof(v1));
		memset(v2, false, sizeof(v2));


		for (int i = 1; i <= N; i++) {
			dp[1][i] = A[i];
			pd[1][i] = A[i];
		}

		for (int i = 2; i <= K; i++) {
			for (int j = i; j <= N; j++) {
				for (int k = max(1, j - D); k <= j - 1; k++) {
					if(dp[i][j] == -1)
					dp[i][j] = max(dp[i - 1][k] * A[j], dp[i][j]);
					dp[i][j] = max(pd[i - 1][k] * A[j], dp[i][j]);
					pd[i][j] = min(pd[i][j], dp[i - 1][k] * A[j]);
					pd[i][j] = min(pd[i][j], pd[i - 1][k] * A[j]);
				}
			}
		}
		int tmp = -inf;
		for (int i = K; i <= N; i++) {
			tmp = max(tmp, dp[K][i]);
		}

		cout << tmp << endl;
	}
	return 0;
}