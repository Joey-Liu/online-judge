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

using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;

const int maxn = 2000 + 10;
int nums[maxn], N;
map<int, vector<int>> tab;

int func(const vector<int>& vi, int a, int b) {
	int ind_1 = lower_bound(vi.begin(), vi.end(), a) - vi.begin();
	int cnt_left = ind_1;

	int ind_2 = upper_bound(vi.begin(), vi.end(), b) - vi.begin();
	int cnt_right = vi.size() - ind_2;
	int t = min(cnt_left, cnt_right);
	t = max(t, 0);
	return t * 2;
}

int work() {
	int res_length = 1;
	for (auto it = tab.begin(); it != tab.end(); it++) {
		int x = it->first;
		vector<int> vi = it->second;
		
		for (int st = 0; st < vi.size(); st++) {
			for (int ed = st; ed < vi.size(); ed++) {
				for (auto tj = tab.begin(); tj != tab.end(); tj++) {
					int y = tj->first;
					/*if (x == y) {
						continue;
					}*/
					vector<int> jv = tj->second;
					int cnt_y = func(jv, vi[st], vi[ed]);
					int cnt_x = ed - st + 1;
					res_length = max(res_length, cnt_x + cnt_y);
				}
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