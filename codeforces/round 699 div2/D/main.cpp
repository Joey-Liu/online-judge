#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;
typedef pair<int, int> PII;

const int maxn = 1e3 + 100;
string lab[maxn];
int N, M, tag[maxn], gat[maxn];

PII check() {
    bool flag = false;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                continue;
            }
            if (lab[i][j] == lab[j][i]) {
                return make_pair(i, j);
            }
        }
    }
    return make_pair(-1, -1);
}

void prepare() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                continue;
            }

            if (lab[i][j] == 'a') {
                tag[i] |= 1;
                gat[j] |= 1;
            } else if (lab[i][j] == 'b') {
                tag[i] |= 2;
                gat[j] |= 2;
            }
        }//for int j
    }//for int i

}


int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w" ,stdout);
    int kasenum;
    cin >> kasenum;
    while (kasenum--) {
        cin >> N >> M;

        for (int i = 0; i < N; i++) {
            cin >> lab[i];
            tag[i] = 0;
            gat[i] = 0;
        }

        PII p1 = check();
        if (p1.first != -1) {
            cout << "YES" << endl;
            cout << p1.first + 1 << " ";
            for (int i = 0; i < M; i++) {
                if (i % 2) {
                    cout << p1.first + 1 << " ";
                } else {
                    cout << p1.second + 1 << " ";
                }
            }
            cout << endl;
            continue;
        }

        if (M % 2) {
            cout << "YES" << endl;
            cout << 1 << " ";
            for (int i = 0; i < M; i++) {
                if (i % 2) {
                    cout << 1 << " ";
                } else {
                    cout << 2 << " ";
                }
            }
            cout << endl;
            continue;
        }

        prepare();
        int y = -1;
        for (int i = 0; i < N; i++) {
            if ((gat[i] & tag[i]) != 0) {
                y = i;
                break;
            }
        }
        if (y == -1) {
            cout << "NO" << endl;
            continue;
        }
        int x = -1, z = -1;
        for (int i = 0; i < N; i++) {
            if (i == y) {
                continue;
            }
            for (int j= 0; j < N; j++) {
                if (j == i || j == y) {
                    continue;
                }
                if (lab[i][y] == lab[y][j]) {
                    x = i;
                    z = j;
                    break;
                }
            }
            if (x != -1) {
                break;
            }
        }

        x += 1;
        y += 1;
        z += 1;
        if ((M / 2) % 2) {
            cout << "YES" << endl;
            cout << x << " ";
            for (int i = 0; i < M / 2; i++) {
                if (i % 2 == 0) {
                    cout << y << " " << z << " ";
                } else {
                    cout << y << " " << x << " ";
                }
            }
            cout << endl;
        } else {
            cout << "YES" << endl;
            cout << y << " ";
            for (int i = 0; i < M / 4; i++) {
                cout << z << " " << y << " " << x << " " << y << " ";
            }
            cout << endl;
        }
    }
    return 0;
}