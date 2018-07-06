#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

const int maxn = 1000000 + 50;
int N, M, nums[maxn];

int partition(int lp, int rp) {
	int piv = nums[rp];
	int x = lp, y = rp;
	
	while (x < y) {
		while (x < y && nums[x] <= piv)
			x++;
		swap(nums[y], nums[x]);
		while (x < y && nums[y] > piv)
			y--;
		swap(nums[x], nums[y]);
	}
	return x;
}

void quick_sort(int lp, int rp) {
	if (lp >= rp) {
		return;
	}

	int pos = partition(lp, rp);
	quick_sort(lp, pos - 1);
	quick_sort(pos + 1, rp);
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	while(cin >> N >> M) {
		for (int i = 0; i < N; i++) {
			cin >> nums[i];
		}
		quick_sort(0, N - 1);
		sort(nums, nums + N);
		for (int i = 0; i < M - 1; i++) {
			cout << nums[N - 1 - i]<<" ";
		}
		cout << nums[N - M]<<endl;
	}
	return 0;
}