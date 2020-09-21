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

bool dfs(int cur, int N, map<int, int>& tab, vector<int>& vi, const vector<int> & finger) {
	if (cur == N) {
		return true;
	}

	int target = finger[cur - 1] - vi[cur - 1];
	if (!tab.count(target) || tab[target] <= 0) {
		return false;
	}
	
	vi[cur] = target;
	tab[target] -= 1;
	return dfs(cur + 1, N, tab, vi, finger);
}

bool the_same(const vector<int>& v1, const vector<int>& v2) {
	for (int i = 0; i < v1.size(); i++) {
		if (v1[i] != v2[i]) {
			return false;
		}
	}
	return true;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int kasenum = 0;
	cin >> kasenum;
	while (kasenum--) {
		int N;
		cin >> N;
		vector<int> arr(N, 0);
		map<int, int> tab;
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
			tab[arr[i]] += 1;
		}

		vector<int> yh(N - 1, 0);
		for (int i = 0; i + 1 < N; i++) {
			yh[i] = arr[i] + arr[i + 1];
		}
		sort(yh.begin(), yh.end());

		vector<int> res(N, 0);
		for (int i = 0; i < N; i++) {
			
			if (arr[i] > yh[0]) {
				continue;
			}
			res[0] = arr[i];
			map<int, int> mii = tab;
			mii[res[0]] -= 1;
			if (dfs(1, N, mii, res, yh) && !the_same(arr, res)) {
				break;
			}
		}

		for (int i = 0; i < N; i++) {
			cout << res[i] << " ";
		}
		cout << endl;

	}//while


	return 0;
}