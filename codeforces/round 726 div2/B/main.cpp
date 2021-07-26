#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int kasenum;
    cin >> kasenum;
    int N, M, x, y;
    while (kasenum--) {
        cin >> N >> M >> x >> y;
        PII pos = make_pair(x, y);
        PII a1, a2;
        a1.first = 1; a1.second = M;
        a2.first = N, a2.second = 1;

        if ((pos.first == 1 && pos.second == 1) || \
            (pos.first == N && pos.second == M)) {
            a1.first = 1; a1.second = M;
            a2.first = N, a2.second = 1;
        } else if ((pos.first == 1 && pos.second == M) || \
            (pos.first == N && pos.second == 1)) {
            a1.first = 1; a1.second = 1;
            a2.first = N, a2.second = M;
        }

        cout << a1.first << " "
            << a1.second << " "
            << a2.first << " "
            << a2.second << endl;
    }
    return 0;
}