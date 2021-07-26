#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

const int maxn = 2e5 + 100;
int H[maxn], N;


int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int kasenum;
    cin >> kasenum;
    while (kasenum--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> H[i];
        }
        sort(H, H + N);

        if (H[0] == H[N - 1] || N == 2) {
            for (int i = 0; i < N; i++) {
                cout << H[i] << " ";
            }
            cout << endl;
            continue;
        }

        int dis = abs(H[1] - H[0]);
        int ind = 0;
        for (int i = 0; i < N - 1; i++) {
            if (H[i + 1] - H[i] < dis) {
                dis = H[i + 1] - H[i];
                ind = i;
            }
        }

        for (int i = ind + 1; i < N; i++) {
            cout << H[i] << " ";
        }

        for (int i = 0; i <= ind; i++) {
            cout << H[i] << " ";
        }
        cout << endl;


    }

    return 0;
}