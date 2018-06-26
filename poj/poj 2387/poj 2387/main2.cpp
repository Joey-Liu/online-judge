#include <iostream>
#include <stdio.h>
#include <queue>
#include <memory.h>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
const int maxn = 1000 + 10;

struct cmp {
	bool operator() (const PII & p1, const PII & p2) {
		return p1.first > p2.first;
	}
};

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int N, T;
	cin >> T >> N;
	vector<vector<PII>> edges(N + 1);

	for (int i = 0; i < T; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edges[a].push_back(make_pair(c, b));
		edges[b].push_back(make_pair(c, a));
	}

	priority_queue<PII, vector<PII>, cmp> pq;
	for (int i = 0; i < edges[1].size(); i++) {
		pq.push(edges[1][i]);
	}

	int dist[maxn];
	dist[1] = 0;
	for (int i = 1; i <= N; i++) {
		dist[i] = INF;
	}
	
	while (!pq.empty()) {
		PII e = pq.top(); pq.pop();
		int to = e.second, cost = e.first;
		if (dist[to] < cost)
			continue;
		dist[to] = cost;
		for (int i = 0; i < edges[to].size(); i++) {
			int co = edges[to][i].first, de = edges[to][i].second;
			if (dist[de] > dist[to] + co) {
				dist[de] = dist[to] + co;
				pq.push(make_pair(dist[de], de));
			}

		}
	}
	cout << dist[N] << endl;
}