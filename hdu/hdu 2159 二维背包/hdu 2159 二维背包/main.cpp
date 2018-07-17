#include <iostream>
#include <stdio.h>
#include <string>
#include <memory.h>
#include <algorithm>


using namespace std;

const int maxn = 150;

int dp[maxn][maxn];
int N, M, K, S, A[maxn], B[maxn];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (cin >> N >> M >> K >> S) {
		for (int i = 0; i < K; i++) {
			cin >> A[i] >> B[i];
		}

		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= S; i++) {
			for (int j = 0; j <= M; j++) {
				dp[i][j] = dp[i - 1][j];
				
				for (int k = 0; k < K; k++) {
					if (j >= B[k])
						dp[i][j] = max(dp[i - 1][j - B[k]] + A[k], dp[i][j]);
				}
			}//for int j
		}//for int i

		if (dp[S][M] < N) {
			cout << -1 << endl;
		}
		else {
			bool found = false;
			for (int j = 0; j <= M; j++) {
				for (int i = 1; i <= S; i++) {
					if (dp[i][j] >= N) {
						cout << M - j << endl;
						found = true;
						break;
					}
				}
				if (found)
					break;
			}
		}

	}//while cin

	return 0;
}