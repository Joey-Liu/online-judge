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

typedef long long LL;

const int maxn = 100000 + 50;

struct Node {
	LL val;
	LL delay;

	Node() {
		val = 0;
		delay = 0;
	}
};

Node nodes[maxn << 2];
int N, Q;


LL build_tree(int root, int lp, int rp) {
	if (lp == rp) {
		cin >> nodes[root].val;
		return nodes[root].val;
	}

	int mid = lp + (rp - lp) / 2;
	int lson = root << 1, rson = (root << 1) | 1;
	LL le_sum = build_tree(lson, lp, mid);
	LL ri_sum = build_tree(rson, mid + 1, rp);
	nodes[root].val = nodes[lson].val + nodes[rson].val;
	return nodes[root].val;
}

void push_down(int root, int lp, int rp) {
	if (nodes[root].delay != 0) {
		LL delay = nodes[root].delay;
		int mid = lp + (rp - lp) / 2;
		int lson = root << 1, rson = (root << 1) | 1;
		nodes[lson].val += (mid - lp + 1) * delay;
		nodes[rson].val += (rp - mid) * delay;
		nodes[lson].delay += delay;
		nodes[rson].delay += delay;
		nodes[root].delay = 0;
	}
}

LL update(int root, int lp, int rp, int up_lp, int up_rp, int c) {
	if (up_lp > rp || up_rp < lp)
		return nodes[root].val;
	if (up_lp <= lp && rp <= up_rp) {
		nodes[root].val += c * (rp - lp + 1);
		nodes[root].delay += c;
		return nodes[root].val;
	}

	int mid = lp + (rp - lp) / 2;
	int lson = root << 1, rson = (root << 1) + 1;
	push_down(root, lp, rp);
	LL le_sum = update(lson, lp, mid, up_lp, up_rp, c);
	LL ri_sum = update(rson, mid + 1, rp, up_lp, up_rp, c);

	return nodes[root].val = le_sum + ri_sum;
}

LL query(int root, int lp, int rp, int q_lp, int q_rp) {
	if (q_lp > rp || q_rp < lp)
		return 0;
	if (q_lp <= lp && rp <= q_rp) {
		return nodes[root].val;
	}

	int mid = lp + (rp - lp) / 2;
	int lson = root << 1, rson = (root << 1) | 1;
	push_down(root, lp, rp);

	LL le_sum = query(lson, lp, mid, q_lp, q_rp);
	LL ri_sum = query(rson, mid + 1, rp, q_lp, q_rp);
	return le_sum + ri_sum;
}


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> Q;
	build_tree(1, 1, N);
	for (int i = 0; i < Q; i++) {
		char ch;
		int q_lp, q_rp;
		LL res;
		cin >> ch >> q_lp >> q_rp;
		switch (ch) {
		case 'Q':
			res = query(1, 1, N, q_lp, q_rp);
			cout << res << endl;
			break;
		case 'C':
			int c;
			cin >> c;
			update(1, 1, N, q_lp, q_rp, c);
			break;
		}
	}//for int i

	return 0;
}