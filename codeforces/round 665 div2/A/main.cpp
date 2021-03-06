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
	int kasenum, A, K;
	cin >> kasenum;
	while (kasenum--) {
		cin >> A >> K;
		int C = A - K;
		if (C <= 0) {
			cout << -C << endl;
		}
		else {
			if (C % 2) {
				cout << 1 << endl;
			}
			else {
				cout << 0 << endl;
			}
		}
	}
	return 0;
}