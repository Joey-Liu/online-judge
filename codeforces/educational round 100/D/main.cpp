#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <string.h>
#include <memory>

using namespace std;
const int maxn = 5 * 1e5;
bool B[maxn];
int N;
vector<int> v1, v2;

int tianjisaima() {
    int x = 0, ind = 0;
    for (x = 0; x < N; x++) {
        //选出第一匹马
        while (ind < N && v2[ind] < v1[x])
            ind += 1;
        if (ind >= N)
            return x;
        ind += 1;
    }
    return N;
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int kasenum;
    cin >> kasenum;
    while (kasenum--) {
        cin >> N;
        memset(B, false, sizeof(B));
        v1.clear(); v2.clear();
        for (int i = 0; i < N; i++) {
            int tmp;
            cin >> tmp;
            B[tmp] = true;
        }//for int i

        v1.reserve(N + 10);
        v2.reserve(N + 10);
        for (int i = 1; i <= 2 * N; i++) {
            if (B[i]) {
                v1.emplace_back(i);
            } else {
                v2.emplace_back(i);
            }
        }//for int i

        int mx = tianjisaima();
        swap(v1, v2);
        int mn = tianjisaima();
        mn = N - mn;

        cout << mx - mn + 1 << endl;

    }//while
    return 0;
}