#include <iostream>
#include <memory.h>
#include <string.h>
#include <string>
#include <algorithm>

using namespace std;
typedef long long LL;

const int maxn = 200000 + 10;
LL segTree[maxn << 2], student[maxn], add[maxn << 2], N, M;

void build_tree(int root, int lp, int rp) {
    if (lp == rp) {
        segTree[root] = student[lp];
        return;
    }

    int mid = lp + (rp - lp) / 2;
    int le_son = root << 1;
    int ri_son = (root << 1) | 1;
    build_tree(le_son, lp, mid);
    build_tree(ri_son, mid + 1, rp);
    segTree[root] = segTree[le_son] + segTree[ri_son];
}

void push_down(int root, int lp, int rp) {
    int le_son = root << 1;
    int ri_son = (root << 1) | 1;
    int mid = lp + (rp - lp) / 2;

    add[le_son] += add[root];
    add[ri_son] += add[root];

    segTree[le_son] += (add[root] * (mid - lp + 1));
    segTree[ri_son] += (add[root] * (rp - mid));
    add[root] = 0;
}

void update(int root, int lp, int rp, int upd_lp, int upd_rp, int val) {
    if (lp > upd_rp || rp < upd_lp) {
        return;
    }
    if (upd_lp <= lp && rp <= upd_rp) {
        add[root] += val;
        segTree[root] += (val * (rp - lp + 1));
        return;
    }
    push_down(root, lp, rp);

    int le_son = root << 1;
    int ri_son = (root << 1) | 1;
    int mid = lp + (rp - lp) / 2;

    update(le_son, lp, mid, upd_lp, upd_rp, val);
    update(ri_son, mid + 1, rp, upd_lp, upd_rp, val);
    segTree[root] = segTree[le_son] + segTree[ri_son];
}

LL query(int root, int lp, int rp, int que_lp, int que_rp) {
    if (que_lp > rp || que_rp < lp) {
        return 0;
    }
    if (que_lp <= lp && rp <= que_rp) {
        return segTree[root];
    }
    push_down(root, lp, rp);
    int le_son = root << 1;
    int ri_son = (root << 1) | 1;
    int mid = lp + (rp - lp) / 2;
    LL le_res = query(le_son, lp, mid, que_lp, que_rp);
    LL ri_res = query(ri_son, mid + 1, rp, que_lp, que_rp);
    return le_res + ri_res;
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    while (cin >> N >> M) {
        memset(segTree, 0, sizeof(segTree));
        memset(student, 0, sizeof(student));
        for (int i = 1; i <= N; i++) {
            cin >> student[i];
        }

        build_tree(1, 1, N);
        for (int i = 0; i < M; i++) {
            char ch;
            int a, b, c;
            cin >> ch;
            if (ch == 'C') {
                cin >> a >> b >> c;
                update(1, 1, N, a, b, c);
            } else {
                cin >> a >> b;
                LL res = query(1, 1, N, a, b);
                cout << res << endl;
            }
        }
    }// while
    return 0;
}