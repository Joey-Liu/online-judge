#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>

using namespace std;
const int maxn = 100000 + 50;

int N, M;
int cost[505], val[505], dp[maxn];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> cost[i] >> val[i];
	}

	for (int i = M; i >= cost[N - 1]; i--) {
		dp[i] = val[N - 1];
	}

	for (int i = N - 2; i >= 0; i--) {
		for (int j = M; j >= cost[i]; j--) {
			dp[j] = max(dp[j], dp[j - cost[i]] + val[i]);
		}
	}

	cout << dp[M] << endl;
	return 0;
}