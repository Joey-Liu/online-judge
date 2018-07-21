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
const int maxn = 1000000 + 50;

int N, nums[maxn], sorted[maxn], len;


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

	memcpy(sorted, nums, sizeof(nums));
	sort(sorted, sorted + N);
	len = unique(sorted, sorted + N) - sorted;
	map<int, int> tab;


	int i = 0, j = 0, ind, ans = INT_MAX;
	ind = lower_bound(sorted, sorted + len, nums[0]) - sorted;
	tab[ind]++;

	while (j < N) {
		if (tab.size() == len) {
			ans = min(ans, j - i + 1);
			ind = lower_bound(sorted, sorted + len, nums[i]) - sorted;
			tab[ind]--;
			if (!tab[ind])
				tab.erase(ind);
			i++;
		}
		else {
			j++;
			if (j < N) {
				ind = lower_bound(sorted, sorted + len, nums[j]) - sorted;
				tab[ind]++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}