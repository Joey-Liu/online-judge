#include <iostream>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <set>

using namespace std;

const int maxn = 5000 + 10;

vector<vector<int> > edges(maxn);
int visited[maxn];


void dfs(int id, int n) {
	for (int i = 0; i < edges[n].size(); i++) {
		int j = edges[n][i];
		if (visited[j] == -1) {
			visited[j] = id;
			dfs(id, j);
		}
	}
}

void dfs2(int id, int n) {
	for (int i = 0; i < edges[n].size(); i++) {
		int j = edges[n][i];
		if (visited[j] != id && visited[j] != 1) {
			visited[j] = id;
			dfs2(id, j);
		}
	}
}

int N, M, S;
int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> M >> S;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		edges[a].push_back(b);
	}
	memset(visited, -1, sizeof(visited));
	
	visited[S] = 1;
	dfs(1, S);

	int id = 2;
	for (int i = 1; i <= N; i++) {
		if (visited[i] != -1) {
			continue;
		}

		visited[i] = id;
		dfs2(id++, i);
	}

	set<int> si;
	for (int i = 1; i <= N; i++) {
		si.insert(visited[i]);
	}
	cout << si.size() - 1 << endl;
	return 0;
}