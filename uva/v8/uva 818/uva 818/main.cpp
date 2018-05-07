#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <algorithm>

using namespace std;

const int maxn = 15 + 20;
const int INF = 0x3f3f3f3f;

int visited[maxn], tab[maxn][maxn],  t_tab[maxn][maxn], N;

bool has_two() {
	for (int i = 0; i < N; i++) {
		int nu = 0;
		for (int j = 0; j < N; j++) {
			if (t_tab[i][j])
				nu++;
		}
		if (nu > 2)
			return true;;
	}
	return false;
}

bool dfs(int cur, int par) {
	visited[cur] = -1;
	for (int i = 0; i < N; i++) {
		if (i == par)
			continue;
		if (t_tab[cur][i] && -1 == visited[i]) {
			return false;
		}
		else if (t_tab[cur][i] && 0 == visited[i]) {
			if (!dfs(i, cur))
				return false;
		}
	}
	visited[cur] = 1;
	return true;
}


bool has_circle() {
	memset(visited, 0, sizeof(visited));

	for (int i = 0; i < N; i++) {
		if (!visited[i] && !dfs(i, -1))
			return true;
	}
	return false;
}

bool judge(int state) {//state 中 每一位为1 表示这个环被打开
	memcpy(t_tab, tab, sizeof(tab));

	for (int i = 0; i < N; i++) {
		if (state & (1 << i)) {
			for (int j = 0; j < N; j++) {
				t_tab[i][j] = 0;
				t_tab[j][i] = 0;
			}
		}//if
	}//for int i
	
	if (has_two() || has_circle())
		return false;
	return true;
}

int count_s(int state) {
	int res = 0;
	while (state) {
		if (1 & state)
			res++;
		state >>= 1;
	}
	return res;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int kase = 0;
	while (cin >> N && N) {
		int a, b, res = INF;;
		memset(tab, 0, sizeof(tab));
		while (cin >> a >> b && a > 0) {
			--a; --b;
			tab[a][b] = tab[b][a] = 1;
		}

		int ts = 1 << N;
		for (int s = 0; s < ts; s++) {
			if (judge(s)) {
				int linked = 0;
				memset(visited, 0, sizeof(visited));
				for (int i = 0; i < N; i++) {
					if (!visited[i] && !((1 << i) & s)) {
						linked++;
						dfs(i, -1);
					}
				}

				int cnt = count_s(s);
				if (linked - 1 <= cnt) {
					res = min(res, cnt);
				}
			}// if
		}//for int i
	
		cout << "Set " << ++kase << ": Minimum links to open is " << res << endl;
	}//while cin>>N
	return 0;
}