#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

using namespace std;
typedef long long LL;
const int maxn = 500000 + 50;

int A[maxn], T[maxn], N;
LL res = 0;

void merge_sort(int lp, int rp)
{
	if (rp - lp <= 1)
		return;

	int mid = lp + (rp - lp) / 2;
	merge_sort(lp, mid);
	merge_sort(mid, rp);

	int x = lp, y = mid, ind = lp;
	while (x < mid || y < rp) {
		if (y >= rp || (x < mid && A[x] < A[y])) {
			T[ind++] = A[x++];
		}
		else
		{
			T[ind++] = A[y++];
			res += (mid - x);
		}
	}
	for (int i = lp; i < rp; i++) {
		A[i] = T[i];
	}
}

int main()
{
	while (cin >> N && N) {
		memset(T, 0, sizeof(T));
		for (int i = 0; i < N; i++)
			cin >> A[i];
		res = 0;
		merge_sort(0, N);
		cout << res << endl;
	}
}