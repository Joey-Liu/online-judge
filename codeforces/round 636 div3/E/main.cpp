#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory>
#include <memory.h>

using namespace std;

typedef long long LL;
const int maxn = 2e5 + 10;

vector<int> adj[maxn];
LL prices[maxn];
bool visited[maxn];
LL pres[maxn];
int N, M, A, B, C;

void bfs(int root, vector<int> & vi) {
    memset(visited, false, sizeof(visited));
    queue<int> que;
    que.push(root);
    visited[root] = true;
    vi[root] = 0;
    while (!que.empty()) {
        int cur = que.front();
        que.pop();

        for (int i = 0; i < adj[cur].size(); i++) {
            int nei = adj[cur][i];
            if (visited[nei]) {
                continue;
            }

            visited[nei] = true;
            vi[nei] = vi[cur] + 1;
            que.push(nei);
        }
    }
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
        cin >> N >> M >> A >> B >> C;
        for (int i = 0; i <= N; i++) {
            adj[i].clear();
        }

        for (int i = 1; i <= M; i++) {
            cin >> prices[i];
        }

        for (int i = 0; i < M; i++) {
            int x, y;
            cin >> x >> y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }

        vector<int> ax(N + 1, 0), bx(N + 1, 0), cx(N + 1, 0);

        bfs(A, ax);
        bfs(B, bx);
        bfs(C, cx);

        sort(prices + 1, prices + M + 1);
        pres[0] = 0;
        for (int i = 1; i <= M; i++) {
            pres[i] = pres[i - 1] + prices[i];
        }

        LL ans = 0x3fffffffffffffff;
        for (int i = 1; i <= N; i++) {
            int p = ax[i];
            int q = bx[i];
            int r = cx[i];
            int pqr = p + q + r;
            if (pqr > M)
                continue;
            ans = min(ans, pres[pqr] + pres[q]);
        }
        cout << ans << endl;



    }
    return 0;
}