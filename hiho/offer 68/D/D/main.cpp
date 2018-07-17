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

const int maxn = 100000 + 20;

vector<int> graph[maxn];
int N, ans = 0;

int dfs(int cur, int prev) {
	
	int fir = 0, sec = 0;
	for (int i = 0; i < graph[cur].size(); i++) {
		int to = graph[cur][i];
		if (to == prev)
			continue;

		int depth = dfs(to, cur) + 1;
		if (depth > fir) {
			sec = fir;
			fir = depth;
		}
		else if (depth > sec) {
			sec = depth;
		}
	}

	ans = max(ans, fir + sec);
	return fir;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> N;
	for	(int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dfs(1, 0);
	int k = 1, res = 0;
	while (k < ans) {
		k <<= 1;
		res++;
	}
	cout << res << endl;
	return 0;
}