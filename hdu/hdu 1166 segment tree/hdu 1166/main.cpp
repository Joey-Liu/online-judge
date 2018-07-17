#include <iostream>
#include <memory.h>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <limits.h>


using namespace std;

const int maxn = 50000 * 4 + 20;
const int inf = INT_MAX;

int seg_tree[maxn], people[50000 + 50];
int N;

int build_tree(int root, int lp, int rp) {
	if (lp == rp) {
		return seg_tree[root] = people[lp];
	}

	int mid = lp + (rp - lp) / 2;
	int s1 = build_tree(root << 1, lp, mid);
	int s2 = build_tree((root << 1) + 1, mid + 1, rp);
	return seg_tree[root] = s1 + s2;
}

void add_people(int root, int lp, int rp, int target, int nu) {
	if (lp == rp) {
		seg_tree[root] += nu;
		return;
	}

	int mid = lp + (rp - lp) / 2;
	if (target <= mid) {
		add_people(root << 1, lp, mid, target, nu);
	}
	else {
		add_people((root << 1) + 1, mid + 1, rp, target, nu);
	}
	seg_tree[root] += nu;
}

int query(int root, int lp, int rp, int query_lp, int query_rp) {
	if (lp >= query_lp && rp <= query_rp) {
		return seg_tree[root];
	}
	else if (lp > query_rp || rp < query_lp) {
		return -1;
	}
	else {
		int mid = lp + (rp - lp) / 2;
		int s1 = query(root << 1, lp, mid, query_lp, query_rp);
		int s2 = query((root << 1) + 1, mid + 1, rp, query_lp, query_rp);
		s1 = max(s1, 0);
		s2 = max(s2, 0);
		return s1 + s2;
	}

}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int kasenum, T = 1;
	cin >> kasenum;
	while (kasenum--) {
		cin >> N;
		for (int i = 1; i <= N; i++)
			cin >> people[i];

		build_tree(1, 1, N);
		cout << "Case " << T++ << ":" << endl;
		string str;
		while (cin >> str && str[0] != 'E') {
			int a, b, ans;
			if (str[0] == 'Q') {
				cin >> a >> b;
				ans = query(1, 1, N, a, b);
				cout << ans << endl;
			}
			else if (str[0] == 'A') {
				cin >> a >> b;
				add_people(1, 1, N, a, b);
			}
			else {
				cin >> a >> b;
				add_people(1, 1, N, a, -b);
			}
		}//while cin
	}//while
	return 0;
}