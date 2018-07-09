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

const LL maxn = 100 + 5;

vector<PII> edges[maxn];

LL N, A[maxn], K;

bool cmp(LL a, LL b)
{
	return a > b;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	cin >> N >> K;
	for (LL i = 1; i <= N; i++) {
		cin >> A[i];
	}

	vector<vector<vector<vector<LL> >> > re_w(maxn, vector<vector<vector<LL>>>(maxn, vector<vector<LL>>(maxn, vector<LL>(maxn, 0))));

	for (LL i = 0; i < N - 1; i++) {
		LL u, v, w;
		cin >> u >> v >> w;
		edges[u].push_back(make_pair(w, v));
		edges[v].push_back(make_pair(w, u));
	}

	for (LL st = 1; st <= N; st++) {
		queue<LL> que;
		que.push(st);

		vector<bool> vis(maxn, false);
		vis[st] = true;
		LL nu = A[st];

		while (!que.empty()) {
			LL pos = que.front(); que.pop();
			for (PII e : edges[pos]) {
				LL cost = e.first, to = e.second;

				if (vis[to])
					continue;
				vis[to] = true;
				que.push(to);
				re_w[st][to][pos][to] += nu * cost;
			}
		}//while
	}

	LL ans = LONG_MAX;

	for (int cen = 1; cen <= N; cen++) {
		LL tmp = 0;
		
		queue<int> que;
		que.push(cen);
		vector<bool> vis(maxn, false);
		vis[cen] = true;
		vector<LL> path;

		while (!que.empty()) {
			int pos = que.front(); que.pop();
			for (PII e : edges[pos]) {
				LL cost = e.first, to = e.second;

				if (vis[to])
					continue;
				vis[to] = true;
				que.push(to);
				
				LL t = 0;
				for (int st = 1; st <= N; st++) {
					for (int ed = 1; ed <= N; ed++) {
						if (ed == st)
							continue;
						t += re_w[st][ed][pos][to];
					}
				}
				path.push_back(t);
			}
		}//que

		sort(path.begin(), path.end(), cmp);
		for (int i = K; i < path.size(); i++) {
			tmp += path[i];
		}
		ans = min(tmp, ans);
	}//for int cen

	cout << ans << endl;

	return 0;
}