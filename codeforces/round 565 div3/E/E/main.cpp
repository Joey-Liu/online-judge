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

const int maxn = 2 * 1e5 + 20;
int N, M;
vector<int> vi[maxn], res[2];
bool vis[maxn];

void dfs(int cur, int ind) {
	vis[cur] = true;
	for (int i = 0; i < vi[cur].size(); i++) {
		if (!vis[vi[cur][i]]) {
			res[ind^1].push_back(vi[cur][i]);
			dfs(vi[cur][i], ind^1);
		}
	}
}

int main()
{

	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		memset(vis, false, sizeof(vis));
		cin >> N >> M;
		for (int i = 1; i <= N; i++) {
			vi[i].clear();
		}//for int i


		for (int i = 0; i < M; i++) {
			int a, b;
			//cin >> a >> b;
			scanf("%d%d", &a, &b);
			vi[a].push_back(b);
			vi[b].push_back(a);
		}

		res[0].clear(); res[1].clear();
		res[0].push_back(1);
		dfs(1, 0);
		if (res[0].size() > res[1].size()) {
			swap(res[0], res[1]);
		}
		cout << res[0].size() << endl;
		for (int i = 0; i < res[0].size() - 1; i++) {
			//cout << res[0][i] << " ";
			printf("%d ", res[0][i]);
		}
		//cout << res[0][res[0].size() - 1] << endl;
		printf("%d\n", res[0][res[0].size() - 1]);
	}//while

	return 0;
}