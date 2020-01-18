#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long LL;

struct Node {
    int mini_num;
    int maxi_num;
    int length;
};

bool node_cmp (const Node & n1, const Node & n2) {
    return n1.maxi_num < n2.maxi_num;
}


bool has_acent(const vector<int> & vi) {
    for (int i = 1; i < vi.size(); i++) {
        if (vi[i] > vi[i - 1]) {
            return true;
        }
    }
    return false;
}

int bisearch(vector<Node> & vn, int lp, int rp, int tar) {
    while (lp < rp) {
        int mid = lp + (rp - lp) / 2;
        if (tar < vn[mid].maxi_num) {
            rp = mid;
        } else {
            lp = mid + 1;
        }
    }
    return lp;
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    LL N, self_ac = 0;
    cin >> N;
    vector<Node> vn;

    LL res = 0;
    for (int i = 0; i < N; i++) {
        int len = 0, tmp_maxi = -1, tmp_mini = 0x3f3f3f3f, tmp = 0;
        cin >> len;
        vector<int> vi;
        vi.resize(len);
        for (int j = 0; j < len; j++) {
            cin >> tmp;
            vi[j] = tmp;
            tmp_maxi = max(tmp, tmp_maxi);
            tmp_mini = min(tmp, tmp_mini);
        }
        if (has_acent(vi)) {
            self_ac += 1;
            res += (2 * N - 1);
            continue;
        }

        Node node;
        node.length = len;
        node.maxi_num = tmp_maxi;
        node.mini_num = tmp_mini;
        vn.emplace_back(node);
    }
    if (self_ac != 0) {
        res = res - ((self_ac - 1) * self_ac);
    }
    sort(vn.begin(), vn.end(), node_cmp);
    for (int i = 0; i < vn.size(); i++) {
        int ind = bisearch(vn, 0, vn.size(), vn[i].mini_num);
        res += (vn.size() - ind);
    }
    cout << res << endl;


    return 0;
}