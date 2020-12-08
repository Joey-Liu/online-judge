#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;
const int maxn = 2e5 + 1;
int par[2 * maxn + 10];
int coins[2 * maxn + 10] = { 0 };

int extra_ind = maxn;

PII set_find(int a) {
    if (a == par[a]) {
        return make_pair(a, 0);
    }

    PII pii = set_find(par[a]);
    coins[a] += pii.second;
    par[a] = pii.first;
    PII cur = make_pair(par[a], coins[a]);
    return cur;
}

void set_join(int a, int b) {
    int x = set_find(a).first;
    int y = set_find(b).first;
    if (x == y) {
        return;
    }
    extra_ind += 1;

    par[x] = extra_ind;
    par[y] = extra_ind;
}


void add(int a, int v) {
    int x = set_find(a).first;
    coins[x] += v;
}

int get_coins(int a) {
    int x = set_find(a).first;
    if (x != a)
        return coins[x] + coins[a];
    else
        return coins[a];
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= 2 * maxn + 5; i++) {
        par[i] = i;
    }
    string str;
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> str;
        if ("add" == str) {
            cin >> a >> b;
            add(a, b);
        } else if ("join" == str) {
            cin >> a >> b;
            set_join(a, b);
        } else {
            cin >> a;
            int res = get_coins(a);
            cout << res << endl;
        }
    }


    return 0;
}