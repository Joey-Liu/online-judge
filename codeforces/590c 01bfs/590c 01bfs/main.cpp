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

const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 50;
string maze[maxn];
int steps[3][maxn][maxn], row, col;
bool visited[maxn][maxn];

int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };


bool in_maze(int r, int c) {
	if (r < 0 || r >= row || c < 0 || c >= col)
		return false;
	return true;
}

void work(int num) {
	deque<PII> deq;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (maze[i][j] - '1' == num) {
				steps[num][i][j] = 0;
				deq.push_back(make_pair(i, j));
			}
		}
	}

	while (!deq.empty()) {
		PII pii = deq.front(); deq.pop_front();
		if (visited[pii.first][pii.second])
			continue;
		visited[pii.first][pii.second] = true;

		for (int i = 0; i < 4; i++) {
			int nr = pii.first + dr[i];
			int nc = pii.second + dc[i];
			if (!in_maze(nr, nc) || maze[nr][nc] == '#')
				continue;
			int step = maze[nr][nc] == '.' ? 1 : 0;
			if (step + steps[num][pii.first][pii.second] < steps[num][nr][nc]) {
				steps[num][nr][nc] = step + steps[num][pii.first][pii.second];
				if (!step)
					deq.push_front(make_pair(nr, nc));
				else
					deq.push_back(make_pair(nr, nc));
			}
		}
	}//while

}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		cin >> maze[i];
	}
	memset(steps, 0x3f, sizeof(steps));
	for (int i = 0; i < 3; i++) {
		memset(visited, false, sizeof(visited));
		work(i);
	}

	int status = 0, res = inf;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (maze[i][j] == '#')
				continue;
			if (steps[0][i][j] == inf || inf == steps[1][i][j] || inf == steps[2][i][j])
				continue;
			int tmp = steps[0][i][j] + steps[1][i][j] + steps[2][i][j];
			if (maze[i][j] == '.')
				tmp -= 2;
			res = min(res, tmp);
			status = 1;
		}
	}

	if (status)
		cout << res << endl;
	else
		cout << -1 << endl;

	return 0;
}