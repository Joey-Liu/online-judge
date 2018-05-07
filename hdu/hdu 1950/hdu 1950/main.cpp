#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <memory.h>

using namespace std;

const int maxn = 40000 + 10;
int nums[maxn], en[maxn], K, N;

int bi_search(int lp, int rp, int tar)
{
	int mid;
	while (lp < rp) {
		mid = lp + (rp - lp) / 2;
		if (en[mid] >= tar) {
			rp = mid;
		}
		else {
			lp = mid + 1;
		}
	}
	return lp;
}

void work()
{
	memset(en, 0, sizeof(en));
	K = 1;
	en[0] = nums[0];
	for (int i = 1; i < N; i++) {
		int ind = bi_search(0, K, nums[i]);
		en[ind] = nums[i];
		if (ind == K)
			K++;
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int kasenum;
	cin >> kasenum;
	while (kasenum--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> nums[i];
		}
		work();
		cout << K << endl;
	}
	return 0;
}