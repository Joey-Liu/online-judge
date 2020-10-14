#include <iostream>
#include <algorithm>
#include <memory.h>
#include <memory>

using namespace std;

const int maxn = 2e5 + 200;
int X[maxn], Y[maxn];
int dp[maxn];

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int kasenum, N, K;
    cin >> kasenum;
    while (kasenum--) {
        cin >> N >> K;
        for (int i = 0; i < N; i++) {
            cin >> X[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> Y[i];
        }

        sort(X, X + N);
        memset(dp, 0, sizeof(dp));


        for (int i = N - 1; i >= 0; i--) {
            int left_bord = X[i];
            int right_bord = left_bord + K;
            int jnd = upper_bound(X, X + N, right_bord) - X;
            int ind = lower_bound(X, X + N, left_bord) - X;
            int tmp = jnd - ind;
            dp[i] = max(dp[i + 1], tmp);
        }

        int res = -1;
        for (int i = 0; i < N; i++) {
            int left_bord = X[i];
            int right_bord = left_bord + K;
            int ind = upper_bound(X, X + N, right_bord) - X;
            int cnt1 = ind - i;
            if (ind >= N) {
                res = max(cnt1, res);
            } else {
                res = max(cnt1 + dp[ind], res);
            }
        }
        cout << res << endl;

    }

    return 0;
}