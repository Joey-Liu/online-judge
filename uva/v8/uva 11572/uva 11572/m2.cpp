#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
const int maxn = 1000000 + 5;

map<int, int> cur;
int last[maxn], A[maxn], N;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int kasenum;
	cin >> kasenum;
	while (kasenum--) {
		cur.clear();
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> A[i];
			if (cur.count(A[i]))
				last[i] = cur[A[i]];
			else
				last[i] = -1;
			cur[A[i]] = i;
		}
		
		int lp = 0, rp = 0, ans = 0;
		while (rp < N) {
			if (last[rp] < lp)
				rp++;
			else {
				lp++;
			}
			ans = max(ans, rp - lp);
		}
		cout << ans << endl;
	}
	return 0;
}