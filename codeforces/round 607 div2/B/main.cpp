#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int kasenum;
    string s1, s2, s1_sort;
    cin >> kasenum;
    while (kasenum--) {
        cin >> s1 >> s2;
        s1_sort = s1;
        sort(s1_sort.begin(), s1_sort.end());
        int ind = 0;
        for (; ind < s1.size(); ind++) {
            if (s1_sort[ind] != s1[ind]) {
                break;
            }
        }

        if (ind < s1.size()) {
            char c = s1_sort[ind];
            int jnd = s1.size() - 1;
            for (; jnd >= 0; jnd--) {
                if (s1[jnd] == c) {
                    break;
                }
            }

            if (jnd >= 0) {
                swap(s1[ind], s1[jnd]);
            }
        }

        if (s1 >= s2) {
            cout << "---" << endl;
        } else {
            cout << s1 << endl;
        }

    }

    return 0;
}