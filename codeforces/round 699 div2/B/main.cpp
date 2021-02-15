#include <iostream>
#include <vector>
using namespace std;

const int maxn = 100 + 10;

int H[maxn], N, K;

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

        int ind = 0;
        bool flag = false;
        int res_pos = 0;

        while (ind < K) {
            int cur_pos = 0;
            while (cur_pos < N) {
                if (cur_pos == N - 1) {
                    flag = true;
                    break;
                }
                int nxt_pos = cur_pos + 1;
                if (H[nxt_pos] <= H[cur_pos]) {
                    cur_pos += 1;
                } else {
                    H[cur_pos] += 1;
                    break;
                }
            }
            ind += 1;
            if (flag) {
                break;
            }
            res_pos = cur_pos;
        }//while

        if (flag) {
            cout << -1 << endl;
        } else {
            cout << res_pos + 1 << endl;
        }
    }
    return 0;
}