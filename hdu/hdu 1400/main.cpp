#include<iostream>
#include<cstring>

using namespace std;


const int mm=1<<13;
typedef long long LL;
LL dp[13][1<<13];
int H, W;

bool check_two(int x, int y) {
    /*
     * x 是否可以转移到y
     * */
    int z = x | y;
    if (z != (1 << W) - 1) {
        return false;
    }
    //    while (z > 0) {
//        if ((z & 1) == 0) {
//            return false;
//        }
//        z >>= 1;
//    }

    z = x & y;

    while (z > 0) {
        if ((z & 1) == 0) {
            z >>= 1;
            continue;
        }

        if ((z & 2) == 0) {
            return false;
        }
        z >>= 2;
    }
    return true;
}


int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    while (cin >> H >> W) {
        if (!H && !W) {
            break;
        }
        if ((H * W) & 1) {
            cout << 0 << endl;
            continue;
        }

        memset(dp, 0, sizeof(dp));
        int max_state = (1 << W);
        for (int j = 0; j < max_state; j++) {
            if (check_two(max_state - 1, j)) {
                dp[0][j] = 1;
            }
        }

        for (int i = 1; i < H; i++) {
            for (int j = 0; j < max_state; j++) {
                for (int k = 0; k < max_state; k++) {
                    if (!check_two(j, k)) {
                        continue;
                    }
                    dp[i][j] += dp[i - 1][k];
                }
            }//for int j
        }//for int i
        cout << dp[H - 1][max_state - 1] << endl;
    }//while

}