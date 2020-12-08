#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 3e5 + 10;
int par[maxn], maxi[maxn], mini[maxn], cnt[maxn];

int set_find(int a) {
    return (a == par[a] ? a : par[a] = set_find(par[a]));
}

void set_join(int a, int b) {
    int x = set_find(a);
    int y = set_find(b);

    if (x == y) {
        return;
    }

    par[x] = y;
    maxi[y] = max(maxi[y], maxi[x]);
    mini[y] = min(mini[y], mini[x]);
    cnt[y] += cnt[x];
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        par[i] = i;
        maxi[i] = i;
        mini[i] = i;
        cnt[i] = 1;
    }

    string str;
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> str;
        if (str == "union") {
            cin >> a >> b;
            set_join(a, b);
        } else {
            cin >> a;
            int x = set_find(a);
            cout << mini[x] << " " << maxi[x] << " " << cnt[x] << endl;
        }
    }

    return 0;
}