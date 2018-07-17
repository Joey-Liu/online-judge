#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;
const int maxn = 200000 + 20;
int status[maxn], N;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	string s, p;
	cin >> N >> s >> p;
	for (int i = 0; i < N; i++) {
		if (s[i] == p[i])
			status[i] = 1;
		else
			status[i] = 0;
	}

	int ans = 0, st = 1;
	for (int i = 0; i < N; i++) {
		if (1 == st && 1 == status[i]) {
			st = 1;
		}
		else if (1 == st && 0 == status[i]) {
			st = 0;
		}
		else if (0 == st && 0 == status[i]) {
			st = 0;
		}
		else {
			ans++;
			st = 1;
		}
	}
	if (st == 0)
		ans++;
	cout << ans << endl;


	return 0;
}