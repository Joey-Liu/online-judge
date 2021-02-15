#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;

const int maxn = 1e5 + 1000;
int A[maxn], B[maxn], C[maxn];
int N, M;

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int kasenum;
    cin >> kasenum;
    while (kasenum--) {
        cin >> N >> M;
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        for (int i = 0; i < M; i++) {
            cin >> C[i];
        }

        map<int, queue<int> > tab;
        map<int, int> ori;

        for (int i = 0; i < N; i++) {
            if (B[i] != A[i]) {
                tab[B[i]].emplace(i);
            } else {
                ori[A[i]] = i;
            }
        }

        vector<int> nx(M, -1);
        for (int i = M - 1; i >= 0; i--) {
            if (tab.count(C[i])) {
                nx[i] = tab[C[i]].back();
            } else if (ori.count(C[i])) {
                nx[i] = ori[C[i]];
            } else if (i + 1 < M){
                nx[i] = nx[i + 1];
            }
        }

        vector<int> res(M, -1);
        bool flag = true;
        for (int i = 0; i < M; i++) {
            int cur = C[i];
            if (tab.count(cur)) {
                res[i] = tab[cur].front();
                tab[cur].pop();
                if (tab[cur].empty()) {
                    tab.erase(cur);
                }
            } else {
                res[i] = nx[i];
                if (res[i] == -1) {
                    flag = false;
                    break;
                }
            }
        }

        if (!flag || tab.size() != 0) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            for (int i = 0; i < M; i++) {
                cout << res[i] + 1 << " ";
                A[res[i]] = C[i];
            }
            cout << endl;

//            for (int i= 0; i < N ;i ++) {
//                cout << A[i] << " ";
//            }
        }


    }
    return 0;
}