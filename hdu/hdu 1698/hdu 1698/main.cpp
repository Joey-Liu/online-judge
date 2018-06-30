#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <algorithm>

using namespace std;

const int maxn = 100000 + 20;
struct Node {
	int x;
	int delay;

	Node() {
		x = 0;
		delay = 0;
	}

};

Node seg_tree[maxn << 2];
int N, Q;

void build_tree(int root, int lp, int rp) {

	if (lp == rp) {
		seg_tree[root].x = 1;
		seg_tree[root].delay = 0;
		return;
	}

	int lson = root << 1, rson = (root << 1) + 1;
	int mid = (lp + rp) >> 1;
	build_tree(lson, lp, mid);
	build_tree(rson, mid + 1, rp);
	seg_tree[root].x = seg_tree[lson].x + seg_tree[rson].x;
	seg_tree[root].delay = 0;
}


void push_down(int root, int lp, int rp) {
	if (seg_tree[root].delay != 0) {
		int lson = root << 1, rson = (root << 1) | 1;
		int mid = (lp + rp) >> 1;
		seg_tree[lson].x = (mid - lp + 1)  *seg_tree[root].delay;
		seg_tree[rson].x = (rp - mid) * seg_tree[root].delay;
		seg_tree[lson].delay = seg_tree[root].delay;
		seg_tree[rson].delay = seg_tree[root].delay;
	}
	seg_tree[root].delay = 0;
}

void update(int root, int lp, int rp, int quer_lp, int quer_rp, int val) {
	if (lp > quer_rp || rp < quer_lp)
		return;
	if (quer_lp <= lp && rp <= quer_rp) {
		seg_tree[root].x = (rp - lp + 1) * val;
		seg_tree[root].delay = val;
		return;
	}

	int lson = root << 1, rson = (root << 1) | 1;
	int mid = (lp + rp) >> 1;
	
	push_down(root, lp, rp);

	update(lson, lp, mid, quer_lp, quer_rp, val);
	update(rson, mid + 1, rp, quer_lp, quer_rp, val);
	seg_tree[root].x = seg_tree[lson].x + seg_tree[rson].x;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T, x, y, z;
	cin >> T;
	for (int casenum = 1; casenum <= T; casenum++) {
		cin >> N;
		build_tree(1, 1, N);
		cin >> Q;
		for (int i = 0; i < Q; i++) {
			cin >> x >> y >> z;
			update(1, 1, N, x, y, z);
 		}
		cout << "Case " << casenum << ": The total value of the hook is " <<seg_tree[1].x << "." << endl;
	}
	return 0;
}