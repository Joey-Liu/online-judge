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

const LL inf = INT_MAX;
const LL maxn = 10000000 + 5;
LL A, B, total, K;
bool in_set[maxn];

LL up_bound() {
	LL lp = 0, rp = inf;
	while (lp < rp) {
		LL mid = lp + (rp - lp) / 2;
		if (mid * (mid + 1) <= 2 * total) {
			lp = mid + 1;
		}
		else {
			rp = LL(mid);
		}
	}

	return lp;
}


void work() {
	LL mini = min(A, B), tk = K, small_size = 0;
	while (mini >= tk && mini) {
		in_set[tk] = true;
		mini -= tk;
		--tk; ++small_size;
	}

	if (mini != 0) {
		in_set[mini] = true;
		small_size++;
	}

	LL big_size = K - small_size;
	if (A < B) {
		cout << small_size << endl;
		for (LL i = 0; i <= K; i++) {
			if (in_set[i])
				cout << i << " ";
		}
		cout << endl;
		cout << big_size << endl;
		for (LL i = 1; i <= K; i++) {
			if (!in_set[i])
				cout << i << " ";
		}
	}
	else {
		cout << big_size << endl;
		for (LL i = 1; i <= K; i++) {
			if (!in_set[i])
				cout << i << " ";
		}
		cout << endl;
		cout << small_size << endl;
		for (LL i = 0; i <= K; i++) {
			if (in_set[i])
				cout << i << " ";
		}
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	memset(in_set, false, sizeof(in_set));
	cin >> A >> B;
	total = A + B;
	if (!total) {
		cout << 0 << endl << endl << 0 << endl;
		return 0;
	}

	K = up_bound() - 1;
	work();

	return 0;
}