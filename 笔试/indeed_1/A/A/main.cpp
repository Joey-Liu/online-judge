#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

const int maxn = 15;
int nu[maxn];
int N, M, frien[maxn][maxn], cnt = 0;
bool visited[maxn];

void dfs(int layer) {
	if (layer == N) {
		if (!frien[nu[N]][nu[1]]) {
			cnt++;
		}
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (visited[i])
			continue;
		int ind = nu[layer];
		if (frien[ind][i])
			continue;
		nu[layer + 1] = i;
		visited[i] = true;
		dfs(layer + 1);
		visited[i] = false;
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		frien[a][b] = frien[b][a] = 1;
	}

	memset(visited, 0, sizeof(visited));
	memset(nu, 0, sizeof(0));
	nu[1] = 1;
	visited[1] = true;
	dfs(1);
	visited[1] = false;
	
	cout << cnt << endl;
	return 0;
}