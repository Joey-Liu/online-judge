#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;
const int maxn = 50;
int row, col;

int tab[maxn][maxn];
int id[maxn][maxn];
int res[maxn], bagua_num;
bool visited[maxn][maxn];


int dr[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dc[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

bool in_tab(int r, int c) {
	if (r < 0 || r >= row || c < 0 || c >= col)
		return false;
	return true;
}


void dfs(int r, int c, int k) {
	for (int i = 0; i < 8; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (in_tab(nr, nc) && !visited[nr][nc] && tab[nr][nc]) {
			visited[nr][nc] = true;
			id[nr][nc] = k;
			dfs(nr, nc, k);
		}
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> tab[i][j];
		}
	}


	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (!visited[i][j] && tab[i][j]) {
				visited[i][j] = true;
				id[i][j] = ++bagua_num;
				dfs(i, j, bagua_num);
			}
		}
	}

	memset(res, 0, sizeof(res));
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			int n = id[i][j];
			if (n) {
				res[n] += tab[i][j];
			}
		}
	}
	
	sort(res + 1, res + bagua_num + 1);
	cout << res[bagua_num] << endl;
	cout << res[1] << endl;

	return 0;
}