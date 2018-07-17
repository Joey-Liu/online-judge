#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

const int maxn = 10000 + 50;
const int inf = 0x3f3f3f3f;
int E, F, W, dp[maxn], weight[maxn], val[maxn], N;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int kasenum;
	cin >> kasenum;
	while (kasenum--) {
		cin >> E >> F;
		W = F - E;

		memset(dp, 0x3f, sizeof(dp));
		dp[0] = 0;

		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> val[i] >> weight[i];

		for (int i = 0; i <= W; i++) {
			for (int j = 0; j < N; j++) {
				if (i < weight[j])
					continue;
				dp[i] = min(dp[i], dp[i - weight[j]] + val[j]);
			}//for int j
		}//for int i

		if (dp[W] == inf)
			cout << "This is impossible." << endl;
		else {
			cout << "The minimum amount of money in the piggy-bank is " << dp[W] << ".\n";
		}
	}
	return 0;
}