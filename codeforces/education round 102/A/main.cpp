#include <iostream>
#include <algorithm>

using namespace std;
const int maxn = 200;
int nums[maxn];

int main() {
    int kasenum;
    int N, D;
    cin >> kasenum;
    while (kasenum--) {
        cin >> N >> D;
        for (int i = 0; i < N; i++) {
            cin >> nums[i];
        }
        sort(nums, nums + N);
        if (nums[N - 1] <= D) {
            cout << "YES" << endl;
            continue;
        }

        if (nums[0] + nums[1] <= D) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }


    }
    return 0;
}