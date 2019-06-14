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
	int T;
	cin >> T;
	while (T--) {
		int res[3] = { 0 }, N, tmp;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> tmp;
			res[tmp % 3]++;
		}
		int ans = res[0];
		ans += min(res[1], res[2]);
		if (res[1] >= res[2]) {
			ans += (res[1] - res[2]) / 3;
		}
		else {
			ans += (res[2] - res[1]) / 3;
		}
		cout << ans << endl;
	}
	return 0;
}