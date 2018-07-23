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
const int maxn = 20000 + 50;

vector<int> neigh[maxn];
int N, ans_num, ind;


int dfs(int cur, int fa) {
	int node_num = 1;
	int tmp = 0, tmp_max = 0;
	for (int i = 0; i < neigh[cur].size(); i++) {
		int to = neigh[cur][i];
		if (to == fa)
			continue;

		tmp = dfs(to, cur);
		tmp_max = max(tmp_max, tmp);
		node_num += tmp;
	}//for int i

	tmp_max = max(tmp_max, N - node_num);
	if (ans_num > tmp_max) {
		ans_num = tmp_max;
		ind = cur;
	}
	
	return node_num;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int kasenum = 0;
	cin >> kasenum;
	while (kasenum--) {

		for (int i = 0; i < maxn; i++)
			neigh[i].clear();
		
		cin >> N;
		for (int i = 0; i < N - 1; i++) {
			int a, b;
			cin >> a >> b;
			neigh[a].push_back(b);
			neigh[b].push_back(a);
		}

		ans_num = 0x3f3f3f;
		dfs(1, 0);
		cout << ind << " " << ans_num << endl;
	}//while

	return 0;
}