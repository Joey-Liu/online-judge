#include <iostream>
#include <vector>
#include <algorithm>

typedef long long LL;
using namespace std;

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int kasenum;
    cin >> kasenum;
    while (kasenum--) {
        LL a[4];
        for (int i = 0; i < 4; i++) {
            cin >> a[i];
        }

        vector<LL> vi;
        for (int i = 1; i < 4; i++) {
            LL k = a[0] / a[i];
            vi.emplace_back(k * a[i]);
            vi.emplace_back(k * a[i] + a[i]);
            vi.emplace_back(k * a[i] - a[i]);
        }

        sort(vi.begin(), vi.end());
        int ind = lower_bound(vi.begin(), vi.end(), a[0]) - vi.begin();
        LL ans = vi[ind] - a[0];
        cout << ans << endl;


    }
    return 0;
}