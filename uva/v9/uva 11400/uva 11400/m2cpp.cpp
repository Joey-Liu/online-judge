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

using namespace std;
const int maxn = 1000 + 50;

struct Node {
	int V, K, C, L;
};

Node nodes[maxn];
int N, dp[maxn], pre_sum[maxn];

bool cmp(Node & n1, Node & n2) {
	return n1.V < n2.V;
}


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	string s = "test";
	string t = reverse(s.begin(), s.end());
	while (cin >> N && N) {
		for (int i = 0; i < N; i++)
			cin >> nodes[i].V >> nodes[i].K >> nodes[i].C >> nodes[i].L;
		
		sort(nodes, nodes + N, cmp);
		pre_sum[0] = nodes[0].L;
		for (int i = 1; i < N; i++)
			pre_sum[i] = pre_sum[i - 1] + nodes[i].L;

		memset(dp, 0x3f, sizeof(dp));
		for (int i = 0; i < N; i++) {
			dp[i] = pre_sum[i] * nodes[i].C + nodes[i].K;
			for (int j = 1; j <= i; j++) {
				dp[i] = min(dp[i], (pre_sum[i] - pre_sum[j - 1]) * nodes[i].C + nodes[i].K + dp[j - 1]);
			}//for int j
		}//for int i
		cout << dp[N - 1] << endl;
	}//while
	return 0;
}