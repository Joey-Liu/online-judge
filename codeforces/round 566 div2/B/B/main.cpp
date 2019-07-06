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

const int maxn = 500 + 10;

char pic[maxn][maxn];
bool visited[maxn][maxn];
int H, W;

int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };

bool in_pic(int r, int c) {
	if (r < 0 || r >= H || c < 0 || c >= W)
		return false;
	return true;
}

bool check_center(int r, int c) {
	if (pic[r][c] == '.')
		return false;
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i], nc = c + dc[i];
		if (!in_pic(nr, nc) || pic[nr][nc] == '.')
			return false;
	}
	return true;
}

void cross(int r, int c) {
	visited[r][c] = true;
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i], nc = c + dc[i];
		while (in_pic(nr, nc) && pic[nr][nc] == '*') {
			visited[nr][nc] = true;
			nr = nr + dr[i];
			nc = nc + dc[i];
		}
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> H >> W;
	for (int i = 0; i < H; i++) {
		cin >> pic[i];
	}
	memset(visited, false, sizeof(visited));

	bool center = false;
	int c_row, c_col;
	for (int i = 1; i < H; i++) {
		for (int j = 1; j < W; j++) {
			bool is_center = check_center(i, j);
			if (is_center && !center) {
				c_row = i; c_col = j;
				center = true;
				cross(i, j);
			}
			else if (is_center && center) {
				cout << "NO" << endl;
				return 0;
			}
		}
	}

	if (!center) {
		cout << "NO" << endl;
	}
	else {

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (pic[i][j] == '*' && !visited[i][j]) {
					cout << "NO" << endl;
					return 0;
				}
			}
		}
		cout << "YES" << endl;
	}

	return 0;
}