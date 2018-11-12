#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <math.h>
#include <functional>
#include <limits.h>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;

const int maxn = 2000 + 50;
int N, M, sr, sc, X, Y;

string maze[maxn];

struct Node {
	int r, c, x, y;

	Node(int aa, int bb, int cc, int dd) {
		r = aa; c = bb;
		x = cc; y = dd;
	}
};

bool visited[maxn][maxn];
int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };

bool in_maze(int r, int c) {
	if (r < 0 || r >= N || c < 0 || c >= M)
		return false;
	return true;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	

	cin >> N >> M >> sr >> sc >> X >> Y;
	sr--; sc--;

	memset(visited, false, sizeof(visited));
	for (int i = 0; i < N; i++) {
		cin >> maze[i];
	}
	deque<Node> deq;
	visited[sr][sc] = true;
	deq.push_back(Node(sr, sc, 0, 0));

	while (deq.size()) {
		Node node = deq.front(); deq.pop_front();
		for (int i = 0; i < 4; i++) {
			int nr = node.r + dr[i], nc = node.c + dc[i];
			int x = node.x, y = node.y;
			x += (i == 3);
			y += (i == 1);
			if (x > X || y > Y)
				continue;

			if (in_maze(nr, nc) && maze[nr][nc] == '.' && !visited[nr][nc]) {
				visited[nr][nc] = true;
				if (i == 0 || i == 2) {
					deq.push_front(Node(nr, nc, x, y));
				}
				else {
					deq.push_back(Node(nr, nc, x, y));
				}
			}
		}//for int i

	}//while

	int res = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j])
				res++;
		}
	}

	cout << res << endl;
	return 0;
}