#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 10000;
int nu[] = { 0, 3, 1, 2, 3,3,3,4,4, 34, 78, 9, 7 }, N = sizeof(nu) / sizeof(int) - 1;
int en[maxn], K;

int bi_lower(int lp, int rp, int tar) 
{
	int mid;
	while (lp < rp) {
		mid = lp + (rp - lp) / 2;
		if (en[mid] >= tar)
			rp = mid;
		else
			lp = mid + 1;
	}
	return lp;
}

int bi_upper(int lp, int rp, int tar)
{
	int mid;
	while (lp < rp) {
		mid = lp + (rp - lp) / 2;
		if (en[mid] > tar)
			rp = mid;
		else
			lp = mid + 1;
	}
	return lp;
}

void work()
{
	en[1] = nu[1];
	K = 1;
	for (int i = 2; i <= N; i++) {
		int ind = bi_upper(1, K + 1 , nu[i]);
		en[ind] = nu[i];
		K = max(ind, K);
	}
	cout << K << endl;
}

int main()
{
	work();
	cin >> N;
	return 0;
}