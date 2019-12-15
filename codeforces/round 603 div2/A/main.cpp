#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    //std::cout << "Hello, World!" << std::endl;
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);


    int casenum, nums[3];
    cin >> casenum;
    while (casenum--) {
        for (int i = 0; i < 3; i++) {
            cin >> nums[i];
        }

        sort(nums, nums + 3);
        int res = 0;
        res += nums[0];

        int t = nums[2] - nums[1];
        if (t > nums[0]) {
            nums[2] -= nums[0];
            res += min(nums[1], nums[2]);
        } else {
            nums[2] = nums[1];
            nums[0] -= t;
            int a = nums[0] / 2;
            int b = nums[0] - a;
            nums[1] -= a;
            nums[2] -= b;

            int tmp = min(nums[1], nums[2]);;
            res += max(tmp, 0);
        }
        cout << res << endl;
    }

    return 0;
}