#include <iostream>
#include <string>
#include <string.h>
#include <memory.h>

using namespace std;
const int maxn = 3e5 + 50;

int work(int ind, int N, int K, const string & str) {
    int res = -1;
    while (ind < N) {
        if (res == -1 && str[ind] == '?') {
            ind += K;
            continue;
        } else if (res == -1 && str[ind] != '?') {
            res = str[ind] - '0';
            ind += K;
        } else if (res != -1 && str[ind] == '?') {
            ind += K;
            continue;
        } else if (res != -1 && str[ind] - '0' == res) {
            ind += K;
            continue;
        } else {
            return 2;
        }
    }//while ind
    return res;
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int kasenum, N, K;
    int visited[maxn];
    string str;
    cin >> kasenum;
    while (kasenum--) {
        cin >> N >> K;
        cin >> str;
        memset(visited, -1, sizeof(visited));
        bool flag = true;

        for (int i = 0; i < K; i++) {
            int num = work(i, N, K, str);
            if (num == 2) {
                flag = false;
                break;
            }

            int ind = i;
            while (ind < N) {
                visited[ind] = num;
                ind += K;
            }

        }//for int i
        if (!flag) {
            cout << "NO" << endl;
            continue;
        }

        int cnt_0 = 0, cnt_1 = 0, cnt_remain = 0;
        for (int i = 0; i < K; i++) {
            if (visited[i] == 0) {
                cnt_0 += 1;
            } else if (visited[i] == 1) {
                cnt_1 += 1;
            } else {
                cnt_remain += 1;
            }
        }
        int diff = cnt_0 - cnt_1;
        int x = (cnt_remain + diff) / 2;
        int y = cnt_remain - x;

        if (x + y != cnt_remain || x - y != diff || x < 0 || y < 0) {
            flag = false;
        }
        if (flag) {
            cout << "YES"<< endl;
        } else {
            cout << "NO" << endl;
        }


    }//while
    return 0;
}