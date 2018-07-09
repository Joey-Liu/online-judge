#include <iostream>
#include <memory.h>
#include <stdlib.h>

using namespace std;
const int maxn = 16;

double poss[maxn][maxn];
double dp[maxn][5];

double work(int n, int layer) {
	if (dp[n][layer] != -1)
		return dp[n][layer];

	if (0 == layer)
		return dp[n][layer] = (n % 2 ? poss[n][n - 1] : poss[n][n + 1]);
	
	double ans = 0.0;
	int group = (1 << layer);
	int cur_group = n / group, nxt_group;
	if (cur_group % 2) {
		nxt_group = cur_group - 1;
	}
	else
		nxt_group = cur_group + 1;
	int st = nxt_group * (1 << layer);
	int ed = (nxt_group + 1) * (1 << layer) - 1;


	for (int i = st; i <= ed; i++) {
		ans += work(n, layer - 1) * work(i, layer - 1) * poss[n][i];
	}
	return dp[n][layer] = ans;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	for (int i = 0; i < maxn; i++) {
		for (int j = 0; j < maxn; j++) {
			cin >> poss[i][j];
		}
	}

	for (int i = 0; i < maxn; i++) {
		for (int j = 0; j < 5; j++) {
			dp[i][j] = -1;
		}
	}

	work(0, 3);
	printf("%.10lf", dp[0][3]);
	for (int i = 1; i < 16; i++) {
		printf(" %.10lf", work(i, 3));
	}
	return 0;
}