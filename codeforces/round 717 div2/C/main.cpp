#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <memory>
#include <memory.h>

using namespace std;
const int maxn = 100 + 10;
int N = 0, M = 0;
int A[maxn];
int dp[maxn][maxn * 2000];

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        M += A[i];
    }

    if (M % 2) {
        cout << "0" << endl;
        return 0;
    }

    memset(dp, 0, sizeof(dp));
    for (int j = 0; j <= M; j++) {
        if (j < A[0]) {
            continue;
        }
        dp[0][j] = A[0];
    }

    for (int i = 1; i < N; i++) {
        for (int j = 0; j <= M; j++) {
            if (j < A[i]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - A[i]] + A[i]);
            }
        }
    }

    if (dp[N - 1][M / 2] != M / 2) {
        cout << 0 << endl;
        return 0;
    }

    int mini_ind = 30, ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 30; j++) {
            if ((1 << j) & A[i]) {
                if (mini_ind > j) {
                    mini_ind = j;
                    ans = i;
                }
                break;
            }
        }
    }

    cout << 1 << endl;
    cout << ans + 1 << endl;


    return 0;
}