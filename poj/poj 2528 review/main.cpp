#include <iostream>
#include <memory.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;
const int maxn = 10000 + 20;
typedef pair<int, int> PII;

int segTree[maxn << 2], add[maxn << 2], kasenum, N;
vector<int> nums;
PII pii[maxn];

void push_down(int root, int lp, int rp) {
    if (add[root] == -1) {
        return;
    }
    int le_son = root << 1;
    int ri_son = (root << 1) | 1;
    int mid = lp + (rp - lp) / 2;
    segTree[le_son] = add[root];
    segTree[ri_son] = add[root];
    add[le_son] = add[root];
    add[ri_son] = add[root];
    add[root] = -1;
}

void update(int root, int lp, int rp, int upd_lp, int upd_rp, int val) {
    if (lp > upd_rp || rp < upd_lp) {
        return;
    }
    if (upd_lp <= lp && rp <= upd_rp) {
        add[root] = val;
        segTree[val] = val;
        return;
    }
    int le_son = root << 1;
    int ri_son = (root << 1) | 1;
    int mid = lp + (rp - lp) / 2;
    push_down(root, lp, rp);
    update(le_son, lp, mid, upd_lp, upd_rp, val);
    update(ri_son, mid + 1, rp, upd_lp, upd_rp, val);
    if (segTree[le_son] == segTree[ri_son] && segTree[le_son] != -2) {
        segTree[root] = segTree[le_son];
    } else {
        segTree[root] = -2;
    }
}

int query(int root, int lp, int rp, int que_lp, int que_rp) {
    if (lp == rp && lp == que_lp) {
        return segTree[root];
    }
    if (rp < que_lp && que_rp < lp) {
        return 0;
    }
    int le_son = root << 1;
    int ri_son = (root << 1) | 1;
    int mid = lp + (rp - lp) / 2;
    push_down(root, lp, rp);

    if (que_lp <= mid) {
        return query(le_son, lp, mid, que_lp, que_rp);
    } else {
        return query(ri_son, mid + 1, rp, que_lp, que_rp);
    }

}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> kasenum;
    while (kasenum--) {
        cin >> N;
        nums.clear();
        for (int i = 0; i < N; i++) {
            cin >> pii[i].first >> pii[i].second;
            nums.push_back(pii[i].first);
            nums.push_back(pii[i].second);
        }

        sort(nums.begin(), nums.end());
        int div_n =  unique(nums.begin(), nums.end()) - nums.begin();
        nums.resize(div_n);

        memset(segTree, -1, sizeof(segTree));
        memset(add, -1, sizeof(add));
        for (int i = 0; i < N; i++) {
            int upd_lp = lower_bound(nums.begin(), nums.end(), pii[i].first) - nums.begin();
            int upd_rp = lower_bound(nums.begin(), nums.end(), pii[i].second) - nums.begin();
            upd_lp += 1;
            upd_rp += 1;
            update(1, 1, div_n, upd_lp, upd_rp, i + 1);
        }

        set<int> si;
        for (int i = 1; i <= div_n; i++) {
            int t = query(1, 1, div_n, i, i);
            si.insert(t);
        }
        cout << si.size() << endl;
    }//while kasenum--

    return 0;
}