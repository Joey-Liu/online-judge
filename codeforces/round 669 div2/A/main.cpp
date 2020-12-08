#include <iostream>

using namespace std;

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int kasenum;
    cin >> kasenum;
    while (kasenum--) {
        int N, a = 0, b = 0, tmp;
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> tmp;
            if (tmp == 0) {
                a += 1;
            } else {
                b += 1;
            }
        }
        if (a >= N / 2) {
            cout << N / 2 << endl;
            for (int i = 0; i < N / 2; i++) {
                cout << 0 << " ";
            }
        } else {
            if (b % 2) {
                b -= 1;
            }
            cout << b << endl;
            for (int i = 0; i < b; i++) {
                cout << 1 << " ";
            }
        }
        cout << endl;
    }
    return 0;
}