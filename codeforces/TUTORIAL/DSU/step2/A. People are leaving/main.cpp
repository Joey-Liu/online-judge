#include <iostream>
#include <stdio.h>


using namespace std;

const int maxn = 1e6 + 10;

int par[maxn], M, N;

int set_find(int a) {
    if (a == par[a]) {
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
    //cin.tie(0);
    //cout.tie(0);

    //cin >> N >> M;
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N + 2; i++) {
        par[i] = i;
    }
    getchar();
    char ch;
    int a;
    for (int i = 0; i < M; i++) {
        scanf("%c %d", &ch, &a);
        getchar();
        //cin >> ch >> a;
        if (ch == '-') {
            int b = a + 1;
            set_join(a, b);
        } else {
            int x = set_find(a);
            if (x > N) {
                printf("-1\n");
                //cout << "-1" << endl;
            } else {
                printf("%d\n", x);
                //cout << x << endl;
            }
        }
    }

    return 0;
}