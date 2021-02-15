#include <iostream>
#include <math.h>
#include <string>

using namespace std;
int X, Y;

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int kasenum;
    cin >> kasenum;
    while (kasenum--) {
        cin >> X >> Y;
        string str;
        cin >> str;
        int N = str.size();
        int cnt[] = {0, 0, 0, 0};
        for (int i = 0; i < N; i++) {
            if(str[i] == 'U') {
                cnt[0]++;
            } else if (str[i] == 'R') {
                cnt[1]++;
            } else if (str[i] == 'D') {
                cnt[2]++;
            } else {
                cnt[3]++;
            }
        }
        bool f1 = false, f2 = false;
        if (X >= 0) {
            if (cnt[1] >= X) {
                f1 = true;
            }
        } else {
            if (cnt[3] >= -X) {
                f1 = true;
            }
        }

        if (Y >= 0) {
            if (cnt[0] >= Y) {
                f2 = true;
            }
        } else {
            if (cnt[2] >= -Y) {
                f2 = true;
            }
        }

        if (f1 && f2) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    }

    return 0;
}