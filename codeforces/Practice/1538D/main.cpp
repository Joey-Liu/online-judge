#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

typedef long long LL;

LL gcd(LL a, LL b) {
    while (b != 0) {
        LL c = a % b;
        a = b;
        b = c;
    }

    return a;
}

LL decomp(LL c) {
    if (c == 1) {
        return 0;
    }

    LL bd = sqrt(c) + 1, cnt = 0;
    for (LL i = 2; i <= c; i++) {
        while (0 == c % i) {
            c /= i;
            cnt += 1;
        }

    }
    return cnt;
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int kasenum;
    cin >> kasenum;
    while (kasenum--) {
        LL a = 0, b = 0, K = 0;
        cin >> a >> b >> K;
        if (a < b) {
            swap(a, b);
        }


        LL cnt = 0, c1 = 0, c2 = 0;
        if (a % b) {
            LL c = gcd(a, b);
            cnt = decomp(c);
        } else {
            cnt = decomp(a);
            cnt = max(cnt, 1LL);
            if (b != 1) {
                c2 = decomp(b);
                c2 = max(1LL, c2);
            }

            if (a != b) {
                c1 = decomp(a / b);
                c1 = max(1LL, c1);
            }

        }

        if (a % b) {
            K -= 2;
        }

        if (K < 0) {
            cout << "No" << endl;
            continue;
        }

        bool flag = false;
        if (a % b) {
            if (cnt >= K) {
                flag = true;
            } else {
                flag = false;
            }
        } else {
            if (K == 1 && a == b) {
                flag = false;
            } else if (c1 + 2 * c2 >= K) {
                flag = true;
            } else {
                flag = false;
            }
        }

        if (flag) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }

    } // while
    return 0;
}