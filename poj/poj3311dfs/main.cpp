#include <iostream>
#include <vector>

using namespace std;

const int maxn = 20;
const int INF = 0x3f3f3f3f;

int routine[maxn];
int dist[maxn][maxn];
int adj[maxn][maxn];
bool visited[maxn];

int N, ans;


int calc() {
    int tmp = 0;
    for (int i = 0; i < N - 1; i++) {
        int a = routine[i], b = routine[i + 1];
        tmp += dist[a][b];
    }
    tmp += dist[routine[N - 1]][0];
    return tmp;
}

void dfs(int cur) {
    if (cur >= N) {
        int tmp = calc();
        ans = min(ans, tmp);
//        for (int i = 0; i < N; i++) {
//            cout << routine[i] << " ";
//        }
//        cout << endl;
        return;
    }

    for (int i = 1; i < N; i++) {
        if (visited[i]) {
            continue;
        }

        visited[i] = true;
        routine[cur] = i;
        dfs(cur + 1);
        visited[i] = false;
    }//for int i
}



int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while (cin >> N) {
        if (!N) {
            break;
        }

        N += 1;
        memset(dist, 0x3f3f3f3f, sizeof(dist));
        ans = INF;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> adj[i][j];
                dist[i][j] = adj[i][j];
            }
        }//for int i

        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }// for int i
        }//for int k

        memset(visited, false, sizeof(visited));
        visited[0] = true;
        routine[0] = 0;
        dfs(1);
        cout << ans << endl;

    }//while cin

    return 0;
}