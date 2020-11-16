#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 1e5 + 50;
typedef pair<int, int> PII;
typedef long long LL;

int nums[maxn];

vector<PII> vpos, vneg;

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int kasenum;
    cin >> kasenum;
    while (kasenum--) {
        int N;
        cin >> N;
        vpos.clear();
        vneg.clear();
        LL all_sum = 0;

        for (int i = 0; i < N; i++) {
            int tmp;
            cin >> tmp;
            if (tmp >= 0) {
                all_sum += tmp;
                vpos.emplace_back(make_pair(i, tmp));
            } else {
                vneg.emplace_back(make_pair(i, tmp));
            }
        }

        int ind = 0, jnd = 0;
        while (ind < vpos.size() && jnd < vneg.size()) {
            if (vpos[ind].first > vneg[jnd].first) {
                jnd += 1;
            } else {
                if (vpos[ind].second + vneg[jnd].second > 0) {
                    vpos[ind].second += vneg[jnd].second;
                    jnd += 1;
                } else if (vpos[ind].second + vneg[jnd].second == 0) {
                    ind += 1;
                    jnd += 1;
                } else {
                    vneg[jnd].second += vpos[ind].second;
                    ind += 1;
                }
            }
        }//while
        LL remain = 0;
        while (ind < vpos.size()) {
            remain += vpos[ind].second;
            ind += 1;
        }
        cout << remain << endl;
    }//while
    return 0;
}