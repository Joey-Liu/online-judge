#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>

using namespace std;

typedef long long LL;
map<LL, LL> tab;
int N;


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	cin >> N;
	LL su = 0, t= 0;
	for (int i = 0; i < N; i++) {
		cin >> t;
		su += t;
		tab[su]++;
	}

	LL ans = 0;
	for (map<LL, LL>::iterator it = tab.begin(); it != tab.end(); it++) {
		if (it->first == 0) {
			ans += it->second;
		}
		if (it->second >= 2) {
			t = it->second;
			ans += t * (t - 1) / 2;
		}
	}
	cout << ans << endl;
}