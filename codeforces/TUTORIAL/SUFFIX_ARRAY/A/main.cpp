#include <iostream>
#include <map>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;
const int maxn = 1e5 + 100;


int main() {
    string str;
    cin >> str;
    str += "$";
    int N = str.size();

    vector<int> c(N, -1);
    {
        vector<pair<int, int>> a;
        for (int i = 0; i < N; i++) {
            a.emplace_back(make_pair(str[i], i));
        }

        sort(a.begin(), a.end());
        c[a[0].second] = 0;
        for (int i = 1; i < N; i++) {
            if (a[i].first == a[i - 1].first) {
                c[a[i].second] = c[a[i - 1].second];
            } else {
                c[a[i].second] = c[a[i - 1].second] + 1;
            }
        }
    }

    int k = 0;
    while ((1 << k) < N) {
        vector<pair<pair<int, int>, int>> a(N);
        for (int i = 0; i < N; i++) {
            a[i] = { {c[i], c[(i + (1 << k)) % N] }, i};
        }
        sort(a.begin(), a.end());
        c[a[0].second] = 0;
        for (int i = 1; i < N; i++) {
            if (a[i].first == a[i - 1].first) {
                c[a[i].second] = c[a[i - 1].second];
            } else {
                c[a[i].second] = c[a[i - 1].second] + 1;
            }
        }
        k += 1;
    }//while

    vector<int> res(N, -1);
    for (int i = 0; i < N; i++) {
        res[c[i]] = i;
    }
    for (int i = 0; i < N; i++) {
        cout << res[i] << " ";
    }
    return 0;
}