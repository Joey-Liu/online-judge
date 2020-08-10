#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
const int maxn = 50 + 10;
int nums[maxn], N;
map<int, int> tab;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int kasenum;
    cin >> kasenum;
    while (kasenum--) {
        tab.clear();
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> nums[i];
            tab[nums[i]] += 1;
        }

        int ans = 0;
        sort(nums, nums + N);
        for (int s = nums[0] * 2; s <= nums[N - 1] * 2; s++) {
            map<int, int> cnt = tab;

            int tmp = 0;
            for (int i = 0; i < N; i++) {
                if (!cnt.count(nums[i]) || cnt[nums[i]] == 0) {
                    continue;
                }
                int a = nums[i], b = s - nums[i];
                if (a != b && cnt.count(b) && cnt[b] > 0) {
                    tmp += 1;
                    cnt[b] -= 1;
                    cnt[a] -= 1;
                } else if (a == b && cnt[a] >= 2) {
                    tmp += 1;
                    cnt[a] -= 2;
                }
            }
            ans = max(ans, tmp);
        }//for int s
        cout << ans << endl;
    }
    return 0;
}