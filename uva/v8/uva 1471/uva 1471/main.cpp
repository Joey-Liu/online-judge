#include <iostream>
#include <stdio.h>
#include <set>
#include <algorithm>

using namespace std;

const int maxn = 200000 + 5;
int N, a[maxn], g[maxn], f[maxn];

struct Cadi {
	int a, g;
	Cadi(int _a, int _g) : a(_a), g(_g) {}

	bool operator < (const Cadi ca) const {
		return a < ca.a;
	}
};

set<Cadi> sc;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int kasenum;
	cin >> kasenum;
	while (kasenum--) {
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> a[i];
		
		sc.clear();
		g[0] = 1; f[N - 1] = 1;
		for (int i = 1; i < N; i++) {
			if (a[i] > a[i - 1])
				g[i] = g[i - 1] + 1;
			else
				g[i] = 1;
		}
		for (int i = N - 2; i >= 0; i--) {
			if (a[i] < a[i + 1])
				f[i] = f[i + 1] + 1;
			else
				f[i] = 1;
		}

		sc.insert(Cadi(a[0], g[0]));
		int res = 1;
		for (int i = 1; i < N; i++) {
			Cadi ca(a[i], g[i]);
			set<Cadi>::iterator it = sc.lower_bound(ca);
			bool flag = true;

			if (it != sc.begin()) {
				Cadi la = *(--it);
				int t = la.g + f[i];
				res = max(res, t);
				if (it->g >= ca.g)
					flag = false;
			}
			if (flag) {
				sc.erase(ca);
				sc.insert(ca);
				set<Cadi>::iterator it = sc.find(ca);
				++it;
				while (it != sc.end()) {
					if (it->a > ca.a && it->g < ca.g)
						sc.erase(it++);
					else
						break;
				}
			}
		}//for int i
		cout << res << endl;
	}//while kasenum 
	return 0;
}