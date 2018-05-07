#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;

const int maxn = 1000 + 10;
int dp[maxn][maxn];
char s1[maxn], s2[maxn];
int len_1, len_2;


int work()
{
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i < len_1 + 1; i++) {
		for (int j = 1; j < len_2 + 1; j++) {
			if (s1[i] == s2[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}		
		}
	}
	return dp[len_1][len_2];
}


int main()
{
	while (cin >> (s1 + 1)) {
		cin >> s2 + 1;
		len_1 = strlen(s1 + 1);
		len_2 = strlen(s2 + 1);
		int ans = work();

		cout << ans << endl;
	}
	return 0;
}