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
		int n, x, a, b;
		cin >> n >> x >> a >> b;
		int c = a - b > 0 ? a - b : b - a;
		int ans = min(n - 1, c + x);
		cout << ans << endl;
	}

	return 0;
}