#include <iostream>
#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <algorithm>

using namespace std;
typedef long long LL;


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int kase = 0; kase < T; kase++) {
		LL n, s1, v1, s2, v2;
		scanf("%lld%lld%lld%lld%lld", &n, &s1, &v1, &s2, &v2);
		
		if (s1 < s2) {
			swap(s1, s2);
			swap(v1, v2);
		}

		LL ans = 0;
		if (n / s1 > 65535) {
			for (LL i = 0; i < s1; i++) {
				ans = max(ans, i * v2 + (n - i * s2) / s1 * v1);
			}
			for (LL i = 0; i < s2; i++) {
				ans = max(ans, i * v1 + (n - i * s1) / s2 * v2);
			}
		}
		else {
			for (LL i = 0; i*s1 <= n; i++) {
				ans = max(ans, i*v1 + (n - i * s1) / s2 * v2);
			}
		}
		printf("Case #%d: %lld\n", kase + 1, ans);
	}
	return 0;
}