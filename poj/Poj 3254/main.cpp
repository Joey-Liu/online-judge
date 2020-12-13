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

const int maxn = (1 << 13);
const int mode = 1e8;

LL dp[13][maxn];
LL inva[13];

int N, M, tmp;

bool check_state(int x) {
	if (x == 0) {
		return true;
	}
	return !(x & (x >> 1));
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> M >> N;
	int maxi_state = (1 << N);

	for (int i = 0; i < M; i++) {
		inva[i] = 0;
		for (int j = 0; j < N; j++) {
			cin >> tmp;
			if (tmp == 0) {
				inva[i] |= (1 << j);
			}
		}
	}

	for (int j = 0; j < (maxi_state); j++) {

		if (!check_state(j)) {
			dp[0][j] = 0;
			continue;
		}

		if (j & inva[0]) {
			dp[0][j] = 0;
		}
		else {
			dp[0][j] = 1;
		}


	}

	for (int i = 1; i < M; i++) {
		for (int j = 0; j < maxi_state; j++) {
			dp[i][j] = 0;
			if (!check_state(j)) {
				continue;
			}
			if (j & inva[i]) {
				continue;
			}

			
			for (int k = 0; k < maxi_state; k++) {
				if (j & k) {
					continue;
				}
				dp[i][j] += dp[i - 1][k];
				dp[i][j] %= mode;
			}
		}
	}

	LL res = 0;
	for (int j = 0; j < maxi_state; j++) {
		res += dp[M - 1][j];
		res %= mode;
	}
	cout << res << endl;


	return 0;
}