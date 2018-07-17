#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

typedef long double LD;
const int maxn = 5000 + 10;


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int N, K;
	double nums[maxn], pre_sum[maxn];
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		cin >> nums[i];
	
	pre_sum[0] = 0;
	for (int i = 1; i <= N; i++) {
		pre_sum[i] = pre_sum[i - 1] + nums[i];
	}

	double ans = 0.0, tmp;
	for (int len = K; len <= N; len++) {
		for (int i = 1; i <= N - len + 1; i++) {
			int j = i + len - 1;
			if (j > N)
				continue;
			tmp = pre_sum[j] - pre_sum[i] + nums[i];
			ans = max(ans, tmp / len);
		}
	}
	printf("%.8llf\n", ans);
	return 0;
}