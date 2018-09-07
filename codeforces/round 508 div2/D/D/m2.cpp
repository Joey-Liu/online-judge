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

typedef long long LL;

using namespace std;

const int maxn = 500000 + 50;
int N;
LL A[maxn];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	cin >> N;
	bool has_pos = false, has_neg = false;
	LL res = 0;
	LL mini = INT_MAX;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		if (N == 1) {
			cout << A[0] << endl;
			return 0;
		}
		if (A[i] <= 0) {
			has_neg = true;
			A[i] = -A[i];
		}
		else if (A[i] > 0) {
			has_pos = true;
		}

		res += A[i];
		mini = min(mini, A[i]);
	}

	if (has_pos && has_neg) {
		cout << res << endl;
	}
	else {
		cout << res - 2 * mini << endl;
	}

	return 0;
}