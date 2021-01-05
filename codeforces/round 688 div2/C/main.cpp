#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <string>
#include <map>

using namespace std;
const int maxn = 2000 + 20;

typedef pair<int, int> PII;

int N;
string board[maxn];

int work(char x) {
    int mini_row = maxn, mini_col = maxn;
    int maxi_row = -1, maxi_col = -1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (x != board[i][j]) {
                continue;
            }
            mini_row = min(mini_row, i);
            mini_col = min(mini_col, j);
            maxi_row = max(maxi_row, i);
            maxi_col = max(maxi_col, j);
        }//for int j
    }//for int i

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (x != board[i][j]) {
                continue;
            }
            int a = max(N - 1 - j, j) * max(maxi_row - i, i - mini_row);
            int b = max(i, N - 1 - i) * max(maxi_col - j, j - mini_col);
            ans = max(a, ans);
            ans = max(b, ans);
        }//for int j
    }//for int i

    return ans;
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int kasenum;
    cin >> kasenum;
    while (kasenum--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> board[i];
        }

        for (int i = '0'; i <= '9'; i++) {
            int tmp = work(i);
            cout << tmp << " ";
        }
        cout << endl;


    }// while
    return 0;
}