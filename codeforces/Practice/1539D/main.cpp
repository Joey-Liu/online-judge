#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;
typedef pair<LL, LL> PII;

const int maxn = 100000 + 500;
PII goods[maxn];

bool cmp(PII p1, PII p2) {
    return p1.second < p2.second;
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    LL N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> goods[i].first >> goods[i].second;
    }
    sort(goods, goods + N, cmp);

    int ed = N - 1, st = 0;
    LL tar = goods[0].second, cnt = 0, ans = 0;


    while (st <= ed) {
        tar = goods[st].second;

        // no discount
        if (cnt < tar) {
            if (cnt + goods[ed].first <= tar) {
                cnt += goods[ed].first;
                ans += 2 * goods[ed].first;
                ed -= 1;
            } else {
                LL tmp = tar - cnt;
                ans += 2 * tmp;
                cnt += tmp;
                goods[ed].first -= tmp;
            }
        } else {
            cnt += goods[st].first;
            ans += goods[st].first;
            st += 1;
        }
    }
    cout << ans << endl;



    return 0;
}