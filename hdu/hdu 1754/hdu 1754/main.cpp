#include <iostream>
#include <algorithm>
#include <limits.h>
#include <memory.h>

using namespace std;

const int maxn = 200000 + 10;
int seg_tree[maxn << 2];

int N, M;

int build_tree(int root, int lp, int rp) {
	if (lp == rp) {
		cin >> seg_tree[root];
		return seg_tree[root];
	}

	int mid = lp + (rp - lp) / 2;
	int m1 = build_tree(root << 1, lp, mid);
	int m2 = build_tree((root << 1) + 1, mid + 1, rp);
	return seg_tree[root] = max(m1, m2);
}

int query(int root, int lp, int rp, int quer_lp, int quer_rp) {
	if (lp > quer_rp || rp < quer_lp) {
		return INT_MIN;
	}
	if (lp >= quer_lp && rp <= quer_rp) {
		return seg_tree[root];
	}

	int mid = lp + (rp - lp) / 2;
	int m1 = query(root << 1, lp, mid, quer_lp, quer_rp);
	int m2 = query((root << 1) + 1, mid + 1, rp, quer_lp, quer_rp);
	return max(m1, m2);
}

void update(int root, int lp, int rp, int target, int nu) {
	if (lp == rp) {
		seg_tree[root] = nu;
		return;
	}

	int mid = lp + (rp - lp) / 2;
	int lson = root << 1, rson = (root << 1) + 1;
	if (target <= mid) {
		update(lson, lp, mid, target, nu);
	}
	else
		update(rson, mid + 1, rp, target, nu);

	seg_tree[root] = max(seg_tree[lson], seg_tree[rson]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	while (cin >> N >> M) {
		memset(seg_tree, 0, sizeof(seg_tree));
		char c;
		int a, b;
		build_tree(1, 1, N);
		for (int i = 0; i < M; i++) {
			cin >> c >> a >> b;
			if (c == 'Q') {
				int ans = query(1, 1, N, a, b);
				cout << ans << endl;
			}
			else {
				update(1, 1, N, a, b);
			}
		}//for int i
	}//while cin
	return 0;
}