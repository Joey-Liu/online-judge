#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <vector>

using namespace std;
const int maxn = 200000 + 10;

vector<int> vi[maxn], buff;
int state[maxn];
int N, M, cnt;

void dfs(int cur) {
	state[cur] = 1;
	buff.push_back(cur);
	for (int i = 0; i < vi[cur].size(); i++) {
		int nei = vi[cur][i];
		if (!state[nei]) {
			dfs(nei);
		}
	}
}

bool check() {
	for (int i = 0; i < buff.size(); i++) {
		int bn = buff[i];
		if (vi[bn].size() != 2)
			return false;
	}
	return true;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		vi[a].push_back(b);
		vi[b].push_back(a);
	}

	cnt = 0;
	memset(state, 0, sizeof(state));
	for (int i = 1; i <= N; i++) {
		if (!state[i]) {
			dfs(i);
			if (check())
				cnt++;
			buff.clear();
		}
	}

	cout << cnt << endl;
	return 0;
}