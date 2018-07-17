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

using namespace std;
int N;

string a, b;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	cin >> N;
	cin >> a >> b;

	int ans = 0;
	for (int i = 0; i < N / 2; i++) {
		map<char, int> tab;
		set<char> sa, sb;
		sa.insert(a[i]); sa.insert(a[N - 1 - i]);
		sb.insert(b[i]); sb.insert(b[N - 1 - i]);

		tab[a[i]]++;
		tab[b[i]]++;
		tab[a[N - 1 - i]]++;
		tab[b[N - 1 - i]]++;

		if (tab.size() == 1)
			continue;
		else if (tab.size() == 2 && sa.size() == sb.size())
			continue;
		else if (tab.size() == 2 && sa.size() != sb.size())
			ans += 1;
		else if (tab.size() == 4)
			ans += 2;
		else if (tab.size() == 3) {
			if (1 == sa.size())
				ans += 2;
			else
				ans += 1;
		}
	}

	if (N % 2) {
		int p = N / 2;
		if (a[p] != b[p])
			ans += 1;
	}
	cout << ans << endl;
	return 0;
}