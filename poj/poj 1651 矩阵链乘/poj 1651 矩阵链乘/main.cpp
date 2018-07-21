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

const int maxn = 100 + 50;
int N;
int nums[maxn], dp[maxn][maxn];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> nums[i];

	for (int len = 2; len <= N; len++) {
		for (int i = 0; i <= N - len; i++) {
			int j = i + len - 1;
			int tmp_min = 0x3f3f3f3f;
			for (int k = i; k < j; k++) {
				int tmp = dp[i][k] + dp[k + 1][j] + nums[i] * nums[k + 1] * nums[j + 1];
				tmp_min = min(tmp_min, tmp);
			}
			dp[i][j] = tmp_min;
		}//for int i
	}

	cout << dp[0][N - 2] << endl;

	return 0;
}