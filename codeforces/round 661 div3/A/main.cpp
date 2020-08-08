#include <iostream>
#include <algorithm>

using namespace std;
const int maxn = 50 + 10;
int nums[maxn], N;

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
        sort(nums, nums + N);
        bool flag = true;
        for (int i = 0; i < N - 1; i++) {
            if (nums[i + 1] - nums[i] > 1) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    }
    return 0;
}