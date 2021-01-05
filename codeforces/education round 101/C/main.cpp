#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;
typedef long long LL;

const int maxn = 2e5 + 100;
LL H[maxn], X[maxn], Y[maxn], N, K;

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int kasenum;
    cin >> kasenum;
    while (kasenum--) {
        cin >> N >> K;
        for (int i = 0; i < N; i++) {
            cin >> H[i];
        }

        X[0] = H[0] + K;
        Y[0] = H[0] + 1;
        bool flag = true;
        for (int i = 1; i < N; i++) {
            int curx = H[i] + K + K - 1;
            int cury = H[i] + 1;

            int px = X[i - 1] + (K - 1);
            int py = Y[i - 1] - (K - 1);
            X[i] = min(px, curx);
            Y[i] = max(py, cury);
            if (X[i] <= Y[i]) {
                flag = false;
                break;
            }
            if (X[i] - Y[i] + 1 < K) {
                flag = false;
                break;
            }

        }

        if (Y[N - 1] != H[N - 1] + 1) {
            flag = false;
        }

//        for (int i = 0; i < N; i++) {
//            cout << X[i] << " ";
//        }
//        cout << endl;
//        for (int i = 0; i < N; i++) {
//            cout << Y[i] << " ";
//        }
//        cout << endl;

        if (flag) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    }
    return 0;
}