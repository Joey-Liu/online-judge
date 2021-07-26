#include <iostream>
using namespace std;

const int maxn = 50 + 5;
int nums[maxn];

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int kasenum = 0, N = 0;
    cin >> kasenum;
    while (kasenum--) {
        cin >> N;
        int tmp = 0, S = 0;
        for (int i = 0; i < N; i++) {
            cin >> tmp;
            S += tmp;
        }

        int ans = 0;
        if (N > S) {
            ans = 1;
        } else if (N < S) {
            ans = S - N;
        }

        cout << ans << endl;
    } // while

    return 0;
}