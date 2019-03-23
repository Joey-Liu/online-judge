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

const int inf = 0x3f3f3f3f;
const int maxn = 1e+5 + 50;
int N;
vector<int> sons[maxn];
LL sum[maxn], a[maxn];

void dfs(int cur, int par) {
	LL tmp = inf;
	for (int i = 0; i < sons[cur].size(); i++) {
		dfs(sons[cur][i], cur);
		tmp = min(tmp, sum[sons[cur][i]]);
	}
	if (sum[cur] != -1)
		return;
	if (sons[cur].size() == 0)
		sum[cur] = sum[par];
	else {
		sum[cur] = tmp;
	}
}

void dfs2(int cur, int par) {
	a[cur] = sum[cur] - sum[par];
	for (int i = 0; i < sons[cur].size(); i++) {
		dfs2(sons[cur][i], cur);
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 2; i <= N; i++) {
		int tmp;
		cin >> tmp;
		sons[tmp].push_back(i);
	}
	for (int i = 1; i <= N; i++) {
		cin >> sum[i];
	}

	dfs(1, 0);
	dfs2(1, 0);
	LL ans = 0;
	bool flag = true;
	for (int i = 1; i <= N; i++) {
		ans += a[i];
		if (a[i] < 0)
			flag = false;
	}
	
	if (!flag)
		cout << "-1" << endl;
	else {
		cout << ans << endl;
	}
	return 0;
}