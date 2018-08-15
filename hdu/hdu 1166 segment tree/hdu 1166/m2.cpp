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

const int maxn = 50000 + 20;

int num[maxn], seg_tree[maxn << 2], N;

void build_tree(int root, int lp, int rp) {
	if (lp == rp) {
		seg_tree[root] = num[lp];
		return;
	}

	int lson = root << 1, rson = (root << 1) | 1;
	int mid = lp + (rp - lp) / 2;
	build_tree(lson, lp, mid);
	build_tree(rson, mid + 1, rp);

	seg_tree[root] = seg_tree[lson] + seg_tree[rson];
}

int query(int root, int lp, int rp, int q_lp, int q_rp) {
	if (rp < q_lp || lp > q_rp) {
		return 0;
	}

	if (lp >= q_lp && rp <= q_rp) {
		return seg_tree[root];
	}

	int mid = lp + (rp - lp) / 2;
	int lson = root << 1, rson = (root << 1) | 1;

	int left_sum = query(lson, lp, mid, q_lp, q_rp);
	int right_sum = query(rson, mid + 1, rp, q_lp, q_rp);
	return left_sum + right_sum;
}

void add(int root, int lp, int rp, int pos, int val) {
	if (pos < lp || pos > rp) {
		return;
	}
	if (lp == rp) {
		seg_tree[root] += val;
		return;
	}

	int mid = lp + (rp - lp) / 2;
	int lson = root << 1;
	int rson = (root << 1) | 1;
	if (pos <= mid) {
		add(lson, lp, mid, pos, val);
	}
	else {
		add(rson, mid + 1, rp, pos, val);
	}

	seg_tree[root] = seg_tree[lson] + seg_tree[rson];
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T = 0;
	cin >> T;
	for (int kasenum = 0; kasenum < T; kasenum++) {
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> num[i];
		}
		
		build_tree(1, 1, N);
		string str;
		cout << "Case " << kasenum + 1 << ":" << endl;
		while (cin >> str) {
			if (str[0] == 'E')
				break;

			int a, b;
			cin >> a >> b;
			if (str[0] == 'Q') {
				int res = query(1, 1, N, a, b);
				cout << res << endl;
			}
			else if (str[0] == 'A') {
				add(1, 1, N, a, b);
			}
			else {
				b = -b;
				add(1, 1, N, a, b);
			}
		}

	}//for int i

	return 0;
}