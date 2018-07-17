#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <assert.h>

using namespace std;

const int maxn = 200000 + 50;
const int max_depth = 22;
typedef  long long LL;

int merge_tree[max_depth][maxn];
int N, nums[maxn];

void build_tree(int depth, int lp, int rp) {
	if (lp == rp) {
		merge_tree[depth][lp] = nums[lp];
		return;
	}

	int mid = (lp + rp) / 2;
	build_tree(depth + 1, lp, mid);
	build_tree(depth + 1, mid + 1, rp);

	int ind = lp, i = lp, j = mid + 1;
	while (i <= mid || j <= rp) {
		if (i > mid || (j <= rp && merge_tree[depth + 1][j] < merge_tree[depth + 1][i]))
			merge_tree[depth][ind++] = merge_tree[depth + 1][j++];
		else
			merge_tree[depth][ind++] = merge_tree[depth + 1][i++];
	}
}

int query(int depth, int lp, int rp, int q_lp, int q_rp, int val) {
	if (lp > q_rp || rp < q_lp)
		return 0;
	if (q_lp <= lp && rp <= q_rp) {
		return (&merge_tree[depth][rp + 1]) - lower_bound(&merge_tree[depth][lp], &merge_tree[depth][rp + 1], val);
	}

	int mid = (lp + rp) >> 1;
	return query(depth + 1, lp, mid, q_lp, q_rp, val) + query(depth + 1, mid + 1, rp, q_lp, q_rp, val);
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
		--nums[i];
	}
	
	build_tree(0, 0, N - 1);
	LL ans = 0;
	for (int i = 0; i < N; i++) {
		if (nums[i] <= i)
			continue;
		int a = i + 1, b = min(N - 1, nums[i]), c = i;
		ans += query(0, 0, N - 1, a, b, i);
	}
	cout << ans << endl;
	return 0;
}