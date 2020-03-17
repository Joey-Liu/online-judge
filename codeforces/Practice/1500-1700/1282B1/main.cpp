#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <memory.h>

using namespace std;
const int maxn = 2e5 + 20;
int N, P, K, A[maxn], dp[maxn];

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int kasenum;
    cin >> kasenum;
    while (kasenum--) {
        cin >> N >> P >> K;
        memset(A, 0, sizeof(A));
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        sort(A, A + N);
        for (int i = 0; i < 2; i++) {
            dp[i] = A[i];
        }

        for (int i = 2; i < N; i++) {
            dp[i] = dp[i - 2] + A[i];
        }
        int res = upper_bound(dp, dp + N, P) - dp;
        cout << res << endl;
    }//while kasenum
    return 0;
}