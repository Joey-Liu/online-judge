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
const int maxn = 5e3 + 10;
int dp[maxn], N, M;
int V[maxn], W[maxn], C[maxn];

void zero_one(int v, int w) {
	for (int i = N; i >= v; i--) {
		dp[i] = max(dp[i], dp[i - v] + w);
	}
}

void comp(int v, int w) {
	for (int i = v; i <= N; i++) {
		dp[i] = max(dp[i], dp[i - v] + w);
	}
}

void multi_pack(int v, int w, int cnt) {
	if (cnt * v >= N) {
		comp(v, w);
		return;
	}

	for (int i = 1; i <= cnt; i <<= 1) {
		zero_one(i * v, i * w);
		cnt -= i;
	}

	zero_one(cnt * v, cnt * w);
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> V;
	for (int i = 0; i < N; i++) {
		cin >> V[i] >> W[i] >> C[i];
	}

	for (int i = 0; i < N; i++) {
		multi_pack(V[i], W[i], C[i]);
	}

	cout << dp[N] << endl;
	return 0;
}