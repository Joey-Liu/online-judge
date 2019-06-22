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
typedef pair<LL, int> PII;

const int maxn = 100000 + 10;
const int inf = 0x3f3f3f3f;
LL nums[maxn];
PII pii[maxn];
int N, K, target;

LL myabs(LL n) {
	return n > 0 ? n : -n;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	while (cin >> N >> K) {
		if (!N && !K)
			break;
		for (int i = 0; i < N; i++) {
			cin >> nums[i];
		}//for int i
		memset(pii, 0, sizeof(pii));

		for (int i = 1; i <= N; i++) {
			pii[i].second = i;
			pii[i].first = pii[i - 1].first + nums[i - 1];
		}
		sort(pii, pii + N + 1);

		while (K--) {
			cin >> target;
			LL diff = inf, res = inf;
			
			int st = 0, ed = 1, lp = 0, rp = 1;
			LL ts = pii[ed].first - pii[st].first;
			while (ed <= N) {
				ts = pii[ed].first - pii[st].first;
				LL tmp = myabs(ts - target);

				if (tmp < diff) {
					lp = st, rp = ed;
					diff = tmp;
					res = ts;
				}
				if (tmp == 0)
					break;
				if (ts > target) {
					st++;
				}
				if (ts < target) {
					ed++;
				}
				if (st == ed) {
					ed++;
				}

			}//while ed <= N
			int p = pii[lp].second, q = pii[rp].second;
			if (p > q) {
				swap(p, q);
			}
			cout <<res<<" "<< p + 1 << " " << q << endl;
		}//while K


	}//while
	return 0;
}