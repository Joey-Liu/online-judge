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
#include <limits.h>

using namespace std;

typedef pair<int, int> PII;

const int maxn = 10000 + 50;

vector<PII> edges[maxn];

map<string, int> tab;
vector<string> vs;

int N, src, dst;
int get_id(string str) {
	if (tab.count(str)) {
		return tab[str];
	}

	tab[str] = vs.size();
	vs.push_back(str);
	return tab[str];
}

struct cmp {
	bool operator() (PII p1, PII p2) {
		return p1.first > p2.first;
	}
};

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string s1, s2;
	while (cin >> N && N != -1) {
		vs.clear();
		tab.clear();
		for (int i = 0; i < maxn; i++)
			edges[i].clear();

		cin >> s1 >> s2;
		src = get_id(s1);
		dst = get_id(s2);

		for (int i = 0; i < N; i++) {
			int co;
			cin >> s1 >> s2 >> co;
			int a = get_id(s1), b = get_id(s2);
			edges[a].push_back(make_pair(co, b));
			edges[b].push_back(make_pair(co, a));
		}
		
		int nodes_num = vs.size();
		vector<int> dist(nodes_num, INT_MAX);
		priority_queue<PII, vector<PII>, cmp> pq;

		for (int j = 0; j < edges[src].size(); j++) {
			int to = edges[src][j].second, co = edges[src][j].first;
			dist[to] = min(dist[to], co);
			pq.push(edges[src][j]);
		}
		dist[src] = 0;
		
		while (!pq.empty()) {
			PII pii = pq.top(); pq.pop();
			int co = pii.first, to = pii.second;

			if (dist[to] < co)
				continue;

			for (auto e : edges[to]) {
				int td = e.second, ct = e.first;
				if (dist[td] > ct + co) {
					dist[td] = ct + co;
					pq.push(make_pair(ct + co, td));
				}
			}
		}
		if (dist[dst] != INT_MAX)
			cout << dist[dst] << endl;
		else
			cout << -1 << endl;
	}//while

	return 0;
}