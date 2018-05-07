#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int kasenum;
	cin >> kasenum;
	while (kasenum--) {
		int n;
		cin >> n;
		vector<int> vi(n);
		for (int i = 0; i < n; i++)
			cin >> vi[i];

		int lp = 0, rp = 1, res = 1;
		set<int> si;
		si.insert(vi[0]);
		while (rp < n) {
			if (!si.count(vi[rp])) {
				si.insert(vi[rp++]);
			}
			else {
				while (si.count(vi[rp])) {
					si.erase(vi[lp]);
					lp++;
				}
			}
			res = max(res, rp - lp);
		}//while rp
		cout << res << endl;
	}//while kasenum
	return 0;
}