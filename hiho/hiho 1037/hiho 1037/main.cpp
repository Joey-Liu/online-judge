#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>


using namespace std;

const int maxn = 200 + 10;
int dp[maxn][maxn], num[maxn][maxn], N;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> num[i][j];
		}
	}

	for (int j = 1; j <= N; j++) {
		dp[N][j] = num[N][j];
	}

	for (int i = N - 1; i >= 1; i--) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] = num[i][j] + max(dp[i + 1][j], dp[i + 1][j + 1]);
		}
	}//for int i

	cout << dp[1][1] << endl;
	return 0;
}