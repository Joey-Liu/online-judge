#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <queue>
#include <map>

using namespace std;

typedef pair<int, int> PII;
const int maxn = 50 + 30;

string tab[maxn];

int N, M, sr, sc, K;
int dr[maxn], dc[maxn];
int step[maxn][maxn];


bool in_tab(int i, int j) {
	if (i < 0 || i >= N || j < 0 || j >= M)
		return false;
	return true;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (cin >> N >> M) {
		for (int i = 0; i < N; i++) {
			cin >> tab[i];
		}

		cin >> sr >> sc;
		cin >> K;
		for (int i = 0; i < K; i++) {
			cin >> dr[i] >> dc[i];
		}
		memset(step, -1, sizeof(step));
		step[sr][sc] = 0;

		queue<PII > que;
		que.push(make_pair(sr, sc));
		while (!que.empty()) {
			PII pos = que.front();
			que.pop();

			for (int i = 0; i < K; i++) {
				int nr = pos.first + dr[i];
				int nc = pos.second + dc[i];

				if (in_tab(nr, nc) && tab[nr][nc] != 'X' && step[nr][nc] == -1) {
					step[nr][nc] = step[pos.first][pos.second] + 1;
					que.push(make_pair(nr, nc));
				}
			}//for int i
		}		

		bool flag = true;
		int ans = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (tab[i][j] == 'X')
					continue;
				if (step[i][j] == -1) {
					flag = false;
					break;
				}
				ans = max(ans, step[i][j]);
			}
			if (!flag) {
				break;
			}
		}

		if (!flag)
			cout << -1 << endl;
		else
			cout << ans << endl;
	}//while cin
	return 0;
}