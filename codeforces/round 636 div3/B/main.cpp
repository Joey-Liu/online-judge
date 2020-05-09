#include <iostream>
using namespace std;

int N;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int kasenum;
    cin >> kasenum;
    while (kasenum--) {
        cin >> N;
        if (0 != N % 4) {
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;
        int x = N / 2, a = N / 4;
        cout << "2";
        for (int i = 1; i < x; i++) {
            cout << " " << (i + 1) * 2;
        }
        for (int i = 0; i < x - 1; i++) {
            cout << " " << (i * 2 + 1);
        }
        cout << " " << x * 2 + x - 1 << endl;
    }
    return 0;
}