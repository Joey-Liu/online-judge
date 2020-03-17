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

const int maxn = 200000 + 10;
int nums[maxn], N;


int bisearch(int tar, int lp, int rp) {
	while (lp < rp) {
		int mid = lp + (rp - lp) / 2;
		if (nums[mid] > tar) {
			rp = mid;
		}
		else {
			lp = mid + 1;
		}
	}
	return lp;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}
	sort(nums, nums + N);

	int res = -1;
	for (int i = 0; i < N; i++) {
		if (i == 0 || nums[i - 1] != nums[i]) {
			int ind = bisearch(nums[i] + 5, 0, N);
			res = max(res, ind - i);
		}// if
	}//for int i
	cout << res << endl;
	return 0;
}