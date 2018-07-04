#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	map<int, int> tab;
	int N, a;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a;
		tab[a]++;
	}

	int ans = 0;
	for (auto it = tab.begin(); it != tab.end(); it++) {
		ans = max(ans, it->second);
	}
	cout << ans << endl;

	return 0;
}