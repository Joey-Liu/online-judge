#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <memory.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <limits.h>

using namespace std;
typedef long long LL;
typedef pair<LL, LL > PII;

const int maxn = 1000 + 50;

LL N, K, A[maxn];
vector<vector<PII>> edges(maxn);

LL dfs(vector<LL> & path, int cur, vector<bool> & vis) {
	LL tot = 0;
	for (int i = 0; i < edges[cur].size(); i++) {
		LL to = edges[cur][i].second, cost = edges[cur][i].first;
		if (vis[to])
			continue;
		
		vis[to] = true;
		LL people = dfs(path, to, vis);
		path.push_back(cost * people);
		tot += people;
	}
	return tot + A[cur];
}

LL	work(int cen) {
	
	vector<LL> path;
	vector<bool> vis(N + 1, false);
	vis[cen] = true;

	dfs(path, cen, vis);
	sort(path.begin(), path.end());

	LL ans = 0;
	for (int i = 0; i < path.size() - K; i++) {
		ans += path[i];
	}
	return ans;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> N >> K;

	
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < N - 1; i++) {
		LL u, v, w;
		cin >> u >> v >> w;
		edges[u].push_back(make_pair(w, v));
		edges[v].push_back(make_pair(w, u));
	}
	
	bool first = true;
	LL ans = -1;
	for (int cen = 1; cen <= N; cen++) {
		if (first) {
			ans = work(cen);
			first = false;
		}
		else {
			ans = min(ans, work(cen));
		}
	}
	cout << ans << endl;
	return 0;
}