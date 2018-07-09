#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <memory.h>
#include <algorithm>

using namespace std;

const int maxn = 1000 + 50;
string str;
int dp[maxn][maxn];

int main()
{

	while (cin >> str) {
		memset(dp, 0, sizeof(dp));

		int N = str.size();
		for (int i = 0; i < N; i++) {
			dp[i][i] = 1;
		}

		for (int len = 2; len <= N; len++) {
			for (int i = 0; i < N; i++) {
				int j = i + len - 1;
				if (j >= N)
					break;

				if (str[i] == str[j])
					dp[i][j] = dp[i + 1][j - 1] + 2;
				dp[i][j] = max(dp[i + 1][j], dp[i][j]);
				dp[i][j] = max(dp[i][j - 1], dp[i][j]);
			}//for int i
		}//for int len
		cout << N - dp[0][N - 1] << endl;
	}
	return 0;
}