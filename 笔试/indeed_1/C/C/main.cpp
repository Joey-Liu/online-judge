#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <algorithm>
#include <functional>

using namespace std;

typedef long long LL;
typedef pair<LL, LL> PLL;

const int maxn = 100000 + 10;
LL N, M, K;
LL dist[maxn], X[maxn];


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	vector<vector<PLL> > edges(N + 1);

	for (int i = 0; i < M; i++) {
		LL a, b, c;
		cin >> a >> b >> c;
		edges[a].push_back(make_pair(c, b));
		edges[b].push_back(make_pair(c, a));
	}
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> X[i];
	}

	for (int i = 0; i <= N; i++) {
		dist[i] = LLONG_MAX;
	}

	dist[0] = 0;
	for (int i = 0; i < K; i++) {
		dist[X[i]] = 0;
	}

	priority_queue<PLL, vector<PLL>, greater<PLL>> pq;
	for (int i = 0; i < K; i++) {
		pq.push(make_pair(dist[X[i]], X[i]));
	}

	while (!pq.empty()) {
		PLL pll = pq.top(); pq.pop();
		LL v = pll.second;
		if (dist[v] < pll.first)
			continue;

		for (int i = 0; i < edges[v].size(); i++) {
			PLL e = edges[v][i];
			LL to = e.second, cost = e.first;
			if (dist[to] > dist[v] + cost) {
				dist[to] = dist[v] + cost;
				pq.push(make_pair(dist[to], to));
			}
		}
	}//while

	int Q, y;
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		cin >> y;
		cout << dist[y] << endl;
	}
	return 0;
}