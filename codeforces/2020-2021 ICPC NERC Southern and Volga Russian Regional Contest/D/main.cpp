#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>

using namespace std;
const int maxn = 2e5 + 100;
typedef long long LL;
int N, M, A, B;
int S[maxn];

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int kasenum;
    cin >> kasenum;
    while (kasenum--) {
        cin >> N >> M >> A >> B;
        for (int i = 0; i < M; i++) {
            cin >> S[i];
        }
        sort(S, S + M);
        reverse(S, S + M);
        LL diff = A > B ? A - B - 1 : B - A - 1;
        LL left = A < B ? A - 1 : N - A;
        LL total_time = diff + left + 1;
        LL X = diff;
        LL Y = 1, ans = 0;
        for (int i = 0; i < M; i++) {
            if (ans >= X) {
                break;
            }
            if (Y + S[i] <= total_time) {
                ans += 1;
                Y += 1;
            }
        }
        cout << ans << endl;
    }//
    return 0;
}