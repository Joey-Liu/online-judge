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
#include <math.h>
#include <functional>
#include <limits.h>
#include <unordered_map>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;

const int maxn = 2000 + 10;
int nums[maxn], N;
unordered_map<int, vector<int>> tab;

int func(const vector<int>& vi, int a, int b) {
	int ind_1 = upper_bound(vi.begin(), vi.end(), a) - vi.begin();
	
	int ind_2 = lower_bound(vi.begin(), vi.end(), b) - vi.begin();
	int cnt = ind_2 - ind_1;
	
	return cnt;
}

int work() {
	int res_length = 1;
	for (auto it = tab.begin(); it != tab.end(); ++it) {
		int x = it->first;
		vector<int> & vi = it->second;
		res_length = max(res_length, int(vi.size()));

		for (int side_cnt = 1; side_cnt * 2 <= vi.size(); side_cnt++) {
			int lp = vi[side_cnt - 1];
			int rp = vi[vi.size() - side_cnt];
			
			for (auto jt = tab.begin(); jt != tab.end(); ++jt) {
				vector<int> & vj = jt->second;
				int y = jt->first;
				if (x == y) {
					continue;
				}

				int tmp = func(vj, lp, rp);
				int ans = tmp + side_cnt * 2;
				res_length = max(res_length, ans);
			}

		}

	}// for auto it
	return res_length;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int kasenum;
	cin >> kasenum;
	while (kasenum--) {
		tab.clear();
		cin >> N;
		for (int i = 0; i < N; i++) {
			int tmp;
			cin >> tmp;
			tab[tmp].emplace_back(i);
		}

		int res = work();
		cout << res << endl;

	}

	return 0;
}