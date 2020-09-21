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
		LL n, x, y, d = -1;
		cin >> n >> x >> y;
		LL diff = y - x;
		if (diff + 1 <= n) {
			d = 1;
		}
		else {
			for (int i = 2; i <= diff; i++) {
				if (diff % i == 0 && diff / i + 1 <= n) {
					d = i;
					break;
				}
			}
		}

		
		LL k = (y - x) / d + 1;
		LL left = n - k;
		LL p = min(x / d, left);
		LL begin = x - p * d;
		if (begin <= 0) {
			begin += d;
		}
		for (int i = 0; i < n; i++) {
			cout << begin + i * d << " ";
		}
		cout << endl;


	}
	return 0;
}