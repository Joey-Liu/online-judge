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
const int maxn = 20 + 5;
int N, M, K, mat[maxn][maxn], sum[maxn][maxn];
int dp[maxn][maxn][maxn][maxn];

int get_cherry(int sr, int sc, int er, int ec) {
	return sum[er][ec] - sum[er][sc - 1] - sum[sr - 1][ec] + sum[sr - 1][sc - 1];
}

int work(int sr, int sc, int er, int ec) {
	int & ans = dp[sr][sc][er][ec];
	if (ans != -1)
		return ans;

	int cherry = get_cherry(sr, sc, er, ec);
	if (cherry == 1)
		return ans = 0;
	
	ans = 0x3f3f3f3f;
	for (int i = sr; i <= er - 1; i++) {
		int cherry_a = get_cherry(sr, sc, i, ec);
		int cherry_b = get_cherry(i + 1, sc, er, ec);
		if (!cherry_a || !cherry_b)
			continue;

		ans = min(ans, ec - sc + 1 + work(sr, sc, i, ec) + work(i + 1, sc, er, ec));
	}

	for (int j = sc; j <= ec - 1; j++) {
		int cherry_a = get_cherry(sr, sc, er, j);
		int cherry_b = get_cherry(sr, j + 1, er, ec);
		if (!cherry_a || !cherry_b)
			continue;

		ans = min(ans, er - sr + 1 + work(sr, sc, er, j) + work(sr, j + 1, er, ec));
	}
	return ans;
}


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int kasenum = 0;
	while (cin >> N >> M >> K) {
		memset(mat, 0, sizeof(mat));
		for (int i = 0; i < K; i++) {
			int a, b;
			cin >> a >> b;
			mat[a][b] = 1;
		}

		memset(dp, -1, sizeof(dp));
		memset(sum, 0, sizeof(sum));
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + mat[i][j];
			}
		}

		int ans = work(1, 1, N, M);
		cout << "Case " << ++kasenum << ": " << ans << endl;
	}//while

	return 0;
}