#include <iostream>
#include <string>
#include <string.h>

using namespace std;

const int maxn = 2e5 + 10;
int par[maxn], A[maxn], B[maxn];
int N, M, K;
string strs[maxn], ans[maxn];

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
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        par[i] = i;
    }

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
    }

    for (int i = 0; i < K; i++) {
        cin >> strs[i] >> A[i] >> B[i];
    }

    int ind = 0;
    for (int i = K - 1; i >= 0; i--) {
        if (strs[i] == "ask") {
            int x = set_find(A[i]);
            int y = set_find(B[i]);
            if (x == y) {
                ans[ind] = "YES";
            } else {
                ans[ind] = "NO";
            }
            ind += 1;
        } else {
            set_join(A[i], B[i]);
        }
    }

    for (int i = ind - 1; i >= 0; i--) {
        cout << ans[i] << endl;
    }



    return 0;
}