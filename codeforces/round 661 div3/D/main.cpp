#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <vector>

using namespace std;

const int maxn = 300000 + 10;

int main() {
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int kasenum, N;
    char ch;
    cin >> kasenum;
    set<int> set_one; set<int> set_zero;

    while (kasenum--) {
        cin >> N;
        vector<int> v0, v1;
        int ind = 0, ans[maxn] = { 0 };
        for (int i = 0; i < N; i++) {
            cin >> ch;
            int tmp = -1;
            if (ch == '1') {
                if (v0.size() > 0) {
                    int cur_index = v0.back();
                    v0.pop_back();
                    v1.emplace_back(cur_index);
                    tmp = cur_index;
                } else {
                    v1.emplace_back(++ind);
                    tmp = ind;
                }
            } else {
                if (v1.size() > 0) {
                    int cur_index = v1.back();
                    v1.pop_back();
                    v0.emplace_back(cur_index);
                    tmp = cur_index;
                } else {
                    v0.emplace_back(++ind);
                    tmp = ind;
                }
            }
            ans[i] = tmp;
        }// for

        cout << ind << endl;
        for (int i = 0; i < N; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }// while
    return 0;
}