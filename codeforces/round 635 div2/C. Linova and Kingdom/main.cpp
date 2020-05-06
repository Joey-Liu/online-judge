#include <iostream>
#include <vector>
#include <memory>
#include <memory.h>
#include <algorithm>
#include <functional>

using namespace std;
typedef long long LL;
const int maxn = 200000 + 10;
int N, K;
vector<int> edges[maxn];
LL sons[maxn], level[maxn];
bool visited[maxn];


// 在最优解情况下，每隔 由黑转白的节点带来的收益是确定的，所以可以使用贪心法

LL dfs(int cur, int depth) {
    visited[cur] = true;
    level[cur] = depth;
    LL tmp = 1;
    for (int i = 0; i < edges[cur].size(); i++) {
        int nxt = edges[cur][i];
        if (visited[nxt]) {
            continue;
        }
        tmp += dfs(nxt, depth + 1);
    }
    return sons[cur] = tmp;
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    memset(sons, 0, sizeof(sons));
    memset(level, 0, sizeof(level));
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        edges[a].emplace_back(b);
        edges[b].emplace_back(a);
    }
    dfs(1, 0);
    vector<LL> vi;
    for (int i = 1; i <= N; i++) {
        vi.emplace_back(sons[i] - level[i] - 1);
    }
    sort(vi.begin(), vi.end(), greater<LL>());
    LL ans = 0;
    for (int i = 0; i < N - K; i++) {
        ans += vi[i];
    }
    cout << ans << endl;
    return 0;
}