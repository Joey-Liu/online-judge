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
string maze[maxn];
int M, N, sr, sc, x, y;


int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };

bool in_maze(int r, int c, int row, int col) {
	if (r < 0 || r >= row || c < 0 || c >= col)
		return false;
	return true;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> N >> M;
	cin >> sr >> sc >> x >> y;
	for (int i = 0; i < N; i++) {
		cin >> maze[i];
	}

	queue<pair<PII, PII> > que;
	PII start_point, steps;
	start_point.first = sr - 1;
	start_point.second = sc - 1;
	steps.first = x;
	steps.second = y;

	que.push(make_pair(start_point, steps));
	map<PII, vector<PII>> tab;
	tab[start_point] = vector<PII> ();
	tab[start_point].push_back(steps);
	int res = 1;

	while (!que.empty()) {
		pair<PII, PII> ppp = que.front(); que.pop();
		PII point = ppp.first, steps = ppp.second;

		int r = point.first, c = point.second;
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			int x = steps.first, y = steps.second;
			if (i == 1)
				y--;
			if (i == 3)
				x--;

			if (x < 0 || y < 0)
				continue;
			if (!in_maze(nr, nc, N, M) || maze[nr][nc] == '*')
				continue;
			
			PII n_point = make_pair(nr, nc);
			PII n_steps = make_pair(x, y);
			bool flag = false;

			if (!tab.count(n_point)) {
				tab[n_point] = vector<PII>();
				tab[n_point].push_back(n_steps);
				flag = true;
				res++;
			}
			else {
				flag = true;
				for(int j = 0; j < tab[n_point].size(); j++) {
					PII prev_step = tab[n_point][j];
					if (prev_step.first >= x && prev_step.second >= y)  {
						flag = false;
						break;
					}
				}
				if(flag)
					tab[n_point].push_back(n_steps);
			}
			
			if(flag)
				que.push(make_pair(n_point, n_steps));
		}//for int i

	}//while
	cout << res << endl;

	return 0;
}