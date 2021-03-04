#include <iostream>
#include <vector>
#include <memory.h>
#include <memory>

using namespace std;

const int maxn = 1e5 + 100;
int nums[maxn], ans[maxn], maxi_ind[maxn], N;


int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int kasenum;
    cin >> kasenum;
    while (kasenum--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> nums[i];
        }

        memset(maxi_ind, -1, sizeof(maxi_ind));
        maxi_ind[0] = 0;
        for (int i = 1; i < N; i++) {
            if (nums[i] > nums[maxi_ind[i - 1]]) {
                maxi_ind[i] = i;
            } else {
                maxi_ind[i] = maxi_ind[i - 1];
            }
        }

        int st = N - 1, ind = 0;
        while (st >= 0) {
            int ed = maxi_ind[st];
            for (int i = ed; i <= st; i++) {
                ans[ind] = nums[i];
                ind += 1;
            }
            st = ed - 1;
        }
        for (int i = 0; i < N; i++) {
            cout << ans[i] << " ";
        }

        cout << endl;

    }// while
    return 0;
}