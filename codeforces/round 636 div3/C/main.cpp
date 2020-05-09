#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

const int maxn = 200000 + 20;
LL nums[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int kasenum;
    cin >> kasenum;
    while (kasenum--) {
        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> nums[i];
        }

        LL res = 0, tmp = 0;
        int st = 0, ed = 1;
        while (st < N) {
            while (ed < N && nums[ed] * nums[st] > 0) {
                ed++;
            }
            tmp = nums[st];
            for (int i = st; i < ed; i++) {
                tmp = max(tmp, nums[i]);
            }
            res += tmp;
            st = ed;
        }// while st
        cout << res << endl;
    }
    return 0;
}