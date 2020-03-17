#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;
const int maxn = 200000 + 20;

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int kasenum, N, P, K;
    int A[maxn], dp[maxn];
    cin >> kasenum;
    while (kasenum--) {
        cin >> N >> P >> K;
        for (int i = 1; i <= N; i++) {
            cin >> A[i];
        }
        sort(A + 1, A + N + 1);
        memset(dp, 0x3f, sizeof(dp));
        dp[0] = 0;

        for (int i = 1; i < K; i++) {
            dp[i] = A[i] + dp[i - 1];
        }

        for (int i = K; i <= N; i++) {
            dp[i] = A[i] + dp[i - K];
        }

        int res = 0;
        for (int i = N; i >= 1; i--) {
            if (dp[i] <= P) {
                res = i;
                break;
            }
        }
        cout << res << endl;
    }// while
    return 0;
}