#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;
const int maxn = 2000 + 20;
int N, nums[maxn];

bool work(int tar) {
    int st = 1;
    int cur = nums[0];
    int cnt = 0;
    while (st < N) {
        while (cur != tar && st < N) {
            cur = cur ^ nums[st];
            st += 1;
        }

        if (cur != tar) {
            if (cnt >= 2)
                break;
            else {
                return false;
            }
        }

        if (st < N) {
            cnt += 1;
            cur = nums[st];
            st += 1;
        } else {
            return true;
        }

    }//while

    return (cur == tar || cur == 0);
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w" , stdout);
    int kasenum;
    cin >> kasenum;
    while (kasenum--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> nums[i];
        }

        vector<int> vi(N - 1, 0);
        vi[0] = nums[0];
        for (int i = 1; i < N - 1; i++) {
            vi[i] = nums[i] ^ vi[i - 1];
        }

        bool flag = false;
        for (int tar : vi) {
            if (work(tar)) {
                flag = true;
                break;
            }
        }

        if (flag) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }// while
    return 0;
}