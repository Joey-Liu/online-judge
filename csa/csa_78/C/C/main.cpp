#include <iostream>
#include <memory.h>
#include <string>
#include <math.h>

using namespace std;
typedef long long LL;

const int maxn = 10;
int banned_nu = 0;
bool banned[maxn];
string s;


LL work(string str)
{
	if (str.size() == 0)
		return 0;

	LL ans = 0, cnt = 0;
	for (int i = 0; i < str[0] - '0'; i++) {
		if (!banned[i])
			cnt += 1;
	}
	ans = cnt;
	for(int i = 0;i < str.size() - 1;i++)
		ans = ans * (10 - banned_nu);

	if (!banned[str[0] - '0'])
		return ans + work(str.substr(1));
	else
		return ans;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	memset(banned, false, sizeof(banned));
	banned_nu = 0;
	for (int i = 0; i < 10; i++) {
		int t;
		cin >> t;
		if (t) {
			banned[i] = true;
			banned_nu += 1;
		}
	}
	cin >> s;
	LL ans = work(s);

	if (banned[0]) {
		int K = s.size() - 1;
		LL res = 0;
		for (int i = 0; i < s.size() - 1; i++) {
			res += pow(10 - banned_nu, K);
			K--;
		}
		ans += res;
	}
	cout << ans << endl;
}