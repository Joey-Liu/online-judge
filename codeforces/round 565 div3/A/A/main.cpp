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

LL N, divd[] = {2, 3, 5};

int work() {
	LL res[3] = { 0 };
	for (int i = 0; i < 3; i++) {
		while (N != 1 && 0 == N % divd[i]) {
			N /= divd[i];
			res[i]++;
		}
	}
	if (N != 1)
		return -1;
	else
		return res[0] + 2 * res[1] + res[2] * 3;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int q;
	cin >> q;
	
	while (q--) {
		cin >> N;
		int res = work();
		cout << res << endl;
	}

	return 0;
}