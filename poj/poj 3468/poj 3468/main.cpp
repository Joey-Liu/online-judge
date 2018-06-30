#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>


using namespace std;
const int maxn = 100000 + 20;
typedef long long LL;

struct Node {
	LL x;
	LL add_delay;

	Node() {
		x = 0;
		add_delay = 0;
	}
};

Node seg_tree[maxn << 2];

void build_tree(LL root, LL lp, LL rp) {
	if (lp == rp) {
		cin >> seg_tree[root].x;
		return;
	}

	LL lson = root << 1, rson = (root << 1) | 1;
	LL mid = (lp + rp) >> 1;
	build_tree(lson, lp, mid);
	build_tree(rson, mid + 1, rp);
	seg_tree[root].x = seg_tree[lson].x + seg_tree[rson].x;
}

void push_down(LL root, LL lp, LL rp) {
	if (seg_tree[root].add_delay != 0) {
		LL lson = root << 1, rson = (root << 1) | 1;
		LL mid = (lp + rp) >> 1;
		seg_tree[lson].x += seg_tree[root].add_delay * (mid - lp + 1);
		seg_tree[rson].x += seg_tree[root].add_delay * (rp - mid);
		seg_tree[lson].add_delay += seg_tree[root].add_delay;
		seg_tree[rson].add_delay += seg_tree[root].add_delay;
	}
	seg_tree[root].add_delay = 0;
}

void update(LL root, LL lp, LL rp, LL quer_lp, LL quer_rp, LL val) {
	if (lp > quer_rp || rp < quer_lp)
		return;
	if (quer_lp <= lp && rp <= quer_rp) {
		seg_tree[root].x += val * (rp - lp + 1);
		seg_tree[root].add_delay += val;
		return;
	}

	LL lson = root << 1, rson = (root << 1) | 1;
	LL mid = (lp + rp) >> 1;

	push_down(root, lp, rp);
	update(lson, lp, mid, quer_lp, quer_rp, val);
	update(rson, mid + 1, rp, quer_lp, quer_rp, val);
	seg_tree[root].x = seg_tree[lson].x + seg_tree[rson].x;
}


LL query(LL root, LL lp, LL rp, LL quer_lp, LL quer_rp) {
	if (quer_lp > rp || quer_rp < lp)
		return 0;

	if (quer_lp <= lp && rp <= quer_rp) {
		return seg_tree[root].x;
	}

	LL lson = root << 1, rson = (root << 1) | 1;
	LL mid = (lp + rp) >> 1;
	push_down(root, lp, rp);
	
	return query(lson, lp, mid, quer_lp, quer_rp) + query(rson, mid + 1, rp, quer_lp, quer_rp);
}

LL N, Q, a, b, c;
char ch;

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> Q;
	build_tree(1, 1, N);
	LL ans;
	for (LL i = 0; i < Q; i++) {
		cin >> ch;
		switch (ch)
		{
		case 'Q':
			cin >> a >> b;
			ans = query(1, 1, N, a, b);
			cout << ans << endl;
			break;
		case 'C':
			cin >> a >> b >> c;
			update(1, 1, N, a, b, c);
			break;
		}
	}
	return 0;
}