#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;
typedef long long LL;

const int maxn = 10000 + 50;
LL tab[2][maxn];
LL dp[2][maxn][2][2];
int M;

LL work() 
{
	memset(dp, 0, sizeof(dp));
	dp[0][M - 1][0][0] = dp[0][M - 1][1][0] = tab[1][M - 1];
	//dp[0][M - 1][0][1] = dp[0][M - 1][1][1] = tab[1][M - 1];


	for (int y = M - 2; y >= 0; y--) {
		int x = 1;
		dp[x][y][0][1] = dp[x][y + 1][1][0] + tab[x][y + 1];
		dp[x][y][1][1] = dp[x][y + 1][0][0] + tab[x][y + 1];

		dp[x - 1][y][0][1] = dp[x - 1][y + 1][1][0] + tab[x - 1][y + 1];
		dp[x - 1][y][1][1] = dp[x - 1][y + 1][0][0] + tab[x - 1][y + 1];

		dp[x][y][0][0] = max(dp[x - 1][y][1][1] + tab[x - 1][y], dp[x][y][0][1]);
		dp[x][y][1][0] = min(dp[x - 1][y][0][1] + tab[x - 1][y], dp[x][y][1][1]);
		
		dp[x - 1][y][0][0] = max(dp[x][y][1][1] + tab[x][y], dp[x - 1][y][0][1]);
		dp[x - 1][y][1][0] = min(dp[x][y][0][1] + tab[x][y], dp[x - 1][y][1][1]);
	}

	return dp[0][0][1][0] + tab[0][0];
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	cin >> M;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < M; j++) {
			cin >> tab[i][j];
		}
	}

	LL res = work();
	cout << res << endl;
	return 0;

}