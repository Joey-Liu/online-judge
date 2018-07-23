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

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int maxn = 100000 + 50;
int N, M, max_dis;
vector<PII> graph[maxn];


int dfs(int cur, int fa) {
	int fir = 0, sec = 0;
	for (int i = 0; i < graph[cur].size(); i++) {
		int to = graph[cur][i].second, cost = graph[cur][i].first;
		if (to == fa)
			continue;

		int tmp = cost + dfs(to, cur);
		if (tmp > fir) {
			sec = fir;
			fir = tmp;
		}
		else if (tmp > sec) {
			sec = tmp;
		}
	}

	max_dis = max(fir + sec, max_dis);
	return fir;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (cin >> N >> M) {
		for (int i = 1; i <= N; i++)
			graph[i].clear();

		for (int i = 0; i < M; i++) {
			int a, b, c;
			char ch;
			cin >> a >> b >> c >> ch;
			graph[a].push_back(make_pair(c, b));
			graph[b].push_back(make_pair(c, a));
		}
		max_dis = 0;
		dfs(1, 0);
		cout << max_dis << endl;
	}//while
	return 0;
}