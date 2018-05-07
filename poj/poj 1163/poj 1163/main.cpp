#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

const int maxn = 100 + 50;
int nums[maxn][maxn];
int dp[maxn][maxn], N;

int work(int r, int c) 
{
	if (dp[r][c] != -1)
		return dp[r][c];
	else {
		return dp[r][c] = (r == N - 1 ? nums[r][c] : nums[r][c] + max(work(r + 1, c), work(r + 1, c + 1)));
	}
}

int main()
{
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> nums[i][j];
		}
	}
	int ans = work(0, 0);
	cout << ans << endl;
	return 0;
}