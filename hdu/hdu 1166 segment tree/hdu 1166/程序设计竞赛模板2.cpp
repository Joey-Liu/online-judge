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

const int maxn = 1e5;

int A[maxn], seg_tree[(maxn << 2) + 50];

int build_tree(int lp, int rp, int root) {
	if (lp == rp) {
		return seg_tree[root] = A[lp];
	}

	int mid = lp + (rp - lp) / 2;
	int lson = root << 1, rson = (root << 1) | 1;
	
	build_tree(lp, mid, lson);
	build_tree(mid + 1, rp, rson);
	return seg_tree[root] = seg_tree[lson] + seg_tree[rson];
}


int query(int lp, int rp, int q_lp, int q_rp, int root) {
	if (q_lp > rp || q_rp < lp)
		return 0;
	if (q_lp <= lp && rp <= q_rp)
		return seg_tree[root];

	int mid = lp + (rp - lp) / 2;
	int lson = root << 1, rson = (root << 1) | 1;
	
	int left_sum = query(lp, mid, q_lp, q_rp, lson);
	int right_sum = query(mid + 1, rp, q_lp, q_rp, rson);
	return left_sum + right_sum;
}



int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);



	return 0;
}