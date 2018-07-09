#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <memory.h>
#include <algorithm>

using namespace std;
typedef long long LL;

const int maxn = 1000000 + 50;

LL nums[maxn], dp[maxn], pd[maxn];
LL N, A, B;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	cin >> N >> A >> B;
	for (int i = 0; i < N; i++)
		cin >> nums[i];

	dp[0] = nums[0];
	pd[0] = nums[0];
	for (int i = 1; i < N; i++) {
		dp[i] = max(nums[i], dp[i - 1] + nums[i]);
		pd[i] = min(nums[i], pd[i - 1] + nums[i]);
	}

	LL ans = dp[0] * A;
	for (int i = 0; i < N; i++) {
		ans = max(dp[i] * A, ans);
		ans = max(pd[i] * A, ans);
	}
	cout << ans + B << endl;

	return 0;
}