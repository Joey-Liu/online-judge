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
#include <math.h>
#include <functional>
#include <limits.h>

using namespace std;

typedef long long LL;

const int maxn = 100000 + 20;
struct Node {
	LL x;
	LL delay;
	Node() {
		x = 0;
		delay = 0;
	}

};

Node seg_tree[maxn << 2];

void build_tree(int root, int lp, int rp) {

	if (lp == rp) {
		seg_tree[root].x = 0;
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
		seg_tree[lson].x += (mid - lp + 1) * seg_tree[root].delay;
		seg_tree[rson].x += (rp - mid) * seg_tree[root].delay;
		seg_tree[lson].delay += seg_tree[root].delay;
		seg_tree[rson].delay += seg_tree[root].delay;
	}
	seg_tree[root].delay = 0;
}

void update(int root, int lp, int rp, int quer_lp, int quer_rp, int val) {
	if (lp > quer_rp || rp < quer_lp)
		return;
	if (quer_lp <= lp && rp <= quer_rp) {
		seg_tree[root].x += (rp - lp + 1) * val;
		seg_tree[root].delay += val;
		return;
	}

	int lson = root << 1, rson = (root << 1) | 1;
	int mid = (lp + rp) >> 1;

	push_down(root, lp, rp);

	update(lson, lp, mid, quer_lp, quer_rp, val);
	update(rson, mid + 1, rp, quer_lp, quer_rp, val);
	seg_tree[root].x = seg_tree[lson].x + seg_tree[rson].x;
}


int query(int root, int lp, int rp, int quer_lp, int quer_rp) {
	if (lp > quer_rp || rp < quer_lp)
		return 0;
	if (quer_lp <= lp && rp <= quer_rp) {
		return seg_tree[root].x;
	}
	int lson = root << 1, rson = (root << 1) | 1;
	int mid = (lp + rp) >> 1;
	push_down(root, lp, rp);
	return query(lson, lp, mid, quer_lp, quer_rp) + query(rson, mid + 1, rp, quer_lp, quer_rp);
}

class Solution {
public:
	vector<int> corpFlightBookings(vector<vector<int>>& bookings, int N) {
		int tmp = bookings.size();
		memset(seg_tree, 0, sizeof(seg_tree));
		build_tree(1, 1, N);
		for (int t = 0; t < tmp; t++) {
			int i = bookings[t][0], j = bookings[t][1], k = bookings[t][2];
			update(1, 1, N, i, j, k);
		}
		
		vector<int> res(N, 0);
		for (int i = 0; i < N; i++) {
			res[i] = query(1, 1, N, i + 1, i + 1);
		}
		return res;

	}
};

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	vector<vector<int>> bookings(2, vector<int> (3, 0));
	
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> bookings[i][j];
		}
	}

	Solution sol;
	sol.corpFlightBookings(bookings, 2);
	return 0;

}