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
	int kasenum;
	cin >> kasenum;
	while (kasenum--) {
		int x, n, m;
		cin >> x >> n >> m;
		
		while (n) {
			int tmp = x / 2 + 10;
			int hurt = x - tmp;
			if (hurt <= 0) {
				break;
			}
			x = tmp;
			n--;
		}
		x -= 10 * m;
		if (x <= 0) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}

	}

	return 0;
}