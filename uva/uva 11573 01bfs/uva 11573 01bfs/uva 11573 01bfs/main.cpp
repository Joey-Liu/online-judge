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

const int maxn = 1000 + 20;
const int inf = 0x3f3f3f3f;

int dr[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dc[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int row, col;
int ocean[maxn][maxn];
int steps[maxn][maxn];
bool visited[maxn][maxn];
int sr, sc, er, ec;

bool in_ocean(int r, int c) {
	if (r < 0 || r >= row || c < 0 || c >= col)
		return false;
	return true;
}

int work() {
	deque<PII> deq;
	deq.push_back(make_pair(sr, sc));

	while (!deq.empty()) {
		PII pii = deq.front(); deq.pop_front();
		if (visited[pii.first][pii.second])
			continue;

		visited[pii.first][pii.second] = true;
		if (pii.first == er && pii.second == ec) {
			break;
		}

		for (int i = 0; i < 8; i++) {
			int nr = pii.first + dr[i];
			int nc = pii.second + dc[i];
			int flag = ocean[pii.first][pii.second] == i ? 0 : 1;
			if (in_ocean(nr, nc) && flag + steps[pii.first][pii.second] < steps[nr][nc]) {
				steps[nr][nc] = steps[pii.first][pii.second] + flag;
				if (!flag) {
					deq.push_front(make_pair(nr, nc));
				}
				else {
					deq.push_back(make_pair(nr, nc));
				}
			}
		}//for int i
	}//while

	return steps[er][ec];
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			char ch;
			cin >> ch;
			ocean[i][j] = ch - '0';
		}
	}

	int kasenum;
	cin >> kasenum;
	while (kasenum--) {
		cin >> sr >> sc >> er >> ec;
		sr--; sc--; er--; ec--;
		memset(steps, 0x3f, sizeof(steps));
		memset(visited, false, sizeof(visited));
		steps[sr][sc] = 0;
		cout << work() << endl;
	}

	return 0;
}