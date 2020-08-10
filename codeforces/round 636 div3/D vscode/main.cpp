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

const int maxn = 400000 + 10;
LL tree[maxn << 2], add[maxn << 2],  N, K;
int A[maxn];

void push_down(int root, int lp, int rp) {
	if (add[root] == 0) {
		return;
	}

	int left_son = root << 1;
	int right_son = (root << 1) | 1;
	int mid = (lp + rp) >> 1;
	//tree[root] += (rp - lp + 1) * add[root];
	
	add[left_son] += add[root];
	add[right_son] += add[root];

	tree[left_son] += add[root];
	tree[right_son] += add[root];
	add[root] = 0;
}

void update_tree(int root, int lp, int rp, int up_lp, int up_rp, int value) {
	if (up_lp > rp || up_rp < lp) {
		return;
	}

	if (up_lp <= lp && rp <= up_rp) {
		add[root] += value;
		tree[root] += value;
		return;
	}

	push_down(root, lp, rp);

	int left_son = root << 1;
	int right_son = (root << 1) | 1;
	int mid = (lp + rp) >> 1;
	update_tree(left_son, lp, mid, up_lp, up_rp, value);
	update_tree(right_son, mid + 1, rp, up_lp, up_rp, value);
	tree[root] = min(tree[left_son], tree[right_son]);
}

void build_tree(int root, int lp, int rp) {
	if (lp > rp) {
		return;
	}
	if (lp == rp) {
		add[root] = 0;
		tree[root] = 0;
		return;
	}
	int mid = (lp + rp) >> 1;
	int left_son = root << 1;
	int right_son = (root << 1) | 1;
	build_tree(left_son, lp, mid);
	build_tree(right_son, mid + 1, rp);
	tree[root] = 0;
	add[root] = 0;
}

LL query(int root, int lp, int rp, int que_lp, int que_rp) {
	if (que_lp > rp || que_rp < lp) {
		return 0xffffffff;
	}
	if (que_lp <= lp && rp <= que_rp) {
		return tree[root];
	}

	push_down(root, lp, rp);
	int left_son = root << 1;
	int right_son = (root << 1) | 1;
	int mid = (lp + rp) / 2;

	LL a = query(left_son, lp, mid, que_lp, que_rp);
	LL b = query(right_son, mid + 1, rp, que_lp, que_rp);
	return min(a, b); 
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int kasenum, N, K;
	cin >> kasenum;
	while (kasenum--) {
		//memset(tree, 0, sizeof(tree));
		//memset(add, 0, sizeof(add));

		cin >> N >> K;
		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}

		build_tree(1, 1, 2 * K);
		for (int i = 0; i < N / 2; i++) {
			LL a = A[i], b = A[N - i - 1];
			LL c = a + b;
			
			LL max_add = K - min(a, b);
			LL max_sub = max(a, b) - 1;
			LL add_once_rb = c + max_add;
			LL sub_once_lb = c - max_sub;
			
			if (sub_once_lb <= c - 1)
				update_tree(1, 1, 2 * K, sub_once_lb, c - 1, 1);
			if (c + 1 <= add_once_rb)
				update_tree(1, 1, 2 * K, c + 1, add_once_rb, 1);
			
			if (2 <= sub_once_lb - 1) 
				update_tree(1, 1, 2 * K, 2, sub_once_lb - 1, 2);
			if (add_once_rb + 1 <= 2 * K)
				update_tree(1, 1, 2 * K, add_once_rb + 1, 2 * K, 2);

		}

		cout << query(1, 1, 2 * K, 2, 2 * K) << endl;
	}

	return 0;
}