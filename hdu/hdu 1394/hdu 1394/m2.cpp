#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;

const int maxn = 5000 + 20;
int seg_tree[maxn << 2], N, A[maxn];

void update(int root, int lp, int rp, int target) {
	if (lp == rp) {
		seg_tree[root]++;
		return;
	}

	int mid = (lp + rp) >> 1;
	int lson = root << 1, rson = (root << 1) + 1;
	if (target <= mid) {
		update(lson, lp, mid, target);
	}
	else {
		update(rson, mid + 1, rp, target);
	}

	seg_tree[root] = seg_tree[lson] + seg_tree[rson];
}

int query(int root, int lp, int rp, int quer_lp, int quer_rp) {
	if (quer_lp > rp || quer_rp < lp)
		return 0;
	if (quer_lp <= lp && rp <= quer_rp)
		return seg_tree[root];

	int lson = root << 1, rson = (root << 1) + 1;
	int mid = (lp + rp) / 2;
	int s1 = query(lson, lp, mid, quer_lp, quer_rp);
	int s2 = query(rson, mid + 1, rp, quer_lp, quer_rp);

	return s1 + s2;
}


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (cin >> N) {
		memset(seg_tree, 0, sizeof(seg_tree)); // no need to build tree
		int ori = 0;
		for (int i = 0; i < N; i++) {
			cin >> A[i];
			update(1, 0, N - 1, A[i]);
			ori += query(1, 0, N - 1, A[i] + 1, N);
		}

		int ans = ori, t = ori;
		for (int i = 0; i < N; i++) {
			t = t - A[i] + N - 1 - A[i];
			ans = min(t, ans);
		}
		cout << ans << endl;
	}//while
}