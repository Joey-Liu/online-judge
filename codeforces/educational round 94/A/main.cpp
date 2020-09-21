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

const int maxn = 100000 + 10;
int N;
string str;
string subs[maxn];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int kasenum = 0;
	cin >> kasenum;
	while (kasenum--) {
		cin >> N >> str;

		set<int> si;
		for (int i = 0; i < N; i++) {
			subs[i] = str.substr(i, N);
			si.insert(i);
		}

		string res = "";
		bool done = false;
		for (int i = 0; i < N; i++) {
			int tmp = 0;
			if (si.size() == 0) {
				done = true;
			}

			if (done) {
				res += '0';
				continue;
			}

			for (auto it = si.begin(); it != si.end(); ++it) {
				int ind = *it;
				tmp += (subs[ind][i] - '0');
			}

			if (tmp >= 1) {
				res += '1';
				for (auto it = si.begin(); it != si.end(); ) {
					int ind = *it;
					if (subs[ind][i] == '1') {
						si.erase(it++);
					}
					else {
						it++;
					}
				}
			}
			else {
				res += '0';
				done = true;
			}
		}

		cout << res << endl;

	}// while
	return 0;
}