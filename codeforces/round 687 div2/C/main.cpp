#include <iostream>
#include <memory.h>
#include <string>
#include <string.h>

using namespace std;

const int maxn = 1e5 + 200;
int N, P, K, X, Y;
int A[maxn], dp[maxn];

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int kasenum;
    cin >> kasenum;
    while (kasenum--) {
        cin >> N >> P >> K;
        string str;
        cin >> str;
        for (int i = 0; i < N; i++) {
            A[i] = str[i] - '0';
        }

        cin >> X >> Y;
        memset(dp, 0x3f3f3f3f, sizeof(dp));
        for (int i = N - 1; i >= 0; i--) {
            int nxt = 0;
            if (i + K < N) {
                nxt = dp[i + K];
            }

            int cur = 0;
            if (A[i] == 0) {
                cur = X;
            }
            dp[i] = cur + nxt;
        }

        int res = dp[P - 1], ind = 1;
        for (int i = P; i < N; i++) {
            if (ind > N - P) {
                break;
            }
            res = min(res, ind * Y + dp[i]);
            ind += 1;
        }
        cout << res << endl;
    }
    return 0;
}