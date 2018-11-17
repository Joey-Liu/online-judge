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

const int maxn = 10 + 5;
const int inf = 0x3f3f3f3f;

int dp[maxn][maxn], N;
int d[maxn][1 << maxn];

int work(int i, int j) {
	if (d[i][j] != inf)
		return d[i][j];
	for (int k = 1; k < N; k++) {
		if ((1 << k) & j)
			d[i][j] = min(d[i][j], work(k, (1 << k) ^ j) + dp[i][k]);
	}
	return d[i][j];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	while (cin >> N && N) {
		N += 1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> dp[i][j];
			}
		}

		for (int k = 0; k < N; k++) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
				}
			}
		}

		memset(d, 0x3f, sizeof(d));

		for (int state = 0; state < (1 << N); state++) {
			for (int i = 0; i < N; i++) {
				if (state == 0) {
					d[i][state] = dp[i][0];
					continue;
				}
				else if ((1 << i) & state) {
					continue;
				}

				for (int j = 0; j < N; j++) {
					if ((1 << j) & state) {
						d[i][state] = min(d[i][state], d[j][state ^ (1 << j)] + dp[i][j]);
					}
				}
			}
		}

		cout << d[0][(1 << N) - 2] << endl;
	}//while



	return 0;
}