#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;
typedef long long LL;

LL n, w;
const int maxn = 1000 + 10;

LL a[maxn], ps[maxn];
bool flag = true;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> w;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] > w)
			flag = false;
		if (a[i] < -w)
			flag = false;
		ps[i] = a[i] + ps[i - 1];
	}

	LL maxi = ps[1], mini = ps[1];
	
	for (int i = 1; i <= n; i++) {
		maxi = max(maxi, ps[i]);
		mini = min(mini, ps[i]);
	}
	
	if (maxi > w) {
		flag = false;
	}
	if (mini < -w) {
		flag = false;
	}
	if(flag) {
		maxi = max(0LL, maxi);
		mini = min(0LL, mini);
		LL res = w - maxi + mini + 1;
		if (res < 0)
			cout << 0 << endl;
		else
			cout << res << endl;
	}
	else {
		cout << 0 << endl;
	}
}