#include <iostream>
#include <algorithm>


using namespace std;
const int maxn = 100000 + 50;

struct Intern {
	int lp;
	int rp;
	int num;
};

Intern intern[maxn];
int group;

bool cmp(Intern a, Intern b) {
	if (a.rp != b.rp)
		return a.rp < b.rp;
	return a.lp > b.lp;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int kasenum = 0;
	cin >> kasenum;
	while (kasenum--) {
		int t1, t2;
		char ch;
		cin >> group;
		for (int i = 0; i < group; i++) {
			cin >> intern[i].num;
			cin >> t1 >> ch >> t2;
			intern[i].lp = t1 * 60 + t2;
			cin >> t1 >> ch >> t2;
			intern[i].rp = t1 * 60 + t2;
		}

		sort(intern, intern + group, cmp);
		int res = intern[0].num, ans = -1;
		int bound = intern[0].rp;
		for (int i = 1; i < group; i++) {
			if (intern[i].lp < bound) {
				res += intern[i].num;
			}
			else {
				ans = max(ans, res);
				res = intern[i].num;
			}
		}//for int i
		ans = max(ans, res);
		cout << ans << endl;
	}
	return 0;
}