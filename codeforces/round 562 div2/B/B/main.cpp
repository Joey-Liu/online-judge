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

const int maxn = 3e5 + 50;
int N, M;
PII pairs[maxn];

bool tor(int a, int b, int x, int y) {
	return (a == x || a == y || b == x || b == y);
}

bool dfs(int x, int y, int cur) {
	if (cur == M)
		return true;
	if (tor(pairs[cur].first, pairs[cur].second, x, y))
		return dfs(x, y, cur + 1);
	else {
		if (y != -1)
			return false;
		if (dfs(x, pairs[cur].first, cur + 1))
			return true;
		else
			return dfs(x, pairs[cur].second, cur + 1);
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> pairs[i].first >> pairs[i].second;
	}
	
	if (dfs(pairs[0].first, -1, 0) || dfs(pairs[0].second, -1, 0))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	
	return 0;
}