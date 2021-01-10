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

const int maxn = 100000 + 10;
int nums[maxn];
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, 1, 0, -1 };

int trans(char c) {
	int n = -1;
	switch (c) {
	case 'U':
		n = 0;
		break;
	case 'R':
		n = 1;
		break;
	case 'D':
		n = 2;
		break;
	case 'L':
		n = 3;
		break;
	}
	return n;
}

bool test_route(const string& order, PII stone) {
	int cur_row = 0, cur_col = 0;
	for (int i = 0; i < order.size(); i++) {
		int ind = trans(order[i]);
		int nxt_row = cur_row + dr[ind];
		int nxt_col = cur_col + dc[ind];
		if (nxt_row == stone.first && nxt_col == stone.second) {
			continue;
		}
		cur_row = nxt_row;
		cur_col = nxt_col;
	}

	return (cur_row == 0 && cur_col == 0);
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
		string order;
		cin >> order;
		int N = order.size();
		set<PII> spii;
		int cur_row = 0, cur_col = 0;

		for (int i = 0; i < N; i++) {
			int ind = trans(order[i]);
			cur_row += dr[ind];
			cur_col += dc[ind];
			spii.emplace(make_pair(cur_row, cur_col));
		}

		bool flag = false;
		PII sol = {0, 0};
		for (auto it = spii.begin(); it != spii.end(); ++it) {
			if (test_route(order, *it)) {
				flag = true;
				sol = *it;
			}
		}
		
		cout << sol.second << " " << -sol.first << endl;

	}//while

	return 0;
}