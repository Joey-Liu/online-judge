#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;

const int maxn = 2e+5 + 10;
int pos[maxn], N;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		int t;
		cin >> t;
		pos[t] = i;
	}

	int prev = N + 1, cur = 0;
	int res = 0;
	for (int i = N; i >= 1; i--) {
		if (pos[i] < prev) {
			cur++;
			res = max(cur, res);
		}
		else {
			cur = 1;
		}
		prev = pos[i];
	}
	cout << N - res << endl;
	return 0;
}