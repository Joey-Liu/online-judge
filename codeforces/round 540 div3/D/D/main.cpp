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

const int maxn = 200000+ 50;
LL M, N, A[maxn], sum_caff = 0;


bool cmp(int a, int b) {
	return a > b;
}

bool func(int k) {
	LL res = 0, ind = 0;
	while (ind < N && res < M) {
		res += A[ind];
		res -= ind / k;
		ind++;
	}//while
	return res >= M;
}

int work() {
	int lp = 1, rp = N + 1;
	while (lp < rp) {
		int mid = lp + (rp - lp) / 2;
		if (func(mid)) {
			rp = mid;
		}
		else {
			lp = mid + 1;
		}
	}//while
	return lp;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
		sum_caff += A[i];
	}
	sort(A, A + N, cmp);
	if (sum_caff < M) {
		cout << -1 << endl;
	}
	else {
		int res = work();
		cout << res << endl;
	}
	
	return 0;
}