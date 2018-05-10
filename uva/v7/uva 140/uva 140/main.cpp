#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <memory.h>
#include <algorithm>

using namespace std;
const int maxn = 30;
const int INF = 0x3f3f3f3f;
int tab[maxn][maxn];
int bandwidth, N;
int res[maxn], tm[maxn];
bool visited[maxn];
bool exist[maxn];

void dfs(int cur_band, int cur) {
	if (cur == N) {
		if (cur_band < bandwidth) {
			bandwidth = cur_band;
			for (int i = 0; i < N; i++)
				res[i] = tm[i];
		}
		return;
	}

	for (int i = 0; i < maxn; i++) {
		if (!visited[i] && exist[i]) {
			tm[cur] = i;
			visited[i] = true;
			int t_ba_width = cur_band;
			for (int j = 0; j < cur; j++) {
				int a = tm[j];
				if (tab[a][i] && cur - j > t_ba_width) {
					t_ba_width = cur - j;
				}
			}
			if (t_ba_width >= bandwidth) {
				visited[i] = false;
				continue;
			}
			dfs(t_ba_width, cur + 1);
			visited[i] = false;
		}//if
	}//for int i
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string str;
	while (cin >> str) {
		if ('#' == str[0])
			break;
		int ind = 0;
		memset(tab, 0, sizeof(tab));
		memset(visited, 0, sizeof(visited));
		memset(exist, false, sizeof(exist));

		while (ind < str.size()) {
			int a = str[ind] - 'A';
			exist[a] = true;
			ind += 2;
			while (ind < str.size() && str[ind] != ';') {
				int b = str[ind] - 'A';
				exist[b] = true;
				tab[a][b] = 1;
				tab[b][a] = 1;
				ind++;
			}
			ind++;
		}//while ind
		N = 0;
		bandwidth = INF;
		for (int i = 0; i < maxn; i++) {
			if (exist[i])
				N++;
		}
		dfs(0, 0);
		cout << char(res[0] + 'A');
		for (int i = 1; i < N; i++) {
			cout << " " << char(res[i] + 'A');
		}
		cout << " -> ";
		cout << bandwidth << endl;
	}//while cin
	return 0;
}