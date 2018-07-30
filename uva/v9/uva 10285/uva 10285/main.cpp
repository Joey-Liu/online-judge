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
const int maxn = 100 + 20;

int matrix[maxn][maxn], row, col;
int dp[maxn][maxn];

string name;

int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };

bool in_map(int r, int c) {
	if (r < 0 || r >= row || c < 0 || c >= col)
		return false;
	return true;
}

int work(int r, int c) {
	if (dp[r][c] != -1)
		return dp[r][c];
	dp[r][c] = 1;
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (in_map(nr, nc) && matrix[nr][nc] < matrix[r][c]) {
			dp[r][c] = max(dp[r][c], 1 + work(nr, nc));
		}
	}
	return dp[r][c];
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int kasenum = 0;
	cin >> kasenum;
	while (kasenum--) {
		cin >> name >> row >> col;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				cin >> matrix[i][j];
			}
		}

		int ans = 1;
		memset(dp, -1, sizeof(dp));
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (dp[i][j] == -1) {
					ans = max(ans, work(i, j));
				}
			}
		}
		cout << name << ": " << ans << endl;
	}
	return 0;
}