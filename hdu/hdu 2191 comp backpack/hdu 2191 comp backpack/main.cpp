#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <memory.h>

using namespace std;

const int maxn = 100 + 50;

int dp[maxn], N, M;
int V[maxn], W[maxn], C[maxn];

void comp_pack(int v, int w) {
	for (int i = v; i <= N; i++) {
		dp[i] = max(dp[i], dp[i - v] + w);
	}
}

void zeroone_pack(int v, int w) {
	for (int i = N; i >= v; i--) {
		dp[i] = max(dp[i], dp[i - v] + w);
	}
}

void multi_pack(int v, int w, int cnt) {
	if (cnt * v >= N) {
		comp_pack(v, w);
		return;
	}

	for (int i = 1; i <= cnt; i *= 2) {
		zeroone_pack(i * v, i * w);
		cnt -= i;
	}
	zeroone_pack(cnt * v, cnt * w);
}


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int kasenum;
	cin >> kasenum;
	while (kasenum--) {
		cin >> N >> M;
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < M; i++) {
			cin >> V[i] >> W[i] >> C[i];
			multi_pack(V[i], W[i], C[i]);
		}

		cout << dp[N] << endl;
	}
	return 0;
}