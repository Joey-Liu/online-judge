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
	int kasenum;
	cin >> kasenum;
	while (kasenum--) {
		int N, sum = 0, amx = -1;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> nums[i];
			sum += nums[i];
			amx = max(amx, nums[i]);
		}

		string res = "HL";
		if (N == 1) {
			res = "T";
		}
		if (sum % 2) {
			res = "T";
		}
		if (amx > sum / 2) {
			res = "T";
		}
		cout << res << endl;

	}

	return 0;
}