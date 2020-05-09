#include <iostream>

using namespace std;
typedef long long LL;

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int kasenum = 0;
    cin >> kasenum;
    while (kasenum--) {
        LL N, K = 2, num = 0;
        cin >> N;
        num = (1 << K) - 1;
        while (num <= N) {
            if (0 == N % num) {
                break;
            }
            K++;
            num = (1 << K) - 1;
        }
        LL ans = N / num;
        cout << ans << endl;
    }
    return 0;
}