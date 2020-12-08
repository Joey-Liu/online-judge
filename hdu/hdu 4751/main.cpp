#include <iostream>
#include <string>
#include <string.h>
#include <memory.h>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>

using namespace std;

const int maxn = 100 + 10;
int knows[maxn][maxn];
int neighbor[maxn][maxn], N;
int color[maxn];

bool dfs(int cur, int yanse) {
    color[cur] = yanse;
    for (int i = 1; i <= N; i++) {
        if (i == cur || neighbor[cur][i] == 0) {
            continue;
        }
        if (color[i] != 0 && color[i] == color[cur]) {
            return false;
        }
        if (color[i] != 0 && color[i] == -color[cur]) {
            continue;
        }
        if (!dfs(i, -yanse)) {
            return false;
        }
    }
    return true;
}


int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    while (cin >> N) {
        cin.get();
        memset(neighbor, 0, sizeof(neighbor));
        memset(knows, 0, sizeof(knows));
        memset(color, 0, sizeof(color));
        for (int i = 0; i < N; i++) {
            string str;
            //str = cin.getline();
            getline(cin, str);
            stringstream ss(str);
            int a;
            while (ss >> a) {
                if (a == 0) {
                    break;
                }
                knows[i + 1][a] = 1;
            }//while
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (!knows[i][j] || !knows[j][i]) {
                    neighbor[i][j] = 1;
                    neighbor[j][i] = 1;
                }
            }
        }

        bool flag = true;
        for (int i = 1; i <= N; i++) {
            if (color[i] != 0) {
                continue;
            }
            if (!dfs(i, 1)) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    }

    return 0;
}