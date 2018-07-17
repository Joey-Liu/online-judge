#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <string>
#include <set>

using namespace std;
const int maxn = 100000 + 20;
typedef long long LL;

string s[3];

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int ans = 0;
	for (int i = 0; i < 3; i++)
		cin >> s[i];
	int N = s[0].size();

	for (int i = 0; i < N; i++) {
		set<char> sc;
		for (int j = 0; j < 3; j++) {
			sc.insert(s[j][i]);
		}
		ans += sc.size() - 1;
	}
	cout << ans << endl;
	return 0;
}