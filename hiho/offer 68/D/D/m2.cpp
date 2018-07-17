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
const int maxn = 100000 + 50;
int N;
vector<int> graph[maxn];
int step[maxn];
bool vis[maxn];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	vis[1] = true;
	queue<int> que;
	que.push(1);
	int layer = 0;


	while (!que.empty()) {
		int N = que.size();
		for (int i = 0; i < que.size(); i++) {
			int cur = que.front(); que.pop();
			for (int j = 0; j < graph[cur].size(); j++) {
				int to = graph[cur][j];
				if (vis[to])
					continue;
				vis[to] = true;
				que.push(to);
				step[to] = layer + 1;
			}
		}//for int i
		layer += 1;
	}//while
	
	int fir = 0, sec = 0;
	for (int i = 1; i <= N; i++) {
		if (step[i] > fir) {
			sec = fir;
			fir = step[i];
		}
		else if (step[i] > sec)
			sec = step[i];
	}

	int len = fir + sec;
	int k = 1, ans =0;
	while (k < len) {
		k <<= 1;
		ans++;
	}

	cout << ans << endl;
	return 0;
}