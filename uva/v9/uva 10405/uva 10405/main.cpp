#include <iostream>
#include <memory.h>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;
const int maxn = 1000 + 10;
int dp[maxn][maxn];
char s1[maxn], s2[maxn];
int len_1, len_2;

void work()
{
	memset(dp, 0, sizeof(dp));
	len_1 = strlen(s1 + 1);
	len_2 = strlen(s2 + 1);
	for (int i = 1; i <= len_1; i++) {
		for (int j = 1; j <= len_2; j++) {
			if (s1[i] == s2[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else {
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}//for int j
	}//for int i
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (cin.getline(s1 + 1, maxn - 2)) {
		cin.getline(s2 + 1, maxn - 2);
		work();
		cout << dp[len_1][len_2]<<endl;
	}
	return 0;
}