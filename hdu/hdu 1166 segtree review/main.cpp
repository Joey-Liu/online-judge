#include <iostream>
#include <memory>
#include <string>
#include <string.h>
#include <memory.h>
#include <algorithm>

using namespace std;

const int maxn = 50000 + 20;
int segTree[maxn << 2], num[maxn];
int T = 0, kasenum = 0, N = 0;
string str;

void build_tree(int root, int lp, int rp) {
    if (lp > rp) {
        return;
    }
    if (lp == rp) {
        segTree[root] = num[lp];
        return;
    }
    int mid = lp + (rp - lp) / 2;
    int le_son = root << 1;
    int ri_son = (root << 1) | 1;
    build_tree(le_son, lp, mid);
    build_tree(ri_son, mid + 1, rp);
    segTree[root] = segTree[le_son] + segTree[ri_son];
}

void update(int root, int lp, int rp, int node, int k) {
    if (lp == rp && lp == node) {
        segTree[root] += k;
        return;
    }

    if (lp > node || rp < node) {
        return;
    }

    int mid = lp + (rp - lp) / 2;
    int le_son = root << 1;
    int ri_son = (root << 1) | 1;
    update(le_son, lp, mid, node, k);
    update(ri_son, mid + 1, rp, node, k);
    segTree[root] = segTree[le_son] + segTree[ri_son];
}

int query(int root, int lp, int rp, int que_lp, int que_rp) {
    if (que_lp <= lp && rp <= que_rp) {
        return segTree[root];
    }
    if (que_lp > rp || que_rp < lp) {
        return 0;
    }

    int mid = lp + (rp - lp) / 2;
    int le_son = root << 1;
    int ri_son = (root << 1) | 1;
    int le_res = query(le_son, lp, mid, que_lp, que_rp);
    int ri_res = query(ri_son, mid + 1, rp, que_lp, que_rp);
    return le_res + ri_res;
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (++kasenum <= T) {
        memset(segTree, 0, sizeof(segTree));
        memset(num, 0, sizeof(num));
        cin >> N;
        for (int i = 1; i <= N; i++) {
            cin >> num[i];
        }
        build_tree(1, 1, N);
        cout << "Case " << kasenum << ":" << endl;
        while (cin >> str && str != "End") {
            int a, b;
            cin >> a >> b;
            if (str[0] == 'Q') {
                int res = query(1, 1, N, a, b);
                cout << res << endl;
            } else if (str[0] == 'S') {
                b = -b;
                update(1, 1, N, a, b);
            } else {
                update(1, 1, N, a, b);
            }
        }
    }

    return 0;
}