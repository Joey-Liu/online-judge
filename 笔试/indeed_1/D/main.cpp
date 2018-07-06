#include <iostream>
#include <climits>
#include <memory.h>
#include <random>
#include <ctime>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <deque>
#include <bitset>
using namespace std;
typedef long long LL;
typedef vector<int> vi;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
#ifdef LOCAL
    #define DEBUG(x) { cerr << "# " << #x << ": " << x << endl;}
#else
    #define DEBUG(x)
#endif
mt19937_64 mt(time(0));
/*++++++++++++++++++++++++++++++++++++coding area start+++++++++++++++++++++++++++++++++++++++++*/

const int mod = 1e9 + 7;
string s;
vector<LL> dp, tmp;

void solve(int len, char c) {
    if (c == s[len]) {
        tmp[len+1] = (tmp[len+1] + dp[len]) % mod;
        return;
    }
    if (len == 0) {
        tmp[0] = (tmp[0] + dp[len]) % mod;
        return;
    }
    string p(1, c);
    for (int j = 1; j <= len; j++) {
        if (s.substr(j, len - j) + p == s.substr(0, len-j+1)) {
            tmp[len-j+1] = (tmp[len-j+1] + dp[len]) % mod;
            return;
        }
    }
    tmp[0] = (tmp[0] + dp[len]) % mod;
}


/*-------------------------------------coding area end------------------------------------------*/
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
    #ifdef LOCAL
        freopen("../test.txt", "r", stdin);
//        freopen("../output.txt", "w", stdout);
    #endif
/*++++++++++++++++++++++++++++++++++++coding area start+++++++++++++++++++++++++++++++++++++++++*/

    int n;
    cin >> n >> s;
    int m = s.size();
    dp = vector<LL>(m+1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        tmp = vector<LL>(m+1, 0);
        for (int j = 0; j < m; j++) {
            for (char c = 'a'; c <= 'z'; c++) {
                solve(j, c);
            }
        }
        swap(tmp, dp);
    }
    LL ret = 0;
    for (int i = 0; i < m; i++) {
        ret = (ret + dp[i]) % mod;
    }
    cout << ret << endl;




/*-------------------------------------coding area end------------------------------------------*/

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
    #endif
    return 0;
}
/* author:  txingml */