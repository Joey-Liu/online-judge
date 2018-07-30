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
const int maxn = 40 + 5;

int dp[maxn][maxn][maxn][maxn];
int candy[4][maxn];
int N;

int get_state_num(int state) {
	int cnt = 0;
	for (int i = 0; i < 31; i++) {
		if ((1 << i) & state)
			cnt++;
	}
	return cnt;
}

int work(int state, int num[]) {
	
	int & ans = dp[num[0]][num[1]][num[2]][num[3]];
	if (ans != -1)
		return ans;

	if (get_state_num(state) >= 5)
		return ans = 0;
	
	ans = 0;
	for (int i = 0; i < 4; i++) {
		if (num[i] >= N)
			continue;
		
		int t = candy[i][num[i]], inc = 0;
		num[i]++;
		if ((1 << t) & state)
			inc += 1;

		ans = max(ans, inc + work(state ^ (1 << t), num));
		num[i]--;
	}
	return ans;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);  cout.tie(0);

	while (cin >> N && N) {
		memset(dp, -1, sizeof(dp));
		for (int j = 0; j < N; j++) {
			for (int i = 0; i < 4; i++) {
				cin >> candy[i][j];
			}
		}

		int num[4] = { 0 };
		int ans = work(0, num);
		cout << ans << endl;
	}//while

	return 0;
}