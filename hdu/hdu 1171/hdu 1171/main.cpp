#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <algorithm>

using namespace std;

const int maxn = 255555;
int N, C[60], W[60], tar;
bool dp[maxn];

void zeroone_pack(int weight) {
	for (int i = tar; i >= weight; i--) {
		dp[i] = (dp[i] || dp[i - weight]);
	}
}

void comp_pack(int weight) {
	for (int i = weight; i <= tar; i++) {
		dp[i] = (dp[i] || dp[i - weight]);
	}
}


void multi_pack(int weight, int cnt) {
	if (cnt * weight >= tar) {
		comp_pack(weight);
		return;
	}
	for (int i = 1; i <= cnt; i *= 2) {
		zeroone_pack(i * weight);
		cnt -= i;
	}
	zeroone_pack(cnt * weight);
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (cin >> N && N >= 0) {
		tar = 0;
		for (int i = 0; i < N; i++) {
			cin >> W[i] >> C[i];
			tar += W[i] * C[i];
		}

		int tmp = tar;
		tar /= 2;
		memset(dp, false, sizeof(dp));
		dp[0] = true;

		for (int i = 0; i < N; i++) {
			multi_pack(W[i], C[i]);
		}

		int ind = tar;
		for (; ind >= 0; ind--) {
			if (dp[ind])
				break;
		}

		cout << tmp - ind << " " << ind << endl;
	}//while
	return 0;
}