#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>


using namespace std;
const int maxn = 100000 + 50;
const int max_depth = 22;

int merge_tree[max_depth][maxn];
int nums[maxn], N, M;

void build_tree(int depth, int lp, int rp) {
	if (lp == rp) {
		merge_tree[depth][lp] = nums[lp];
		return;
	}

	int mid = (lp + rp) >> 1;
	build_tree(depth + 1, lp, mid);
	build_tree(depth + 1, mid + 1, rp);

	int ind = lp, i = lp, j = mid + 1;
	while (i <= mid || j <= rp) {
		if (i > mid || (j <= rp && merge_tree[depth + 1][i] > merge_tree[depth + 1][j]))
			merge_tree[depth][ind++] = merge_tree[depth + 1][j++];
		else
			merge_tree[depth][ind++] = merge_tree[depth + 1][i++];
	}
}

int query(int depth, int lp, int rp, int q_lp, int q_rp, int val) {
	if (lp > q_rp || rp < q_lp)
		return 0;
	if (q_lp <= lp && rp <= q_rp)
		return lower_bound(&merge_tree[depth][lp], &merge_tree[depth][rp + 1], val) - (merge_tree[depth] + lp);

	int mid = (lp + rp) >> 1;
	return query(depth + 1, lp, mid, q_lp, q_rp, val) + query(depth + 1, mid + 1, rp, q_lp, q_rp, val);
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int kasenum;
	cin >> kasenum;
	while (kasenum--) {
		cin >> N >> M;
		for (int i = 0; i < N; i++)
			cin >> nums[i];
		build_tree(0, 0, N - 1);

		for (int i = 0; i < M; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			a--; b--; 

			int lp = 0, rp = N;
			while (lp < rp) {
				int mid = (lp + rp) >> 1;
				int val = merge_tree[0][mid];

				int cnt = query(0, 0, N - 1, a, b, val);
				if (cnt <= c - 1)
					lp = mid + 1;
				else
					rp = mid;
			}
			cout << merge_tree[0][rp - 1] << endl;
		}
	}//while kasenum

	return 0;
}