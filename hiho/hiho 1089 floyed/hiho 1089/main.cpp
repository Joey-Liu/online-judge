#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <memory.h>

using namespace std;

const int maxn = 100 + 50;
int graph[maxn][maxn], N, M;

int main()
{

	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> N >> M;
	memset(graph, 0x3f, sizeof(graph));

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a][b] = min(graph[a][b], c);
		graph[b][a] = min(graph[b][a], c);
	}

	for (int i = 1; i <= N; i++) {
		graph[i][i] = 0;
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << graph[i][j];
			if (j != N)
				cout << " ";
		}
		cout << endl;
	}
	return 0;
}