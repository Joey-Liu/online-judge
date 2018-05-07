#include <iostream>
#include <stdio.h>
#include <memory.h>


using namespace std;
const int maxn = 1000 + 10;
int nums[maxn], en[maxn], K, N;

int bi_search(int lp, int rp, int tar) {
	int mid;
	while (lp < rp) {
		mid = lp + (rp - lp) / 2;
		if (en[mid] >= tar) {
			rp = mid;
		}
		else {
			lp = mid + 1;
		}
	}//while lp < rp
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
		if (K == ind)
			K++;
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int kasenum;
	cin >> kasenum;
	bool is_first = true;
	while (kasenum--) {
		if (!is_first)
			cout << endl;
		is_first = false;
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> nums[i];
		work();
		cout << K << endl;
	}
	return 0;
}