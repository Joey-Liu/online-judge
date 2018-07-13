#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;

struct cmp {

	bool operator() (PII p1, PII p2) {
		return p1.first > p2.first;
	}
};

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int N, M, S, T;

	cin >> N >> M >> S >> T;
	vector<vector<PII> > edges(N + 1);

	for (int i = 0; i < M; i++) {
		int u, v, len;
		cin >> u >> v >> len;
		edges[u].push_back(make_pair(len, v));
		edges[v].push_back(make_pair(len, u));
	}

	vector<int> dist(N + 1, inf);
	dist[S] = 0;
	priority_queue<PII, vector<PII>, cmp> que;
	for (int i = 0; i < edges[S].size(); i++) {
		que.push(edges[S][i]);
		dist[edges[S][i].second] = min(edges[S][i].first, dist[edges[S][i].second]);
	}

	while (!que.empty()) {
		int to = que.top().second, d = que.top().first;
		que.pop();
		if (d > dist[to])
			continue;

		for (int i = 0; i < edges[to].size(); i++) {
			int nxt = edges[to][i].second, co = edges[to][i].first;
			if (dist[nxt] > dist[to] + co) {
				dist[nxt] = dist[to] + co;
				que.push(make_pair(dist[nxt], nxt));
			}
		}
	}
	cout << dist[T] << endl;
	return 0;
}