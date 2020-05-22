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
#include <iomanip>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;

const int maxn = 200 + 10;
int nums[maxn];
double x[maxn], y[maxn];


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N;
	while (cin >> N && N) {
		for (int i = 0; i < N; i++) {
			cin >> x[i] >> y[i];
		}

		double res = 0;
		for (int i = 0; i < N; i++) {
			int nxt = (i + 1) % N;
			double tmp = x[i] * y[nxt] - x[nxt] * y[i];
			res += tmp;
		}
		res /= 2;
		res = abs(res);
		cout << fixed << setprecision(1) << res << endl;
	}


	return 0;
}