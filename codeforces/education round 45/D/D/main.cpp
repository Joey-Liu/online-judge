#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;

const int maxn = 1000 + 50;
int N, A, B;
int graph[maxn][maxn];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> N >> A >> B;
	if (min(A, B) != 1) {
		cout << "NO" << endl;
		return 0;
	}

	if (N <= 3 && N >=2 && max(A, B) == 1) {
		cout << "NO" << endl;
		return 0;
	}

	bool flag = true;
	memset(graph, 0, sizeof(graph));
	if (A == 1) {
		swap(A, B);
		flag = false;
	}

	int cur = 0, cnt = 0;
	while (cnt < N - A) {
		graph[cur][cur + 1] = 1;
		graph[cur + 1][cur] = 1;
		cur++;
		cnt++;
	}

	if (!flag) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i == j)
					continue;
				graph[i][j] = 1 - graph[i][j];
			}
		}
	}

	cout << "YES" << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << graph[i][j];
		}
		cout << endl;
	}
	return 0;
}