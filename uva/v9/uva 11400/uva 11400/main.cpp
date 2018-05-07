#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

const int maxn = 1000 + 10;
const int INF = 0x3f3f3f3f;
int pre_sum[maxn];
struct Node {
	int volt;
	int K;
	int C;
	int L;
};
Node nodes[maxn];
int node[maxn], N, dp[maxn];

bool cmp(Node n1, Node n2) 
{
	return n1.volt < n2.volt;
}

void work()
{
	memset(pre_sum, 0, sizeof(pre_sum));
	for (int i = 1; i <= N; i++) {
		pre_sum[i] = pre_sum[i - 1] + nodes[i].L;
	}

	dp[0] = 0;
	for (int i = 1; i <= N; i++) {
		dp[i] = INF;
		for (int j = 0; j < i; j++) {
			dp[i] = min(dp[i], dp[j] + (pre_sum[i] - pre_sum[j]) * nodes[i].C + nodes[i].K);
		}
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (cin >> N && N) {
		for (int i = 1; i <= N; i++) {
			cin >> nodes[i].volt >> nodes[i].K >> nodes[i].C >> nodes[i].L;
		}
		sort(nodes + 1, nodes + N + 1, cmp);
		work();
		cout << dp[N] << endl;
	}
	return 0;
}