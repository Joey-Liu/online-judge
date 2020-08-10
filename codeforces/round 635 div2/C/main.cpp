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
#include <unordered_set>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;

const int maxn = 200000 + 10;
vector<int> edges[maxn];


struct Node {
	int id;
	int level;
	int num_of_sons;
};

Node nodes[maxn];
int parent[maxn];

bool cmp(Node& n1, Node& n2) {
	return n1.level > n2.level;
}

struct Node_cmp {
	bool operator() (Node n1, Node n2) {
		return n1.level < n2.level;
	}
};

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		edges[a].emplace_back(b);
		edges[b].emplace_back(a);
	}

	queue<int> que;
	que.push(1);
	int steps = 0;
	unordered_set<int> si;
	si.insert(1);
	parent[1] = -1;

	while (!que.empty()) {
		int size = que.size();
		for (int i = 0; i < size; i++) {
			int t = que.front();
			que.pop();
			nodes[t].level = steps;
			nodes[t].num_of_sons = edges[t].size() - 1;
			nodes[t].id = t;

			for (int j = 0; j < edges[t].size(); j++) {
				int son = edges[t][j];
				if (si.count(son)) {
					continue;
				}
				que.push(son);
				si.insert(son);
				parent[son] = t;
			}
		}

	}//while que empty
	
	priority_queue<Node, vector<Node>, Node_cmp> pq;
	for (int i = 1; i <= N; i++) {
		pq.push(nodes[i]);
	}

	int ind_cnt = 0, res = 0;
	
	while (ind_cnt < K) {
		Node n = pq.top();
		pq.pop();
		res += n.level;
	}

	return 0;
}