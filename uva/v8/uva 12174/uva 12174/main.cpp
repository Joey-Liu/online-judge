#include <iostream>
#include <stdio.h>
#include <memory.h>

using namespace std;

int S, N;
const int maxn = 100000 + 5;
int x[maxn * 3], cnt[maxn];
bool ok[maxn * 3];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int kasenum = 0;
	cin >> kasenum;
	while (kasenum--) {
		cin >> S >> N;
		fill(x, x + N + S * 2, -1);
		fill(ok, ok + N + S * 2, false);
		memset(cnt, 0, sizeof(cnt));

		for (int i = S; i < S + N; i++) {
			cin >> x[i];
		}

		int tot = 0;

		for (int i = 0; i < S + N; i++) {
			if (i < S && i == tot)
				ok[i] = true;
			if (i > N && i - N == S - tot)
				ok[i] = true;
			if (tot == S)
				ok[i] = true;

			if (x[i] != -1 && --cnt[x[i]] == 0)
				tot--;
			if (x[i + S] != -1 && ++cnt[x[i + S]] == 1)
				tot++;
		}

		int ans = 0;
		for (int i = 0; i < S; i++) {
			bool valid = true;
			for (int j = i; j < N + S; j += S) {
				if (!ok[j]) {
					valid = false;
					break;
				}
			}
			if (valid)
				ans++;
		}
		if (ans == N + 1)
			ans = S;
		cout << ans << endl;
	}//while kasenum
	return 0;
}