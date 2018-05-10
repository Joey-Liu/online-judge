#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <iomanip>
#include <memory.h>
#include <queue>


using namespace std;
queue<int> que;

const int maxn = 30;
double weight[maxn], R, res;
double lw[maxn], rw[maxn];

int S, wei_num;
bool visited[maxn], flag;


void dfs(int layer, double cur_width)
{
	if (layer == S - 1) {
		if (cur_width > res) {
			res = cur_width;
			flag = true;
		}
		return;
	}

	for (int i = 0; i < wei_num; i++) {
		if (visited[i])
			continue;
		
		for (int j = 0; j < wei_num; j++) {
			if (i == j || visited[j])
				continue;
			double lf = max(lw[i], lw[j] - 1);
			double rf = max(rw[j], rw[i] - 1);

			if (lf + rf + 1 > R)
				continue;

			weight[wei_num] = weight[i] + weight[j];
			lw[wei_num] = lf + weight[j] / weight[wei_num];
			rw[wei_num] = rf + weight[i] / weight[wei_num];
			wei_num++;
			visited[i] = true;
			visited[j] = true;
			
			dfs(layer + 1, lf + rf + 1);
			
			wei_num--;
			visited[i] = false;
			visited[j] = false;

		}//for int j
	}//for int i
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int kasenum;
	cin >> kasenum;
	while (kasenum--) {
		cin >> R >> S;
		for (int i = 0; i < S; i++) {
			cin >> weight[i];
		}

		memset(visited, false, sizeof(visited));
		memset(lw, 0, sizeof(lw));
		memset(rw, 0, sizeof(rw));
		flag = false;
		wei_num = S;
		res = -1;

		dfs(0, 0);
		if( res >= 0) {
			cout.setf(ios::fixed);
			cout << setprecision(10) << res << endl;
		}
		else
			cout << -1 << endl;
	}
	return 0;
}