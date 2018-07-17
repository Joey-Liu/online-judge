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

using namespace std;

typedef long long LL;

const int maxn = 1000000 + 20;
const int mod = 1e9 + 7;
int N;

bool is_prime[maxn];
LL dp[maxn];

int work(int num) {
	
	if (dp[num] != -1)
		return dp[num];

	if (is_prime[num] || num == 1) {
		return dp[num] = 1;
	}

	LL ans = 1;
	for (int i = 2; i <= num / 2; i++) {
		if (0 == num % i) {
			ans = (ans + work(num / i)) % mod;
		}
	}

	return dp[num] = ans;
}


void init() {

	memset(is_prime, true, sizeof(is_prime));
	is_prime[0] = false;
	is_prime[1] = false;

	for (int i = 2; i < maxn; i++) {
		if (!is_prime[i])
			continue;

		for (int j = 2; j * i < maxn; j++) {
			is_prime[j * i] = false;
		}
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> N;

	init();
	memset(dp, -1, sizeof(dp));

	LL ans = work(N);

	cout << ans << endl;
	return 0;
}