#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 1000 + 20;
string names[maxn];
int N;

bool cmp(string s1, string s2) {
	return s1 < s2;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (cin >> N && N) {
		for (int i = 0; i < N; i++) {
			cin >> names[i];
		}
		sort(names, names + N, cmp);

		string s1 = names[N / 2 - 1], s2 = names[N / 2];
		string ans = "";
		int ind = 0;
		while (ind < min(s1.size(), s2.size()) - 1) {
			if (s1[ind] == s2[ind]) {
				ans += s1[ind++];
			}
			else {
				string tmp = ans;
				ans += char(s1[ind] + 1);
				if(ans != s2)
					break;
				ans = tmp;
				ans += s1[ind++];
			}
		}
		if (ans < s1)
			ans = s1;
		cout << ans << endl;
	}

	return 0;
}