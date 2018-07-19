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

typedef pair<int, int> PII;

const int maxn = 50000 + 50;
int height[maxn];
int min_seg[maxn * 4], max_seg[maxn * 4], N, Q;


 PII build_tree(int cur, int lp, int rp) {
	if (lp == rp) {
		min_seg[cur] = height[lp];
		max_seg[cur] = height[lp];
		return make_pair(height[lp], height[lp]);
	}

	int mid = lp + (rp - lp) / 2;
	PII le_pii = build_tree(cur << 1, lp, mid);
	PII ri_pii = build_tree((cur << 1) + 1, mid + 1, rp);

	min_seg[cur] = min(le_pii.first, ri_pii.first);
	max_seg[cur] = max(le_pii.second, ri_pii.second);

	return make_pair(min_seg[cur], max_seg[cur]);
}

 PII query(int root, int lp, int rp, int q_lp, int q_rp) {

	 if (q_lp > rp || q_rp < lp) {
		 return make_pair(0x3f3f3f3f, -1);
	 }
	 
	 if (q_lp <= lp && rp <= q_rp) {
		 return make_pair(min_seg[root], max_seg[root]);
	 }

	 int mid = lp + (rp - lp) / 2;
	 PII le_pii = query(root << 1, lp, mid, q_lp, q_rp);
	 PII ri_pii = query((root << 1) + 1, mid + 1, rp, q_lp, q_rp);

	 int mini = min(le_pii.first, ri_pii.first);
	 int maxi = max(le_pii.second, ri_pii.second);
	 
	 return make_pair(mini, maxi);
 }

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	while (cin >> N >> Q) {
		for (int i = 1; i <= N; i++) {
			scanf("%d", &height[i]);
		}
		
		memset(min_seg, 0x3f, sizeof(min_seg));
		memset(max_seg, -1, sizeof(max_seg));

		build_tree(1, 1, N);
		for (int i = 0; i < Q; i++) {
			int q_lp, q_rp;
			scanf("%d%d", &q_lp, &q_rp);
			
			PII pii = query(1, 1, N, q_lp, q_rp);
			printf("%d\n", pii.second - pii.first);
		}
	}//while

	return 0;
}