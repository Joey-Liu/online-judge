#include <iostream>
#include <algorithm>
typedef long long LL;
using namespace std;
const int maxn = 50 + 10;
int A[maxn], B[maxn], N;

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int kasenum;
    cin >> kasenum;
    while (kasenum--) {
        LL res = 0;
        cin >> N;
        int ma = 0x3f3f3f3f, mb = 0x3f3f3f3f;
        for (int i = 0; i < N; i++) {
            cin >> A[i];
            ma = min(A[i], ma);
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
            mb = min(B[i], mb);
        }

        for (int i = 0; i < N; i++) {
            int p = A[i] - ma;
            int q = B[i] - mb;
            res += min(p, q);
            res = res + p + q - min(p, q) - min(p, q);
        }
        cout << res << endl;

    }
    return 0;
}