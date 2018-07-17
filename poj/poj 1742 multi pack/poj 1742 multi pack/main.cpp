#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <memory>
#include <string>
#include <string.h>


using namespace std;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 60;


int N, M, dp[maxn];
int A[maxn], C[maxn];

inline void zeroone_pack(int v, int w) {
	for (int i = M; i >= v; i--) {
		if (dp[i] > dp[i - v] + w) {
			dp[i] = dp[i - v] + w;
		}
	}
}

inline void comp_pack(int v, int w) {
	for (int i = v; i <= M; i++) {
		if (dp[i] > dp[i - v] + w) {
			dp[i] = dp[i - v] + w;
		}
	}
}

inline void multi_pack(int v, int w, int cnt) {
	if (cnt * v >= M) {
		comp_pack(v, w);
		return;
	}

	for (int i = 1; i <= cnt; i <<= 1) {
		zeroone_pack(i * v, i * w);
		cnt -= i;
	}
	zeroone_pack(cnt * v, cnt * w);
}


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d%d", &N, &M);
	while (N && M) {
		for (int i = 0; i < N; i++) {
			scanf("%d", &A[i]);
		}

		memset(dp, 0x3f, sizeof(dp));
		dp[0] = 0;
		for (int i = 0; i < N; i++) {
			int tmp;
			scanf("%d", &tmp);
			multi_pack(A[i], 1, tmp);
		}

		int ans = 0;
		for (int i = 1; i <= M; i++) {
			if (dp[i] < inf)
				ans++;
		}
		printf("%d\n", ans);
		scanf("%d%d", &N, &M);
	}
	return 0;
}