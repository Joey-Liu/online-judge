#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;
const int maxn = 100000 + 10;
vector<LL> color[3];

bool work(vector<LL> & s, vector<LL> & m, vector<LL> & h, LL & value) {
    bool is_first = true;
    for (int i = 0; i < m.size(); i++) {
        LL b = m[i];
        int h_ind = lower_bound(h.begin(), h.end(), b) - h.begin();
        int s_ind = upper_bound(s.begin(), s.end(), b) - s.begin();
        s_ind -= 1;
        if (s_ind < 0 || h_ind >= h.size()) {
            continue;
        }
        LL a = h[h_ind], c = s[s_ind];
        LL tmp = (a - b) * (a - b) + (b - c) * (b - c) + (a - c) * (a - c);

        if (is_first) {
            is_first = false;
            value = tmp;
        }
        value = min(value, tmp);
    }
    return !is_first;
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int kasenum = 0;
    cin >> kasenum;
    while (kasenum--) {
        int lens[3];
        for (int i = 0; i < 3; i++) {
            cin >> lens[i];
            color[i].clear();
        }

        for (int i = 0; i < 3; i++) {
            LL tmp = 0;
            for (int j = 0; j < lens[i]; j++) {
                cin >> tmp;
                color[i].emplace_back(tmp);
            }
            sort(color[i].begin(), color[i].end());
        }

        LL res = -1, tmp = -1;
        if (work(color[0], color[1], color[2], tmp)) {
            if (res == -1 || res > tmp) {
                res = tmp;
            }
        }
        if (work(color[0], color[2], color[1], tmp)) {
            if (res == -1 || res > tmp) {
                res = tmp;
            }
        }
        if (work(color[1], color[0], color[2], tmp)) {
            if (res == -1 || res > tmp) {
                res = tmp;
            }
        }
        if (work(color[1], color[2], color[0], tmp)) {
            if (res == -1 || res > tmp) {
                res = tmp;
            }
        }
        if (work(color[2], color[0], color[1], tmp)) {
            if (res == -1 || res > tmp) {
                res = tmp;
            }
        }
        if (work(color[2], color[1], color[0], tmp)) {
            if (res == -1 || res > tmp) {
                res = tmp;
            }
        }
        cout << res << endl;
    }// while
    return 0;
}