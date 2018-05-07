#include <iostream>
#include <string>
#include <string.h>
#include <memory.h>
#include <algorithm>

using namespace std;

const int maxn = 1000 + 10;

int dp[maxn][maxn];
char s1[maxn], s2[maxn];

int work()
{
	memset(dp, 0, sizeof(dp));
	int len1 = strlen(s1 + 1);
	int len2 = strlen(s2 + 1);
	
	for (int i = 1; i < len1 + 1; i++) {
		for (int j = 1; j < len2 + 1; j++) {
			if (s1[i] == s2[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	return dp[len1][len2];
}


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (cin.getline(s1 +1, maxn)) {
		cin.getline(s2 + 1, maxn);
		int res = work();
		cout << res << endl;
	}
	return 0;
}