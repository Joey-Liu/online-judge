#include <iostream>
#include <string>

using namespace std;

int gcd(int x, int y) {
    if (x % y == 0) {
        return y;
    }

    return gcd(y, x % y);

}
int LCM(int x, int y) {
    return x * y / gcd(x, y);
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int kasenum = 0;
    cin >> kasenum;
    while (kasenum--) {
        string s1, s2, sub;
        cin >> s1 >> s2;
        int N = s1.size(), N2 = s2.size();
        bool flag = false;
        int i = 0;
        for (i = 1; i <= N; i++) {
            if (N % i != 0 || N2 % i != 0) {
                continue;
            }
            sub = s1.substr(0, i);
            string tmp = "";
            for (int j = 0; j < N / i; j++) {
                tmp.append(sub);
            }
            string t2 = "";
            for (int j = 0; j < N2 / i; j++) {
                t2.append(sub);
            }

            if (tmp == s1 && t2 == s2) {
                flag = true;
                break;
            }
        }
        if (flag) {
            string ans = "";
            int x1 = s1.size() / i, x2 = s2.size() / i;
            int lcm = LCM(x1, x2);
            for (int k = 0; k < lcm; k++) {
                ans.append(sub);
            }
            cout << ans << endl;
        } else {
            cout << "-1" << endl;
        }
    }
    return 0;
}