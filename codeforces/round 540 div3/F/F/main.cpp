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


const int maxn = 300000 + 50;
vector<int> nodes[maxn];
int colors[maxn], N, red_cnt = 0, blue_cnt = 0;
int res = 0;

PII dfs(int cur, int par) {
	int rcnt = 0, blcnt = 0;
	if (colors[cur] == 1)
		rcnt++;
	if (colors[cur] == 2)
		blcnt++;
	for (int i = 0; i < nodes[cur].size(); i++) {
		if (nodes[cur][i] == par)
			continue;
		PII pii = dfs(nodes[cur][i], cur);
		rcnt += pii.first;
		blcnt += pii.second;
	}
	if (rcnt == red_cnt && blcnt == 0)
		res++;
	else if (rcnt == 0 && blcnt == blue_cnt)
		res++;

	return make_pair(rcnt, blcnt);
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> colors[i];
		if (colors[i] == 1)
			red_cnt++;
		if (colors[i] == 2)
			blue_cnt++;
	}
	for (int i = 1; i < N; i++) {
		int a, b;
		cin >> a >> b;
		nodes[a].push_back(b);
		nodes[b].push_back(a);
	}
	dfs(1, 0);
	cout << res << endl;



	return 0;
}