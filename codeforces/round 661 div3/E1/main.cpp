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
typedef pair<LL, LL> PII;

const int maxn = 200000 + 10;
vector<PII> children[maxn];
int leaf_nums[maxn];

struct Node {
	LL cnt;
	LL weight;
	LL value;
};

struct cmp {

	bool operator() (const Node& n1, const Node& n2) {
		return n1.value < n2.value;
	}

};

int dfs_leaves(int cur, int prev) {
	int leaves = 0;
	if (cur != 1 && children[cur].size() == 1) {
		return leaf_nums[cur] = 1;
	}

	for (int i = 0; i < children[cur].size(); i++) {
		if (children[cur][i].first == prev) {
			continue;
		}
		leaves += dfs_leaves(children[cur][i].first, cur);
	}
	return leaf_nums[cur] = leaves;
}

void dfs_edges(int cur, int prev, vector<Node> & vn) {
	int res = 0;
	if (cur != 1 && children[cur].size() == 1) {
		return;
	}
	
	for (int i = 0; i < children[cur].size(); i++) {
		int nxt = children[cur][i].first;
		if (nxt == prev) {
			continue;
		}
		int weight = children[cur][i].second;
		
		Node node;
		node.cnt = leaf_nums[nxt];
		node.weight = weight;
		node.value = LL(node.cnt) * node.weight;
		vn.emplace_back(node);
		dfs_edges(nxt, cur, vn);
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int kasenum;
	cin >> kasenum;
	while (kasenum--) {
		LL N, S;
		cin >> N >> S;
		for (int i = 1; i <= N; i++) {
			children[i].clear();
			leaf_nums[i] = 0;
		}

		for (int i = 0; i < N - 1; i++) {
			LL a, b, c;
			cin >> a >> b >> c;
			children[a].emplace_back(make_pair(b, c));
			children[b].emplace_back(make_pair(a, c));
		}


		dfs_leaves(1, -1);
		vector<Node> vn;
		dfs_edges(1, -1, vn);

		LL cur_s = 0;
		priority_queue<Node, vector<Node>, cmp> pq;
		for (int i = 0; i < vn.size(); i++) {
			cur_s += vn[i].value;
			Node node;
			node.cnt = vn[i].cnt;
			node.weight = vn[i].weight / 2;
			node.value = vn[i].value - LL(node.cnt) * node.weight;
			pq.emplace(node);
		}

		int res = 0;
		while (cur_s > S) {
			Node node = pq.top();
			pq.pop();
			cur_s -= node.value;
			Node nxt_node;
			nxt_node.cnt = node.cnt;
			nxt_node.weight = node.weight / 2;
			nxt_node.value = node.cnt * node.weight - nxt_node.cnt * nxt_node.weight;
			pq.emplace(nxt_node);
			res += 1;
		}//while

		cout << res << endl;

	}//while


	return 0;
}