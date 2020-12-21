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

const int maxn = 1 << 13;
int dp[maxn][20];
int N;
int adj[20][20], dis[20][20];

int work(int state, int x) {
	if (dp[state][x] != -1) {
		return dp[state][x];
 	}

	dp[state][x] = 0x3f3f3f3f;
	for (int i = 0; i < N; i++) {
		if (i == x) {
			continue;
		}

		if (state & (1 << i)) {
			dp[state][x] = min(dp[state][x], dis[i][x] + work(state ^ (1 << x), i));
		}//if
	}//for int i

	return dp[state][x];
}


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	while (cin >> N) {
		if (!N) {
			break;
		}

		++N;
		memset(adj, 0, sizeof(adj));
		memset(dis, 0x3f3f3f3f, sizeof(dis));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> adj[i][j];
				dis[i][j] = adj[i][j];
			}
		}

		for (int k = 0; k < N; k++) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
				}
			}//for int i
		}//for int k
		
		memset(dp, -1, sizeof(dp));
		//dp[1][0] = 0;
		//dp[0][0] = 0;
		for (int i = 0; i < N; i++) {
			dp[1 << i][i] = dis[0][i];
		}


		int max_state = (1 << N) - 1;
		int ans = work(max_state, 1) + dis[1][0];
		for (int i = 1; i < N; i++) {
			int tmp = work(max_state, i) + dis[i][0];
			ans = min(ans, tmp);
		}
		cout << ans << endl;



	}//while


	return 0;
}