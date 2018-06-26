#include <iostream>
#include <string>
#include <memory.h>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;
const int maxn = 150;
typedef pair<int, int> PII;

int N;
bool visited[maxn];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (cin >> N && N) {
		vector<vector<PII>> edge(N + 1);
		memset(visited, false, sizeof(visited));
		
		for (int i = 0; i < N *(N - 1) / 2; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			edge[a].push_back(make_pair(c, b));
			edge[b].push_back(make_pair(c, a));
		}

		visited[1] = true;
		priority_queue<PII, vector<PII>, greater<PII>> pq;
		for (int i = 0; i < edge[1].size(); i++) {
			pq.push(edge[1][i]);
		}

		int ans = 0;
		for (int ind = 0; ind < N - 1; ) {
			PII e = pq.top(); pq.pop();
			int to = e.second, cost = e.first;
			if (visited[to]) 
				continue;
			
			ans += cost;
			visited[to] = true;
			for (int i = 0; i < edge[to].size(); i++) {
				if (!visited[edge[to][i].second])
					pq.push(edge[to][i]);
			}
			ind++;
		}
		cout << ans << endl;
	}
}