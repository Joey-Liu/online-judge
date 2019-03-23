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
	
	int kasenum = 0;
	cin >> kasenum;
	while (kasenum--) {
		LL n, a, b;
		cin >> n >> a >> b;
		if (a * 2 <= b) {
			cout << n * a << endl;
		}
		else {
			LL res = n / 2 * b;
			if (n % 2)
				res += a;
			cout << res << endl;
		}

	}//while

	return 0;
}