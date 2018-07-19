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
const int maxn = 10000 + 50;

typedef pair<int, int> PII;

int seg_tree[maxn << 4], N, len, ans;
PII edge[maxn];
set<int> si;

void push_down(int root, int lp, int rp) {
	if (seg_tree[root] != -1) {
		int mid = lp + (rp - lp) / 2;
		int lson = root << 1, rson = (root << 1) | 1;
		
		seg_tree[lson] = seg_tree[root];
		seg_tree[rson] = seg_tree[root];
		seg_tree[root] = -1;
	}
}

void update(int root, int lp, int rp, int up_lp, int up_rp, int label) {
	if (up_lp > rp || up_rp < lp) {
		return;
	}

	if (up_lp <= lp && rp <= up_rp) {
		seg_tree[root] = label;
		return;
	}

	push_down(root, lp, rp);
	int mid = lp + (rp - lp) / 2;
	int lson = root << 1, rson = (root << 1) | 1;
	update(lson, lp, mid, up_lp, up_rp, label);
	update(rson, mid + 1, rp, up_lp, up_rp, label);
}

void query(int root, int lp, int rp) {
	if (seg_tree[root] != -1) {
		if (!si.count(seg_tree[root]))
			ans++;
		si.insert(seg_tree[root]);
		return;
	}

	if (lp == rp)
		return;
	int mid = lp + (rp - lp) / 2;
	int lson = root << 1, rson = (root << 1) | 1;
	query(lson, lp, mid);
	query(rson, mid + 1, rp);
}


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int kasenum = 0;
	cin >> kasenum;
	while (kasenum--) {
		memset(seg_tree, -1, sizeof(seg_tree));
		vector<int> point;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> edge[i].first >> edge[i].second;
			point.push_back(edge[i].first);
			point.push_back(edge[i].second);
		}//for int i


		sort(point.begin(), point.end());
		len = unique(point.begin(), point.end()) - point.begin();
		point.resize(len);

		for (int i = len - 1; i > 0; i--) {
			if (point[i] - point[i - 1] > 1) {
				point.push_back(point[i] - 1);
			}
		}

		sort(point.begin(), point.end());
		len = point.size();
		ans = 0;
		si.clear();
		int label = 1;
		for (int i = 0; i < N; i++) {
			int up_lp = lower_bound(point.begin(), point.end(), edge[i].first) - point.begin();
			int up_rp = lower_bound(point.begin(), point.end(), edge[i].second) - point.begin();
			up_lp++; up_rp++;
			update(1, 1, len, up_lp, up_rp, label++);
		}
		query(1, 1, len);
		cout << si.size() << endl;
	}//while
		
	return 0;
}