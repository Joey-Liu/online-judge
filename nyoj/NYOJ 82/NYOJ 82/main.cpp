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

const int maxn = 20 + 5;
int M, N;
char mapp[maxn][maxn];
int keys[6];
//PII doors[6];

vector<PII> doors[6];

bool visited[maxn][maxn];

const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, 1, 0, -1 };
	
bool in_map(int r, int c, int row, int col) {
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

	while (cin >> M >> N && M && N) {
		for (int i = 0; i < M; i++) {
			cin >> mapp[i];
		}
		memset(keys, 0, sizeof(keys));
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < 6; i++) {
			doors[i].clear();
		}

		int sr = -1, sc = -1;
		int er = -1, ec = -1;
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (mapp[i][j] >= 'a' && mapp[i][j] <= 'e') {
					keys[mapp[i][j] - 'a']++;
				}
				if (mapp[i][j] >= 'A' && mapp[i][j] <= 'E') {
					doors[mapp[i][j] - 'A'].push_back(make_pair(i, j));
				}
				if (mapp[i][j] == 'S') {
					sr = i;
					sc = j;
				}
				if (mapp[i][j] == 'G') {
					er = i;
					ec = j;
				}
			}//for int j
		}//for int i

		visited[sr][sc] = true;
		bool flag = false;
		queue<PII> que;
		que.push(make_pair(sr, sc));

		for (int nk = 0; nk < 6; nk++) {
			if (!keys[nk]) {
				for (int i = 0; i < doors[nk].size(); i++) {
					int r = doors[nk][i].first;
					int c = doors[nk][i].second;
					if (visited[r][c]) {
						que.push(make_pair(r, c));
					}
					else {
						mapp[r][c] = '.';
					}
				}
			}
		}

		while (!que.empty()) {
			PII pii = que.front(); que.pop();
			for (int i = 0; i < 4; i++) {
				int nr = pii.first + dr[i];
				int nc = pii.second + dc[i];
				
				if (in_map(nr, nc, M, N) && !visited[nr][nc]) {
					if (mapp[nr][nc] == 'X')
						continue;
					if (mapp[nr][nc] == 'G') {
						flag = true;
						break;
					}
					if (mapp[nr][nc] >= 'a' && mapp[nr][nc] <= 'e') {
						int nk = mapp[nr][nc] - 'a';
						keys[nk]--;
						
						/*
						if (keys[nk] == 0 && visited[doors[nk].first][doors[nk].second]) {
							que.push(make_pair(doors[nk].first, doors[nk].second));
						}
						if (keys[nk] == 0 && !visited[doors[nk].first][doors[nk].second]) {
							mapp[doors[nk].first][doors[nk].second] = '.';
						}*/

						if (keys[nk] == 0) {
							for (int i = 0; i < doors[nk].size(); i++) {
								int r = doors[nk][i].first;
								int c = doors[nk][i].second;
								if (visited[r][c]) {
									que.push(make_pair(r, c));
								}
								else {
									mapp[r][c] = '.';
								}
							}
						}

						que.push(make_pair(nr, nc));
						visited[nr][nc] = true;
					} else if (mapp[nr][nc] >= 'A' && mapp[nr][nc] <= 'E') {
						visited[nr][nc] = true;
					}
					else {
						visited[nr][nc] = true;
						que.push(make_pair(nr, nc));
					}
				}
			}//for int i

			if (flag)
				break;
		}//while

		if (flag) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}//while

	return 0;
}