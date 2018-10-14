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
#include <math.h>
#include <functional>
#include <limits.h>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;


string s1, s2;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	while (cin >> s1 >> s2) {
		int len_1 = s1.size(), len_2 = s2.size();
		vector<vector<int> > dp(len_1, vector<int>(len_2, 0));

		for (int j = 0; j < len_2; j++) {
			if (s1[0] == s2[j]) {
				dp[0][j] = 1;
			}
			if (dp[0][j] == 0 && j > 0) {
				dp[0][j] = dp[0][j - 1];
			}
		}

		for (int i = 0; i < len_1; i++) {
			if (s1[i] == s2[0]) {
				dp[i][0] = 1;
			}
			if (dp[i][0] == 0 && i > 0) {
				dp[i][0] = dp[i - 1][0];
			}
		}//for int i

		for (int i = 1; i < len_1; i++) {
			for (int j = 1; j < len_2; j++) {
				if (s1[i] == s2[j]) {
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else {
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}
		cout << dp[len_1 - 1][len_2 - 1] << endl;
	}//while
	return 0;
}