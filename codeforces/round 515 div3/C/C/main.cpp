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

const int maxn = 6 * 1e5;

int N, lp, rp, id;
map<int, int> tab;
char ch;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	
	cin >> N;
	cin >> ch >> id;
	tab[id] = 0;
	lp = -1, rp = 1;

	for (int i = 1; i < N; i++) {
		cin >> ch >> id;
		if (ch == 'L') {
			tab[id] = lp;
			lp--;
		}
		else if (ch == 'R') {
			tab[id] = rp;
			rp++;
		}
		else {
			int k1 = tab[id] - lp - 1;
			int k2 = rp - tab[id] - 1;
			cout << min(k1, k2) << endl;
		}
	}

	return 0;
}