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
#include <math.h>
#include <functional>
#include <limits.h>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;

const int maxn = 200000 + 10;
int nums[maxn], N, K;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> K;
	map<int, int> tab;
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
		tab[nums[i] % K]++;
	}

	int res = 0;
	for (int i = 0; i <= K / 2; i++) {
		int j = (K - i) % K;
		if (i != j) {
			int t = min(tab[i], tab[j]);
			res += 2 * t;
			tab[i] -= t;
			tab[j] -= t;
		}
		else {
			int t = tab[i] / 2;
			res += t * 2;
			tab[i] -= t * 2;
		}
	}
	cout << res << endl;
	return 0;
}