#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

const int maxn = 3e5 + 10;
int par[maxn];

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
    int N, cur, res;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        par[i] = i;
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &cur);
        res = set_find(cur);
        printf("%d ", res);
        int nxt = res + 1;
        if (nxt > N) {
            nxt = 1;
        }
        set_join(cur, nxt);
    }
    return 0;
}