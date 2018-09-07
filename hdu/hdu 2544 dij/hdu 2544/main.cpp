#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <memory.h>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
typedef pair<int, int> PII;

const int maxn = 150;
const int inf = 0x3f3f3f3f;

int dist[maxn], N, M;

struct cmp {
	bool operator() (PII p1, PII p2) {
		return p1 > p2;
	}
};


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (cin >> N >> M) {
		if (!N && !M)
			break;

		vector<vector<PII> > edges(N + 1);
		for (int i = 0; i < M; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			edges[a].push_back(make_pair(c, b));
			edges[b].push_back(make_pair(c, a));
		}

		memset(dist, 0x3f, sizeof(dist));
		dist[1] = 0;
		priority_queue<PII, vector<PII>, cmp> pq;

		for (int i = 0; i < edges[1].size(); i++) {
			pq.push(edges[1][i]);
			dist[edges[1][i].second] = min(dist[edges[1][i].second], edges[1][i].first);
		}

		while (!pq.empty()) {
			int to = pq.top().second, cost = pq.top().first;
			pq.pop();

			if (cost > dist[to]) 
				continue;

			for (int i = 0; i < edges[to].size(); i++) {
				int tar = edges[to][i].second, d = edges[to][i].first;
				if (cost + d < dist[tar]) {
					dist[tar] = cost + d;
					pq.push(make_pair(cost + d, tar));
				}
			}
		}//while

		cout << dist[N] << endl;
	}//while
	return 0;
}