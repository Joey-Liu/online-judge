#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <memory.h>

using namespace std;

const int maxn = 100000 + 10;

int par[maxn];
int find_par(int k) {
	if (-1 == par[k]) {
		return k;
	}
	else {
		return par[k] = find_par(par[k]);
	}
}

void join(int p, int q) {
	int x = find_par(p);
	int y = find_par(q);
	if(x != y)
		par[x] = y;
}

int N, M;
int nums[maxn], a, b;
vector<set<int> > vse;
vector<int> idx[maxn];
vector<int> nu[maxn];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;

	memset(par, -1, sizeof(par));
	for (int i = 1; i <= N; i++) {
		cin >> nums[i];
	}
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		join(a, b);
	}

	for (int i = 1; i <= N; i++) {
		idx[find_par(i)].push_back(i);
		nu[find_par(i)].push_back(nums[i]);
	}

	int res = 0;
	for (int i = 1; i <= N; i++) {
		if (idx[i].size() != 0) {
			sort(idx[i].begin(), idx[i].end());
			sort(nu[i].begin(), nu[i].end());
			int x = 0, y = 0;
			while (x < idx[i].size() && y < nu[i].size()) {
				if (idx[i][x] == nu[i][y]) {
					x++;
					y++;
					res++;
				}
				else if (idx[i][x] > nu[i][y]) {
					y++;
				}
				else {
					x++;
				}
			}//while
		}
	}

	cout << res << endl;
	return 0;
}