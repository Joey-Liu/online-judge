#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>

using namespace std;
const int maxn = 100 + 5;

int M, N;
int dp[maxn][100][100];
int state[100], state_size = 0;
int dixing[maxn] = { 0 };
string str[maxn];

int check_one(int x) {
    if (x & (x >> 1))
        return false;
    if (x & (x >> 2))
        return false;
    return true;
}

int check_two(int x, int y) {
    if (x & y) {
        return false;
    }
    return true;
}

int calc(int x) {
    int res = 0;
    while (x > 0) {
        if (x & 1) {
            res += 1;
        }
        x >>= 1;
    }
    return res;
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> str[i];
        dixing[i] = 0;
        for (int j = 0; j < M; j++) {
            if (str[i][j] == 'P') {
                continue;
            }
            int t = M - j - 1;
            dixing[i] |= (1 << t);
        }//for int j
    }//for int i


    int maxi_state = (1 << M);

    for (int i = 0; i < maxi_state; i++) {
        if (check_one(i)) {
            state[state_size++] = i;
        }
    }

    for (int k = 0; k < state_size; k++) {
        int sk = state[k];
        if (sk & dixing[0]) {
            continue;
        }
        int tmp_num = calc(sk);
        for (int j = 0; j < state_size; j++) {
            dp[0][j][k] = tmp_num;
        }//for int j
    }//for int k

    for (int k = 0; k < state_size; k++) {
        int sk = state[k];
        if (sk & dixing[1]) {
            continue;
        }
        int tmp_num = calc(sk);
        for (int j = 0; j < state_size; j++) {
            int sj = state[j];
            if (sj & dixing[0]) {
                continue;
            }
            if (!check_two(sk, sj)) {
                continue;
            }

            dp[1][j][k] = max(dp[1][j][k], tmp_num + dp[0][0][j]);
        }
    }


    for (int i = 2; i < N; i++) {
        for (int k = 0; k < state_size; k++) {
            int sk = state[k];
            if (sk & dixing[i]) {
                continue;
            }

            int tmp_num = calc(sk);
            for (int j = 0; j < state_size; j++) {
                int sj = state[j];
                if (sj & dixing[i - 1]) {
                    continue;
                }
                if (!check_two(sk, sj)) {
                    continue;
                }

                for (int x = 0; x < state_size; x++) {
                    int sx = state[x];
                    if (!check_two(sj, sx) || !check_two(sk, sx)) {
                        continue;
                    }
                    dp[i][j][k] = max(dp[i][j][k], tmp_num + dp[i - 1][x][j]);
                }

            }//for int j

        }//for int k
    }//for int i

    int res = 0;
    for (int j = 0; j < state_size; j++) {
        for (int k = 0; k < state_size; k++) {
            res = max(res, dp[N - 1][j][k]);
        }
    }

    cout << res << endl;
    return 0;
}