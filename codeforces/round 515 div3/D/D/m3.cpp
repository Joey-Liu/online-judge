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
typedef long double LD;
typedef pair<int, int> PII;

const int maxn = 1e5 + 50;
int nums[maxn], seg_tree[(maxn << 2) + 50];

int build_tree(int root, int lp, int rp) {
	if (lp == rp) {
		return seg_tree[root] = nums[lp];
	}

	int mid = lp + (rp - lp) / 2;
	int lson = root << 1, rson = (root << 1) | 1;
	int left_sum = build_tree(lson, lp, mid);
	int right_sum = build_tree(rson, mid + 1, rp);
	
	return seg_tree[root] = left_sum + right_sum;
}

int query(int root, int lp, int rp, int q_lp, int q_rp) {
	if (q_lp > rp || q_rp < lp)
		return 0;
	if (q_lp <= lp && rp <= q_rp) {
		return seg_tree[root];
	}

	int mid = lp + (rp - lp) / 2;
	int lson = root << 1, rson = (root << 1) | 1;
	return query(lson, lp, mid, q_lp, q_rp) + query(rson, mid + 1, rp, q_lp, q_rp);
}

int	add(int root, int lp, int rp, int pos, int val) {
	if (lp == rp) {
		return seg_tree[root] = val;
	}

	if (pos < lp || pos > rp) {
		return seg_tree[root];
	}

	int mid = lp + (rp - lp) / 2;
	int lson = root << 1, rson = (root << 1) | 1;
	return seg_tree[root] = add(lson, lp, mid, pos, val) + add(rson, mid + 1, rp, pos, val);
}



int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);



	return 0;
}