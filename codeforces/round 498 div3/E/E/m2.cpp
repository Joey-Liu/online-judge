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

const int maxn = 200000 + 50;
vector<int> neigh[maxn];
int N, Q, step;

int seq[maxn], son_len[maxn], id_step[maxn];


void dfs(int cur) {
	int tmp = step;
	seq[step] = cur;
	id_step[cur] = step;

	for (int i = 0; i < neigh[cur].size(); i++) {
		int to = neigh[cur][i];
		step++;
		dfs(to);
	}

	son_len[tmp] = step - tmp + 1;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	cin >> N >> Q;
	for (int i = 2; i <= N; i++) {
		int par;
		cin >> par;
		neigh[par].push_back(i);
	}
	

	dfs(1);
	for (int i = 0; i < Q; i++) {
		int u, k;
		cin >> u >> k;
		
		int s = id_step[u];
		if (son_len[s] < k)
			cout << -1 << endl;
		else {
			int p = s + k - 1;
			cout << seq[p] << endl;
		}
	}

	return 0;
}