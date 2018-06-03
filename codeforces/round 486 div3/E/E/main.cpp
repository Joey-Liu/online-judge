#include <iostream>
#include <map>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

string nu;
const string ss[] = { "00", "25", "50", "75" };

int work(string str, string s) 
{
	int N = str.size();
	if (N < 2)
		return -1;

	int cnt = 0;
	for (int i = 1; i >= 0; i--) {
		if (s[i] == str[N - 2 + i])
			continue;
		int j = 0;
		for (j = N - 2 + i; j >= 0; j--) {
			if (str[j] == s[i])
				break;
		}
		if (j == -1)
			return -1;

		for (int k = j; k < N - 2 + i; k++) {
			swap(str[k], str[k + 1]);
			cnt++;
		}
	}//for int i

	if (str[0] == '0') {
		int i = 0;
		for (i = 1; i < N; i++) {
			if (str[i] != '0')
				break;
		}
		if (i == N) {
			return -1;
		}

		for (int j = i; j > 0; j--) {
			swap(str[j], str[j - 1]);
			cnt++;
		}
	}
	return cnt;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int ans = 0x3f3f3f3f;
	cin >> nu;
	for (int i = 0; i < 4; i++) {
		int t = work(nu, ss[i]);
		if (t >= 0)
			ans = min(ans, t);
	}
	if (ans == 0x3f3f3f3f)
		cout << "-1" << endl;
	else
		cout << ans << endl;
	return 0;
}