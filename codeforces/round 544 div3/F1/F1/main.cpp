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
typedef pair<int, int> PII;

const int maxn = 200000 + 10;

vector<vector<int> > vvi(maxn, vector<int>());
int N, M;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	int maxi_de = 0, ind = 0;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		vvi[a].push_back(b);
		vvi[b].push_back(a);
	}

	for (int i = 1; i <= M; i++) {
		if (maxi_de < vvi[i].size()) {
			ind = i;
			maxi_de = vvi[i].size();
		}
	}

	queue<int> que;
	vector<PII> res;
	vector<bool> vis(N + 1, false);
	vis[ind] = true;
	for (int i = 0; i < vvi[ind].size(); i++) {
		que.push(vvi[ind][i]);
		res.push_back(make_pair(ind, vvi[ind][i]));
		vis[vvi[ind][i]] = true;
	}

	vis[ind] = true;
	while (!que.empty()) {
		int t = que.front(); que.pop();
		for (int i = 0; i < vvi[t].size(); i++) {
			if (!vis[vvi[t][i]]) {
				vis[vvi[t][i]] = true;
				que.push(vvi[t][i]);
				res.push_back(make_pair(t, vvi[t][i]));
			}
		}
	}
	for (auto t : res) {
		cout << t.first << " " << t.second << endl;
	}

	return 0;
}