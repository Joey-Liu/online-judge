#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <algorithm>

using namespace std;

typedef long long LL;
const int maxn = 50 + 50;


LL dp[maxn][maxn], pd[maxn][maxn];
LL N, A[maxn], K, D;
bool v1[maxn][maxn], v2[maxn][maxn];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	while (cin >> N) {
		for (LL i = 1; i <= N; i++) {
			cin >> A[i];
		}

		cin >> K >> D;
		memset(v1, false, sizeof(v1));
		memset(v2, false, sizeof(v2));
		memset(v1, 0, sizeof(v1));
		memset(v2, 0, sizeof(v2));


		for (LL i = 1; i <= N; i++) {
			dp[1][i] = A[i];
			pd[1][i] = A[i];
		}

		for (LL i = 2; i <= K; i++) {
			for (LL j = i; j <= N; j++) {
				
				for (LL m = max(i - 1, j - D); m <= j - 1; m++) {
					if (!v1[i][j]) {
						dp[i][j] = dp[i - 1][m] * A[j];
						v1[i][j] = true;
					}
					if (!v2[i][j]) {
						pd[i][j] = dp[i - 1][m] * A[j];
						v2[i][j] = true;
					}

					dp[i][j] = max(dp[i - 1][m] * A[j], dp[i][j]);
					dp[i][j] = max(pd[i - 1][m] * A[j], dp[i][j]);

					pd[i][j] = min(pd[i - 1][m] * A[j], pd[i][j]);
					pd[i][j] = min(dp[i - 1][m] * A[j], pd[i][j]);
				}
			}//for LL j
		}//for LL i
		
		LL ans = dp[K][K];
		for (LL i = K + 1; i <= N; i++) {
			ans = max(ans, dp[K][i]);
		}
		cout << ans << endl;
	}//while
	return 0;
}