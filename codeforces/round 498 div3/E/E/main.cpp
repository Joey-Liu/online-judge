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
const int inf = 0x7fffffff;
int seg_tree[4 * maxn];

int layer[maxn];
int step[maxn], N, Q, step_cnt = 0;
int dfs_seq[maxn];

vector<int> edge[maxn];


void dfs(int cur, int la) {
	step[cur] = step_cnt;
	dfs_seq[step_cnt] = cur;
	layer[step_cnt++] = la;

	for (int i = 0; i < edge[cur].size(); i++) {
		dfs(edge[cur][i], la + 1);
	}
}

int build_tree(int root, int lp, int rp) {
	if (lp == rp) {
		return seg_tree[root] = layer[lp];
	}

	int mid = (lp + rp) >> 1;
	int le_min = build_tree(root << 1, lp, mid);
	int ri_min = build_tree((root << 1) + 1, mid + 1, rp);

	seg_tree[root] = min(le_min, ri_min);
}

int query(int root, int lp, int rp, int q_lp, int q_rp) {
	if (q_lp > rp || q_rp < lp)
		return inf;
	if (q_lp <= lp && rp <= q_rp)
		return seg_tree[root];

	int mid = (lp + rp) >> 1;
	int a = query(root << 1, lp, mid, q_lp, q_rp);
	int b = query((root << 1) + 1, mid + 1, rp, q_lp, q_rp);

	return min(a, b);
}


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int N;
	cin >> N >> Q;

	for (int i = 2; i <= N; i++) {
		int par;
		cin >> par;
		edge[par].push_back(i);
	}
	
	dfs(1, 0);
	build_tree(1, 0, N - 1);


	for (int i = 0; i < Q; i++) {
		int u, k;
		cin >> u >> k;

		int st = step[u];
		int ed = st + k - 1;
		if (ed >= N)
			cout << -1 << endl;
		else if (st == ed) {
			cout << dfs_seq[ed] << endl;
		}
		else {
			int tmp = query(1, 0, N - 1, st + 1, ed);
			if (tmp <= layer[step[u]])
				cout << -1 << endl;
			else {
				cout << dfs_seq[ed] << endl;
			}
		}

	}

	return 0;
}