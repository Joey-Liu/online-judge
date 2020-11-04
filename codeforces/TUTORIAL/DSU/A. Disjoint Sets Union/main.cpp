#include <iostream>
#include <string>
#include <string.h>

using namespace std;

const int maxn = 1e5 + 100;
int par[maxn], N, M;

int set_find(int a) {
    if (par[a] == a) {
        return a;
    }

    return par[a] = set_find(par[a]);
}

void set_join(int a, int b) {
    int x = set_find(a);
    int y = set_find(b);
    if (x == y) {
        return;
    }

    par[x] = y;
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        par[i] = i;
    }

    for (int i = 0; i < M; i++) {
        string str;
        int a, b;
        cin >> str >> a >> b;
        if (str == "union") {
            set_join(a, b);
        } else {
            int x = set_find(a);
            int y = set_find(b);
            if (x == y) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }


    return 0;
}