#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;
const LL mode = 1e9 + 7;

LL gcd(LL a, LL b) {
    while (b != 0) {
        LL c = a % b;
        a = b;
        b = c;
    } // while

    return a;
}


LL lcm(LL a, LL b) {
    LL c = gcd(a, b);
    return a * b / c;
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int kasenum;
    cin >> kasenum;
    while (kasenum--) {
        LL N = 0, ans = 0;
        cin >> N;

        LL cur = 1, ind = 1;
        while (true) {
            if (cur > N) {
                break;
            }

            LL nxt = lcm(cur, ind + 1);
            LL tmp = N / cur - N / nxt;
            ans += (tmp * (ind + 1));
            ans %= mode;

            cur = nxt;
            ind += 1;


        }

        cout << ans << endl;


    } //while

    return 0;
}