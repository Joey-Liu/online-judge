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


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int kasenum, a;
	cin >> kasenum;
	while (kasenum--) {
		cin >> a;
		int ones = 0;
		for (int i = 0; i <= 30; i++) {
			if ((1 << i) & a) {
				ones++;
			}
		}

		if (!ones) {
			cout << 1 << endl;
		}
		else {
			cout << (1 << ones) << endl;
		}

	}

	return 0;
}