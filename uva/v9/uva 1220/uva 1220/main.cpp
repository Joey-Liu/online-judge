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
const int maxn = 200 + 50;

vector<int> sons[maxn];
vector<string> vs;
map<string, int> tab;
int N, dp[maxn][2], f[maxn][2];

int get_id(string str) {
	if (tab.count(str))
		return tab[str];

	tab[str] = vs.size();
	vs.push_back(str);
	return tab[str];
}


int work(int cur, int status) {
	if (dp[cur][status] != -1)
		return dp[cur][status];

	int ans = 0;
	if (status == 1) {
		ans += 1;
		f[cur][status] = 1;
		for (int i = 0; i < sons[cur].size(); i++) {
			ans += work(sons[cur][i], 0);
			if (!f[sons[cur][i]][0])
				f[cur][status] = 0;
		}
		return dp[cur][status] = ans;
	}
	else {
		f[cur][status] = 1;
		for (int i = 0; i < sons[cur].size(); i++) {
			int n0 = work(sons[cur][i], 0), n1 = work(sons[cur][i], 1);
			ans += max(n0, n1);
			
			if (n0 == n1)
				f[cur][status] = 0;
			if(n0 > n1 && !f[sons[cur][i]][0])
				f[cur][status] = 0;
			if (n1 > n0 && !f[sons[cur][i]][1])
				f[cur][status] = 0;
		}

		return dp[cur][status] = ans;
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (cin >> N && N) {
		vs.clear();
		tab.clear();
		for (int i = 0; i < maxn; i++)
			sons[i].clear();

		string s1, s2;
		cin >> s1; get_id(s1);

		for (int i = 0; i < N - 1; i++) {
			cin >> s1 >> s2;
			int a = get_id(s1), b = get_id(s2);
			sons[b].push_back(a);
		}

		memset(dp, -1, sizeof(dp));
		memset(f, -1, sizeof(f));

		int n0 = work(0, 0), n1 = work(0, 1);
		cout << max(n0, n1) << " ";

		if (n0 == n1) {
			cout << "No" << endl;
		}
		else {
			int status = n0 > n1 ? 0 : 1;
			if (f[0][status]) {
				cout << "Yes" << endl;
			}
			else {
				cout << "No" << endl;
			}
		}
	}//while


	return 0;
}