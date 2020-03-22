#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <memory.h>
using namespace std;

const int maxn = 200 + 10;
const int inf = 0x3f3f3f3f;
int dp[maxn][maxn][2], N, even_num;
int bulbs[maxn];

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    memset(dp, 0x3f, sizeof(dp));

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> bulbs[i];
    }

    dp[0][0][0] = 0;
    dp[0][0][1] = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= i; j++) {
            if (!bulbs[i] || bulbs[i] % 2) {
                dp[i][j][1] = min(dp[i - 1][j][1], dp[i - 1][j][0] + 1);
            }
            if (j && !(bulbs[i] % 2)) {
                dp[i][j][0] = min(dp[i - 1][j - 1][0], dp[i - 1][j - 1][1] + 1);
            }
        }
    }
    cout << min(dp[N][N / 2][0], dp[N][N / 2][1]) << endl;

    return 0;


}