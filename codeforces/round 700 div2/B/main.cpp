#include <iostream>
#include <algorithm>
#include <memory>
#include <memory.h>
#include <vector>
#include <math.h>

typedef long long LL;
struct Node {
    LL a, b, c;
    Node () {
        a = 0;
        b = 0;
        c = 0;
    }
};

const int maxn = 1e5 + 50;
int A, B, N;

using namespace std;

bool mycmp(const Node & a, const Node & b) {
    return a.c < b.c;
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int kasenum;
    cin >> kasenum;
    while (kasenum--) {
        cin >> A >> B >> N;
        vector<Node> mons(N);
        for (int i = 0; i < N; i++) {
            cin >> mons[i].a;
        }
        for (int i = 0; i < N; i++) {
            cin >> mons[i].b;
        }

        LL all_damage = 0;
        for (int i = 0; i < N; i++) {
            LL t = int(ceil(double(mons[i].b) / A));
            mons[i].c = t * mons[i].a;
            all_damage += mons[i].c;
        }

        bool flag = false;
        LL H = B - all_damage;
        for (int i = 0; i < N; i++) {
            LL tmp = H + mons[i].a;
            if (tmp > 0) {
                flag = true;
                break;
            }
        }
        if (flag) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }


    }//while
    return 0;
}