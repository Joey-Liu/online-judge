#include <iostream>
#include <string>
using namespace std;

const int maxn = 2e5 + 200;
int M, N;
string s1, s2;

int dp[maxn], kb[maxn];

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> N >> M;
    cin >> s2 >> s1;

    int ind1 = 0, ind2 = 0;
    while (ind1 < M) {
        while (ind2 < N && s2[ind2] != s1[ind1]) {
            ++ind2;
        }
        dp[ind1] = ind2;
        ind1 += 1;
        ind2 += 1;
    }

    ind1 = M - 1;
    ind2 = N - 1;
    while (ind1 >= 0) {
        while (ind2 >= 0 && s2[ind2] != s1[ind1]) {
            --ind2;
        }
        kb[ind1] = ind2;
        ind1 -= 1;
        ind2 -= 1;
    }

    int ans = -1;
    for (int i = 0; i + 1 < M; i++) {
        ans = max(ans, kb[i + 1] - dp[i]);
    }
    cout << ans << endl;

    return 0;
}