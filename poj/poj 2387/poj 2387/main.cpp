#include <iostream>
#include <stdio.h>
#include <string>
#include <memory.h>
#include <algorithm>

using namespace std;

const int maxn = 1000 + 20;
const int INF = 0x3f3f3f3f;

int T, N;
int dist[maxn], tab[maxn][maxn];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	cin >> T >> N;

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			tab[i][j] = INF;
		}
	}

	for (int i = 0; i < T; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (c > tab[a][b])
			continue;
		tab[a][b] = tab[b][a] = c;
	}

	dist[1] = 0;
	for (int i = 2; i <= N; i++) {
		dist[i] = tab[1][i];
	}

	bool visited[maxn];
	memset(visited, false, sizeof(visited));
	visited[1] = true;
	for (int ind = 0; ind < N - 1; ind++) {
		int s = -1, mini = INF;
		for (int i = 1; i <= N; i++) {
			if (!visited[i] && dist[i] < mini) {
				s = i;
				mini = dist[i];
			}
		}

		visited[s] = true;
		for (int i = 1; i <= N; i++) {
			if (tab[s][i] != INF && dist[i] > dist[s] + tab[s][i]) {
				dist[i] = dist[s] + tab[s][i];
			}
		}
	}
	cout << dist[N] << endl;
	return 0;
}