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

const int maxn = 25000 + 50;
int N, T;
struct Node {
	int lp, rp;
};

bool cmp(Node n1, Node n2) {
	if (n1.lp != n2.lp)
		return n1.lp < n2.lp;
	return n1.rp > n2.rp;
}

Node nodes[maxn];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> N >> T;
	for (int i = 0; i < N; i++) {
		cin >> nodes[i].lp >> nodes[i].rp;
	}

	sort(nodes, nodes + N, cmp);
	if (nodes[0].lp > 1) {
		cout << -1 << endl;
		return 0;
	}

	int prev = 0, max_reach = nodes[0].rp, cnt = 1;
	while (prev < N && max_reach < T) {
		
		int tmp = -1, i;
		for (i = prev; i < N && nodes[i].lp <= max_reach + 1; i++) {
			tmp = max(tmp, nodes[i].rp);
		}

		if (tmp <= max_reach)
			break;
		cnt++;
		max_reach = tmp;
		prev = i;
	}

	if (max_reach < T) {
		cout << -1 << endl;
	}
	else {
		cout << cnt << endl;
	}

	return 0;
}