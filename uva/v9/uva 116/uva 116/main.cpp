#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;
const int maxn = 10000;
const int inf = 0x3f3f3f3f;

int tab[maxn][maxn];
int step[maxn][maxn];
int dp[maxn][maxn];

int M, N;

void work()
{
	for (int i = 0; i < M; i++)
		dp[i][N - 1] = tab[i][N - 1];

	for (int j = N - 2; j >= 0; j--) {
		for (int i = 0; i < M; i++) {
			int ans = inf, ind;
			for (int k = -1; k <= 1; k++) {
				int tmp = tab[i][j] + dp[(i + k + M) % M][j + 1];
				if (tmp < ans || (tmp == ans && (i + k + M) % M < ind)) {
					ans = tmp;
					ind = (i + k + M) % M;
				}
			}
			step[i][j] = ind;
			dp[i][j] = ans;
		}
	}
}


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (cin >> M >> N) {
		for (int i = 0; i < M; i++) 
			for (int j = 0; j < N; j++) 
				cin >> tab[i][j];
		work();
		int st = 0, ans = inf;
		for (int i = 0; i < M; i++) {
			if (ans > dp[i][0]) {
				ans = dp[i][0];
				st = i;
			}
		}

		cout << st + 1;
		for (int i = st, j = 0; j < N - 1; j++) {
			cout << " " << step[i][j] + 1;
			i = step[i][j];
		}
		cout << endl<< dp[st][0] << endl;
	}
	return 0;
}