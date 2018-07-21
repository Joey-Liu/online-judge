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

const int maxn = 1000 + 50;
int N, dp[maxn];
bool parl[maxn][maxn];

string str;

void init() {
	for (int i = 0; i < N; i++) {
		parl[i][i] = true;
	}

	for (int len = 2; len <= N; len++) {
		for (int i = 0; i <= N - len; i++) {
			int j = i + len - 1;
			if (str[i] == str[j] && (i + 1 > j - 1 || parl[i + 1][j - 1]))
				parl[i][j] = true;
		}//int i
	}//for len
}


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int kasenum;
	cin >> kasenum;
	while (kasenum--) {
		cin >> str;
		memset(parl, false, sizeof(parl));
		N = str.size();

		init();

		memset(dp, 0x3f, sizeof(dp));
		dp[0] = 1;
		for (int i = 1; i < N; i++) {
			for (int j = 0; j < i; j++) {
				if (parl[j + 1][i]) {
					dp[i] = min(dp[i], dp[j] + 1);
				}
			}//for int j
			if (parl[0][i])
				dp[i] = 1;
		}//for int i
		cout << dp[N - 1] << endl;
	}

	return 0;
}