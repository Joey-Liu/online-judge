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

const int maxn = 1000 + 50;

int N, nums[maxn], heater[maxn], R;

int work(int cur) {
	int rp = min(N - 1, cur + R - 1);
	int ind = rp;

	while (ind >= cur && nums[ind] == 0)
		ind--;
	if (ind >= cur) {
		return ind + R;
	}

	while (ind >= max(cur - R + 1, 0) && nums[ind] == 0) {
		ind--;
	}
	if (ind >= max(cur - R + 1, 0)) {
		return ind + R;
	}

	return -1;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	
	cin >> N >> R;
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}

	int ind = 0, res = 0;
	while (ind < N) {
		int t = work(ind);
		if (t < 0) {
			cout << -1 << endl;
			return 0;
		}
		else {
			res += 1;
			ind = t;
		}
	}//
	cout << res << endl;

	return 0;
}