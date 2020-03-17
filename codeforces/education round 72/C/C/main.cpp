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

const int maxn = 300000 + 10;
int nxt[maxn];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);


	string str;
	int casenum = 0;
	cin >> casenum;
	while (casenum--) {
		cin >> str;
		
		memset(nxt, 0, sizeof(nxt));
		int len = str.size(), res = 0;
		for (int i = 0; i < len; i++) {
			if (str[i] == '1') {
				nxt[i] = i;
			}
			else {
				nxt[i] = (i == 0 ? -1 : nxt[i - 1]);
			}
		}

		for (int rp = 0; rp < len; rp++) {
			int num = 0;
			for (int lp = rp; lp >= 0 && rp - lp < 20; lp--) {
				if (str[lp] == '0')
					continue;
				num += (1 << (rp - lp));
				if (num <= rp - (lp == 0 ? -1 : nxt[lp - 1])) {
					res++;
				}
			}
		}
		cout << res << endl;
	}
	return 0;

}