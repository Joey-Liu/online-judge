#include <iostream>
#include <string>
#include <memory.h>

using namespace std;

const int maxn = 200000 + 10;
typedef long long LL;

LL a[maxn], ps[maxn], le[maxn];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		ps[i] = a[i] + ps[i - 1];
	}

	for (int i = 1; i <= m; i++) {
		cin >> le[i];
	}

	int i = 1, j = 1;
	while (j <= m) {
		if (le[j] > ps[i])
			i++;
		else {
			cout << i << " ";
			cout << le[j] - ps[i - 1] << endl;
			j++;
		}
	}//while
	return 0;
}