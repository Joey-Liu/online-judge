#include <iostream>
#include <math.h>

using namespace std;
typedef long long LL;

const int maxn = 1e5 + 30;

int N;
LL T[maxn], X[maxn];

bool check(int ind, LL cur_pos, int dr, LL cur_time, LL nxt_time) {
    int tar_pos = X[ind];
    LL td = (tar_pos - cur_pos) / dr;
    if (td < 0) {
        return false;
    }

    LL ext = cur_time + td;
    if (ext > nxt_time) {
        return false;
    }

    if (ext >= T[ind] && ext <= T[ind + 1]) {
        return true;
    }
    return false;

}

int work(int cur_ind, int cur_pos, int & res) {
    LL cur_time = T[cur_ind], nxt_pos = X[cur_ind];
    if (nxt_pos == cur_pos) {
        res += 1;
        return cur_ind + 1;
    }
    LL time_diff = abs(nxt_pos - cur_pos);
    LL nxt_time = cur_time + time_diff;
    int ed_ind = cur_ind;
    while (ed_ind < N && T[ed_ind] < nxt_time) {
        ed_ind += 1;
    }
    int dr = nxt_pos - cur_pos > 0 ? 1 : -1;

    for (int i = cur_ind; i < ed_ind; i++) {
        if (check(i, cur_pos, dr, cur_time, nxt_time)) {
            //cout << i << endl;
            res += 1;
        }
    }
    return ed_ind;
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int kasenum;
    cin >> kasenum;
    while (kasenum--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> T[i] >> X[i];
        }
        T[N] = 0x3f3f3f3f3f3f3f3f;
        int cur_ind = 0, cur_pos = 0, res = 0;

        while (true) {
            int nxt_ind = work(cur_ind, cur_pos, res);
            if (nxt_ind >= N) {
                break;
            }
            cur_pos = X[cur_ind];
            cur_ind = nxt_ind;
        }
        cout << res << endl;
    }//while
    return 0;
}