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

LL N;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	vector<vector<int> > ans;

	while(cin >> N && N) {
		LL st = 1, ed = 2;
		LL square = st * st;
		ans.clear();
		while (true) {
			while (square < N && ed * ed <= N) {
				square += ed * ed;
				ed++;
			}//while

			while (square >= N) {
				if (square == N) {
					vector<int> vi;
					for (int i = st; i < ed; i++) {
						vi.push_back(i);
					}
					ans.push_back(vi);
				}
				square -= st * st;
				st++;
			}
			if (ed * ed > N)
				break;
		}
		cout << ans.size() << endl;
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i].size();
			for (int j = 0; j < ans[i].size(); j++) {
				cout << " " << ans[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}