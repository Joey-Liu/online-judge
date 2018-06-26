#include <iostream>
#include <vector>
#include <memory.h>
#include <string>

using namespace std;
const int maxn = 5000 + 10;

int N, M, S, label = 1;
vector<vector<int> > ve(maxn);
int vis[maxn];
int ru[maxn];

void dfs(int id, int n) {
	for (int i = 0; i < ve[n].size(); i++) {
		int a = ve[n][i];
		if (vis[a] == -1) {
			vis[a] = id;
			dfs(id, a);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M >> S;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		ve[a].push_back(b);
		ru[b]++;
	}

	memset(vis, -1, sizeof(vis));
	vis[S] = label;
	dfs(label++, S);
	
	for (int i = 1; i <= N; i++) {
		if (vis[i] == -1 && ru[i] == 0) {
			vis[i] = label;
			dfs(label++, i);
		}
	}
	
	cout << label - 1 << endl;
}