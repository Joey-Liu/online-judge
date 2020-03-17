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


	int casenum;
	cin >> casenum;
	while (casenum--) {
		LL a, b, z;
		cin >> a >> b >> z;
		double x = (z + b - a) / 2.0;
		if (x > z) {
			cout << 0 << endl;
		}
		else {
			LL res = 0;
			if (x < 0) {
				x = 0;
				res++;
			}
			res += LL(ceil(z - x));
			cout << res << endl;
		}
	}


	return 0;
}