#include <iostream>
#include <memory.h>
#include <memory>

using namespace std;

const int maxn = 50000 + 10;

int nums[maxn], N, pre[maxn];
int dp[maxn][maxn];

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    while (cin >> N && N) {
        memset(nums, 0, sizeof(nums));
        memset(dp, 0, sizeof(dp));
        memset(pre, 0, sizeof(pre));
        for (int i = 1; i <= N; i++) {
            cin >> nums[i];
            pre[i] = pre[i - 1] + nums[i];
        }

        for (int len = 2; len <= N; len++) {
            for (int st = 1; st + len - 1 <= N; st++) {
                int ed =  st + len - 1;
                for (int k = st; k < ed; k++) {
                    int left_weight = pre[k] - pre[st - 1];
                    int right_weight = pre[ed] - pre[k];
                    int tmp = dp[st][k] + dp[k + 1][ed] + left_weight + right_weight;
                    if (0 == dp[st][ed]) {
                        dp[st][ed] = tmp;
                    }
                    dp[st][ed] = min(tmp, dp[st][ed]);
                }
            }
        }
        cout << dp[1][N] << endl;

    }// while
    return 0;
}