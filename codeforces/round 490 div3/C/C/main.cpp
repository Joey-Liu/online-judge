#include <iostream>
#include <stdio.h>
#include <set>
#include <map>
#include <string>
#include <memory.h>

using namespace std;

const int maxn = 400000 + 10;

bool visited[maxn];
int N, K;
string str;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	cin >> N >> K;
	cin >> str;
	map<int, set<int>> tab;
	for (int i = 0; i < N; i++) {
		tab[str[i]].insert(i);
	}
	memset(visited, true, sizeof(visited));

	for (int i = 0; i < K; i++) {
		char c = tab.begin()->first;
		int index = *(tab[c].begin());
		visited[index] = false;
		tab[c].erase(index);
		if (tab[c].size() == 0)
			tab.erase(c);
	}
	string ans = "";
	for (int i = 0; i < N; i++) {
		if (visited[i]) {
			ans += str[i];
		}
	}
	cout << ans << endl;
	return 0;
}