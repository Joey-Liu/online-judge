#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <algorithm>

using namespace std;

int N, K;
int dp[520][520 * 12];
int a[100000 + 5], b[100000 + 5];
int joy[12];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> N >> K;
	for (int i = 0; i < N * K; i++) {
		int x;
		cin >> x;
		b[x]++;
	}

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		a[x]++;
	}

	for (int i = 1; i <= K; i++) {
		cin >> joy[i];
	}

	for (int x = 0; x < N; x++) {
		for (int y = 0; y <= N * K; y++) {
			for (int i = 0; i <= K; i++) {
				dp[x + 1][y + i] = max(dp[x + 1][y + i], dp[x][y] + joy[i]);
			}
		}
	}

	int ans = 0;
	for (int i = 1; i < 100005; i++) {
		ans += dp[a[i]][b[i]];
	}

	cout << ans << endl;
	return 0;
}