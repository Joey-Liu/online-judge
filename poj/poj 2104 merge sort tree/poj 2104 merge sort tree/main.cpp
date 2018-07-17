#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;
const int maxn = 100000 + 50;
const int depth = 25;

int merge_tree[depth][maxn];
int num[maxn];
int N, M;


void build_tree(int deep, int lp, int rp) {
	if (lp == rp) {
		merge_tree[deep][lp] = num[lp];
		return;
	}

	int mid = (lp + rp) >> 1;
	build_tree(deep + 1, lp, mid);
	build_tree(deep + 1, mid + 1, rp);

	int i = lp, j = mid + 1, ind = lp;
	while (i <= mid || j <= rp) {
		if (i > mid || (j <= rp && merge_tree[deep + 1][i] > merge_tree[deep + 1][j]))
			merge_tree[deep][ind++] = merge_tree[deep + 1][j++];
		else
			merge_tree[deep][ind++] = merge_tree[deep + 1][i++];
	}
	
}

int query(int layer, int lp, int rp, int q_lp, int q_rp, int val) {
	if (lp > q_rp || rp < q_lp)
		return 0;
	if (q_lp <= lp && rp <= q_rp)
		return lower_bound(merge_tree[layer] + lp, merge_tree[layer] + rp + 1, val) - (merge_tree[layer] + lp);

	int mid = (lp + rp) >> 1;
	return query(layer + 1, lp, mid, q_lp, q_rp, val) + query(layer + 1, mid + 1, rp, q_lp, q_rp, val);
}


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%d", &num[i]);
	build_tree(0, 0, N - 1);
	for (int i = 0; i < M; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		a--; b--; c--;
		int lp = 0, rp = N;
		while (lp < rp) {
			int mid = (lp + rp) >> 1;
			int val = merge_tree[0][mid];
			int cnt = query(0, 0, N - 1, a, b, val);
			if (cnt <= c)
				lp = mid + 1;
			else
				rp = mid;
		}
		printf("%d\n", merge_tree[0][rp - 1]);
	}//for int i
	return 0;
}