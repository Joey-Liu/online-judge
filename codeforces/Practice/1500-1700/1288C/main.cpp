#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <memory>
#include <memory.h>

using namespace std;
typedef long long LL;
LL M, N;

const LL mode = 1e9 + 7;
const int maxn = 1000 + 20;


LL C[maxn][maxn];
int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w" ,stdout);
    cin >> N >> M;
    memset(C, 0, sizeof(C));
    for (int i = 0; i < maxn; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mode;
        }
    }

    cout << C[N + 2 * M - 1][2*M] << endl;
    return 0;
}