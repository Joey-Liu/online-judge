#include <iostream>
#include <memory.h>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

const int maxn = 150;


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int tab[maxn][maxn];
	int N;

	cin >> N;
	string str;
	stringstream ss;

	memset(tab, 0, sizeof(tab));

	for (int i = 2; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			cin >> str;
			if (str[0] == 'x') {
				tab[i][j] = tab[j][i] = INT_MAX;
			}
			else {
				ss.clear();
				ss.str("");
				ss << str;
				int t;
				ss >> t;
				tab[i][j] = tab[j][i] = t;
			}
		}
	}

	int dist[maxn];
	for (int i = 1; i <= N; i++) {
		dist[i] = tab[1][i];
	}

	bool visited[maxn];
	memset(visited, false, sizeof(visited));
	visited[1] = true;

	for (int i = 2; i <= N; i++) {
		
		int mini = INT_MAX, ind = -1;
		for (int j = 1; j <= N; j++) {
			if (visited[j])
				continue;
			if (mini > dist[j]) {
				mini = dist[j];
				ind = j;
			}
		}

		visited[ind] = true;
		for (int j = 1; j <= N; j++) {
			if (tab[ind][j] != INT_MAX)
				dist[j] = min(dist[j], dist[ind] + tab[ind][j]);
		}
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		ans = max(ans, dist[i]);
	}
	cout << ans << endl;
	return 0;
}