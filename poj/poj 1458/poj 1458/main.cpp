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

const int maxn = 500;
int dp[maxn][maxn];

char s1[maxn], s2[maxn];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (cin >> (s1 + 1)) {
		cin >> (s2 + 1);
		memset(dp, 0, sizeof(dp));

		int len_1 = strlen(s1 + 1);
		int len_2 = strlen(s2 + 1);

		for (int i = 1; i <= len_1; i++) {
			for (int j = 1; j <= len_2; j++) {
				if (s1[i] == s2[j]) {
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else {
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}
		cout << dp[len_1][len_2] << endl;
	}
	return 0;
}