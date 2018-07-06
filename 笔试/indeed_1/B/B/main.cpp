#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>

using namespace std;
typedef long long LL;

const int maxn = 100000 + 50;
LL A[maxn], ps[maxn], N, Q;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	cin >> A[0];
	if (A[0] < 0)
		A[0] = -A[0];
	ps[0] = A[0];
	for (int i = 1; i < N; i++) {
		cin >> A[i];
		if (A[i] < 0)
			A[i] = -A[i];
		ps[i] = A[i] + ps[i - 1];
	}

	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		LL ans = ps[y] - ps[x] + A[x];
		cout << ans << endl;
	}

	return 0;
}