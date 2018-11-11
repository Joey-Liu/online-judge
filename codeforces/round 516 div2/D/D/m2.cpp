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
int N, M, sr, sc, x, y;

struct Node {
	int r, c;
	int right_steps, left_steps;

	Node(int aa = 0, int bb = 0, int cc = 0, int dd = 0) {
		r = aa; c = bb;
		right_steps = dd; left_steps = cc;
	}

	bool friend operator < (const Node & m, const Node & n) {
		return m.right_steps + m.left_steps > n.right_steps + n.left_steps;
	}

};

string maze[maxn];
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

	memset(visited, false, sizeof(visited));
	cin >> N >> M >> sr >> sc >> x >> y;
	for (int i = 0; i < N; i++) {
		cin >> maze[i];
	}

	sc--; sr--;
	priority_queue<Node> pq;
	visited[sr][sc] = true;
	pq.push(Node(sr, sc, 0, 0));

	while (!pq.empty()) {
		Node node = pq.top(); pq.pop();
		for (int i = 0; i < 4; i++) {
			int nr = node.r + dr[i];
			int nc = node.c + dc[i];
			int lss = node.left_steps, rss = node.right_steps;

			lss += (i == 3);
			rss += (i == 1);
			if (lss > x || rss > y)
				continue;

			if (in_maze(nr, nc) && maze[nr][nc] == '.' && !visited[nr][nc]) {
				visited[nr][nc] = true;
				pq.push(Node(nr, nc, lss, rss));
			}
		}
	}//while
	int res = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j]) {
				res++;
				//cout << " 1";
			}
			/*
			else {
				cout << " 0";
			}*/
		}
		//cout << endl;
	}

	cout << res << endl;
	return 0;
}