#include <iostream>
#include <memory.h>
#include <vector>
#include <algorithm>

using namespace std;
const int maxn = 500 + 10;
struct Node {
	int dest, st, eti, cost;
};

int N, M;
vector<Node> vn[maxn];

bool visited[maxn];

int dfs(int posi, int backup, int tim) {
	if (posi == N)
		return 0;

	if (!backup) {
		int ans = -1;
		for (int i = 0; i < (int)vn[posi].size(); i++) {
			if (tim >= vn[posi][i].st || visited[vn[posi][i].dest])
				continue;
			
			int dest = vn[posi][i].dest;
			//visited[dest] = true;
			int t = dfs(dest, backup, vn[posi][i].eti);
			//visited[dest] = false;

			if (t >= 0) {
				int tmp = t + vn[posi][i].cost;
				if (ans < 0)
					ans = tmp;
				ans = min(ans, tmp);
			}
		}
		return ans;
	}//if
	else {
		int i, j, ans = -1;
		for (i = 0; i < (int)vn[posi].size(); i++) {
			if (tim >= vn[posi][i].st || visited[vn[posi][i].dest])
				continue;
			int st = vn[posi][i].st;
			
			//visited[vn[posi][i].dest] = true;
			int c1 = dfs(vn[posi][i].dest, true, vn[posi][i].eti);
			//visited[vn[posi][i].dest] = false;
			if (c1 < 0)
				continue;

			for (j = 0; j < (int)vn[posi].size(); j++) {
				if (i == j)
					continue;
				if (visited[vn[posi][j].dest])
					continue;

				int st2 = vn[posi][j].st;
				if (st >= st2)
					continue;
				
				//visited[vn[posi][j].dest] = true;
				int c2 = dfs(vn[posi][j].dest, false, vn[posi][j].eti);
				//visited[vn[posi][j].dest] = false;

				if (c2 < 0)
					continue;
				if (ans == -1) {
					ans = max(c1 + vn[posi][i].cost, c2 + vn[posi][j].cost);
				}
				else {
					ans = min(ans, max(c1 + vn[posi][i].cost, c2 + vn[posi][j].cost));
				}
			}
		}
		return ans;
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		int t1, t2;
		char ch;
		cin >> t1 >> ch >> t2;
		int st = t1 * 2 + (t2 == 30 ? 1 : 0);
		cin >> t1 >> ch >> t2;
		int eti = t1 * 2 + (t2 == 30 ? 1 : 0);
		
		Node no;
		no.dest = b; no.cost = c; no.st = st; no.eti = eti;
		vn[a].push_back(no);
	}

	memset(visited, false, sizeof(visited));
	//visited[1] = true;
	int ans = dfs(1, true, -1);
	if (ans < 0)
		cout << -1 << endl;
	else
		cout << ans << endl;
	return 0;
}