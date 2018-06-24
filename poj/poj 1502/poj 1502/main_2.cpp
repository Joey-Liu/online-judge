#include <iostream>
#include <algorithm>
#include <memory.h>
#include <queue>
#include <functional>
#include <string>
#include <sstream>

using namespace std;

typedef pair<int, int> PII;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	stringstream ss;
	string str;
	int N;
	cin >> N;
	vector<vector<PII> > edges(N + 1);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			cin >> str;
			if (str[0] == 'x')
				continue;
			ss.clear(); ss.str("");
			ss << str;
			int t;
			ss >> t;
			edges[i].push_back(make_pair(t, j));
			edges[j].push_back(make_pair(t, i));
		}
	}

	int dist[150];
	for (int i = 0; i < 150; i++)
		dist[i] = INT_MAX;

	dist[1] = 0;
	priority_queue<PII, vector<PII>, greater<PII>> pq;

	for (int i = 0; i < edges[1].size(); i++) {
		pq.push(edges[1][i]);
		dist[edges[1][i].second] = edges[1][i].first;
	}

	while (!pq.empty()) {
		PII p = pq.top(); pq.pop();
		int v = p.second, cost = p.first;
		if (dist[v] < cost)
			continue;

		for (int i = 0; i < edges[v].size(); i++) {
			PII e = edges[v][i];
			int to = e.second, co = e.first;
			if (dist[to] > dist[v] + co) {
				dist[to] = dist[v] + co;
				pq.push(make_pair(dist[to], to));
			}
		}

	}

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		ans = max(ans, dist[i]);
	}
	cout << ans << endl;
	return 0;
}