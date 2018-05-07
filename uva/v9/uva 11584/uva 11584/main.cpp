#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;
const int maxn = 1000 + 10;
const int INF = 0x3f3f3f3f;
bool palino[maxn][maxn];
int dp[maxn];

int N;
string str;

void init()
{
	memset(palino, false, sizeof(palino));
	for (int i = 0; i < N; i++) {
		palino[i][i] = true;
	}


	for (int L = 2; L <= N; L++) {
		for(int i = 0;i < N;i++) {
			int j = i + L - 1;
			if (j >= N)
				break;
			if (str[j] == str[i] && (i + 1 > j - 1 || palino[i + 1][j - 1]))
				palino[i][j] = true;
		}
	}
}

void work()
{
	dp[0] = 1;
	for (int i = 1; i < N; i++) {
		dp[i] = INF;
		if (palino[0][i])
			dp[i] = 1;
		for (int j = 1; j <= i; j++) {
			if(palino[j][i])
				dp[i] = min(dp[i], dp[j - 1] + 1);
		}
	}
}

int main()
{
	int kasenum;
	cin >> kasenum;
	while (kasenum--) {
		cin >> str;
		N = str.size();
		init();
		work();
		cout << dp[N - 1] << endl;
	}
	return 0;

}