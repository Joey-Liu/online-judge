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

const int maxn = 1000 + 50;
int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };
int row, col;
string maze[maxn];
int steps[maxn][maxn];
bool visited[maxn][maxn];

bool in_maze(int r, int c) {
	if (r < 0 || r >= row || c < 0 || c >= col)
		return false;
	return true;
}

int work() {
	deque<PII> deq;
	deq.push_back(make_pair(0, 0));
	while (!deq.empty()) {
		PII pii = deq.front(); deq.pop_front();
		if (pii.first == row - 1 && pii.second == col - 1)
			break;
		if (visited[pii.first][pii.second])
			continue;
		visited[pii.first][pii.second] = true;

		for (int i = 0; i < 4; i++) {
			int nr = pii.first + dr[i];
			int nc = pii.second + dc[i];

			if (!in_maze(nr, nc))
				continue;
			int inc = (maze[nr][nc] == maze[pii.first][pii.second]) ? 0 : 1;
			if (inc + steps[pii.first][pii.second] < steps[nr][nc]) {
				steps[nr][nc] = inc + steps[pii.first][pii.second];
				if (inc) {
					deq.push_back(make_pair(nr, nc));
				}
				else {
					deq.push_front(make_pair(nr, nc));
				}
			}

		}


	}//while
	return steps[row - 1][col - 1];
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int kasenum = 0;
	cin >> kasenum;
	while (kasenum--) {
		cin >> row >> col;
		for (int i = 0; i < row; i++) {
			cin >> maze[i];
		}

		memset(visited, false, sizeof(visited));
		memset(steps, 0x3f, sizeof(steps));
		steps[0][0] = 0;
		cout << work() << endl;
	}//while

	return 0;
}