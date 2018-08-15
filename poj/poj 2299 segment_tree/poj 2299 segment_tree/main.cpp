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

const int maxn = 500000 + 5;

typedef long long LL;

int seg_tree[maxn << 2], N, len;
int nums[maxn], sorted[maxn];

int get_id(int a) {
	int lp = 1, rp = len + 1;
	while (lp < rp) {
		int mid = lp + (rp - lp) / 2;
		if (sorted[mid] >= a) {
			rp = mid;
		}
		else {
			lp = mid + 1;
		}
	}//while
	return lp;
}

LL query(int root, int lp, int rp, int q_lp, int q_rp) {
	if (q_lp > q_rp)
		return 0;
	if (q_lp > rp || q_rp < lp)
		return 0;
	if (q_lp <= lp && rp <= q_rp)
		return seg_tree[root];

	int mid = lp + (rp - lp) / 2;
	int lson = root << 1, rson = (root << 1) | 1;
	LL a = query(lson, lp, mid, q_lp, q_rp);
	LL b = query(rson, mid + 1, rp, q_lp, q_rp);
	return a + b;
}

void update(int root, int lp, int rp, int pos) {
	if (lp == rp) {
		seg_tree[root]++;
		return;
	}

	int mid = lp + (rp - lp) / 2;
	int lson = root << 1, rson = (root << 1) | 1;
	if (pos <= mid) {
		update(lson, lp, mid, pos);
	}
	else {
		update(rson, mid + 1, rp, pos);
	}

	seg_tree[root] = seg_tree[lson] + seg_tree[rson];
}


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	while (cin >> N && N) {
		memset(seg_tree, 0, sizeof(seg_tree));
		for (int i = 1; i <= N; i++) {
			cin >> nums[i];
			sorted[i] = nums[i];
		}

		sort(sorted + 1, sorted + N + 1);
		len = unique(sorted + 1, sorted + N + 1) - (sorted + 1);
		LL res = 0;

		for (int i = 1; i <= N; i++) {
			int id = lower_bound(sorted + 1, sorted + N + 1, nums[i]) - sorted;
			res += query(1, 1, len, id + 1, len);
			update(1, 1, len, id);
		}
		cout << res << endl;
	}//while

	return 0;
}