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


const LL maxn = 2e5 + 50;
const LL mode = LL(998244353);
LL N, M;
string s1, s2;

LL A[maxn] = { 0 }, B[maxn] = { 0 };
LL tab[maxn] = { 0 }, cnt[maxn] = { 0 };

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	

	cin >> N >> M;
	cin >> s1 >> s2;
	for (LL i = s1.size() - 1, ind = 0; i >= 0; i--, ind++) {
		A[ind] = s1[i] - '0';
	}
	for (LL i = s2.size() - 1, ind = 0; i >= 0; i--, ind++) {
		B[ind] = s2[i] - '0';
	}

	tab[0] = 1;
	for (LL i = 1; i < N; i++) {
		tab[i] = (tab[i - 1] << 1) % mode;
	}
	
	for (LL i = M - 1; i >= 0; i--) {
		cnt[i] = cnt[i + 1] + B[i];
	}

	LL res = 0;
	for (int i = 0; i < N; i++) {
		if (A[i]) {
			res = (res + (tab[i] * cnt[i]) % mode) % mode;
		}
	}
	cout << res << endl;

	return 0;
}