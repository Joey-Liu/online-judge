#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <memory.h>

using namespace std;
const int maxn = 13000;
const int ma = 3500;
int N, M, weight, desi;
int dp[maxn];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> weight >> desi;
		for (int j = M; j >= weight; j--) {
			dp[j] = max(dp[j], dp[j - weight] + desi);
		}
	}
	cout << dp[M]<<endl;

	return 0;
}