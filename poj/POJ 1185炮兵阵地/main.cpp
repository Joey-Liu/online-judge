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

int N, M;
string str[110];
int dp[110][1 << 11][1 << 11];


bool check_two(int x, int y) {
	return !(x & y);
}

bool check_one(int x) {
	int a = x & (x >> 1);
	int b = x & (x >> 2);
	return !(a || b);
}

bool calc(int x) {
	int res = 0;
	for (int i = 0; i < 30; i++) {
		if (x & (1 << i)) {
			res++;
		}
	}
	return res;
}


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> str[i];
	}

	int maxi_state = (1 << M);
	for (int k = 0; k < maxi_state; k++) {
		for (int j = 0; j < maxi_state; j++) {
			if (check_one(k)) {
				dp[0][j][k] = calc(k);
			}
		}
	}

	for (int k = 0; k < maxi_state; k++) {
		if (!check_one(k)) {
			continue;
		}

		int tmp_num = calc(k);

		for (int j = 0; j < maxi_state; j++) {
			if (!check_one(j)) {
				continue;
			}
			
			if (!check_two(k, j)) {
				continue;
			}

			dp[1][j][k] = max(dp[1][j][k], tmp_num + dp[0][0][j]);
		}
	}


	for (int i = 2; i < M; i++) {
		for (int k = 0; k < maxi_state; k++) {
			if (!check_one(k)) {
				continue;
			}

			int tmp_num = calc(k);

			for (int j = 0; j < maxi_state; j++) {
				if (!check_one(j)) {
					continue;
				}

				if (!check_two(k, j)) {
					continue;
				}
				
				dp[i][j][k] = max(dp[i][j][k], tmp_num)
			
			}

		}//for int k
	}//for int i



	return 0;
}