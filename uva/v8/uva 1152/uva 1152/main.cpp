#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;
const int maxn = 4000 + 10;
typedef long long LL;

int A[maxn], B[maxn], C[maxn], D[maxn], N;
int ab[maxn * maxn], cd[maxn * maxn], cn_ab, cn_cd;

int low_bound(int arr[], int lp, int rp, int target)
{
	int mid;
	while (lp < rp) {
		mid = lp + (rp - lp) / 2;
		if (arr[mid] >= target)
			rp = mid;
		else
			lp = mid + 1;
	}
	return lp;
}

int up_bound(int arr[], int lp, int rp, int target)
{
	int mid;
	while (lp < rp) {
		mid = lp + (rp - lp) / 2;
		if (arr[mid] <= target)
			lp = mid + 1;
		else
			rp = mid;
	}
	return lp;
}

void work()
{	
	cn_ab = 0; cn_cd = 0;
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			ab[cn_ab++] = A[i] + B[j];
	sort(ab, ab + cn_ab);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cd[cn_cd++] = C[i] + D[j];
	sort(cd, cd + cn_cd);

	LL res = 0;
	for (int i = 0; i < cn_ab; i++) {
		int lb = low_bound(cd, 0, cn_cd, -ab[i]);
		int ub = up_bound(cd, 0, cn_cd, -ab[i]);
		res += ub - lb;
	}
	cout << res << endl;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int kasenum;
	cin >> kasenum;
	bool is_first = true;
	while (kasenum--) {
		if (!is_first)
			cout << endl;
		is_first = false;

		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> A[i] >> B[i] >> C[i] >> D[i];
		}
		work();
	}
}