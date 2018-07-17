#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <algorithm>

using namespace std;

const int maxn = 222222 + 10;
int seg_tree[maxn << 2];
int H, W, N;

int build_tree(int root, int lp, int rp) {
	if (lp == rp) {
		return seg_tree[root] = W;
	}

	int lson = root << 1, rson = (root << 1) + 1;
	int mid = (lp + rp) >> 1;
	
	int m1 = build_tree(lson, lp, mid);
	int m2 = build_tree(rson, mid + 1, rp);
	return seg_tree[root] = max(m1, m2);
}


int query(int root, int lp, int rp, int nu) {
	if (seg_tree[root] < nu)
		return -1;

	if (lp == rp && seg_tree[root] >= nu) {
		return lp;
	}

	int lson = root << 1, rson = (root << 1) + 1;
	int mid = (lp + rp) >> 1;
	if (seg_tree[lson] >= nu) {
		return query(lson, lp, mid, nu);
	}
	else {
		return query(rson, mid + 1, rp, nu);
	}
}

void minus_val(int root, int lp, int rp, int target, int nu) {
	if (lp == rp) {
		seg_tree[root] -= nu;
		return;
	}

	int lson = root << 1, rson = (root << 1) | 1;
	int mid = (lp + rp) >> 1;

	if (target <= mid) {
		minus_val(lson, lp, mid, target, nu);
	}
	else {
		minus_val(rson, mid + 1, rp, target, nu);
	}
	seg_tree[root] = max(seg_tree[lson], seg_tree[rson]);
}


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	while (cin >> H >> W >> N) {
		H = min(H, N);
		build_tree(1, 1, H);
		for (int i = 0; i < N; i++) {
			int wi;
			cin >> wi;
			int ind = query(1, 1, H, wi);
			cout << ind << endl;
			if (ind > 0) {
				minus_val(1, 1, H, ind, wi);
			}
		}
	}//while 
	return 0;
}