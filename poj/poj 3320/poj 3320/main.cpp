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

const int maxn = 100000 + 10;
int nums[maxn];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int kasenum, N, S;
	cin >> kasenum;
	while (kasenum--) {
		cin >> N >> S;
		for (int i = 0; i < N; i++)
			cin >> nums[i];
		int st = 0, ed = 1, ts = nums[0], res = maxn;
		while (true) {
			if (ed >= N)
				break;
			while (ed < N && ts < S) {
				ts += nums[ed++];
			}

			while (ts >= S && st < ed) {
				res = min(res, ed - st);
				ts -= nums[st++];
			}
			if (ts >= S)
				break;
		}//while
		if (res == maxn)
			cout << 0 << endl;
		else
			cout << res << endl;
	}

	return 0;
}