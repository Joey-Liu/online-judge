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
int kasenum, N, nums[maxn];

bool vertify(int ta, const vector<int>& vi) {
	int rest = vi.size();
	if (vi.back() == ta) {
		rest -= 1;
	}
	return rest >= ta;
}


int work(const vector<int>& vi) {
	int rp = vi.back(), lp = 1;
	while (lp < rp) {
		int mid = lp + (rp - lp) / 2;
		if (vertify(mid, vi)) {
			lp = mid + 1;
		}
		else {
			rp = mid;
		}
	}// while
	if (vertify(lp, vi)) {
		return lp;
	}
	return lp - 1;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> kasenum;
	while (kasenum--) {
		map<int, int> tab;
		tab.clear();

		cin >> N;
		for (int i = 0; i < N; i++) {
			int tmp;
			cin >> tmp;
			tab[tmp] += 1;
		}

		vector<int> vi;
		for (auto it = tab.begin(); it != tab.end(); ++it) {
			vi.emplace_back(it->second);
		}
		sort(vi.begin(), vi.end());
		int res = work(vi);
		cout << res << endl;

	}// while


	return 0;
}