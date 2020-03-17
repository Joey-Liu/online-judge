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


struct Node {
	int a, b;
	int cnt;
};

bool cmp(Node& n1, Node& n2) {
	return n1.cnt > n2.cnt;
}

int gcd(int a, int b) {
	int c = 0;
	while (b != 0) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int N;
Node nodes[maxn];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> nodes[i].a;
	}
	for (int i = 0; i < N; i++) {
		cin >> nodes[i].b;
	}

	for (int i = 0; i < N; i++) {
		if (nodes[i].a != 0 && nodes[i].b != 0) {
			int t = gcd(nodes[i].a, nodes[i].b);
			nodes[i].a /= t;
			nodes[i].b /= t;
		}
		if (nodes[i].a != 0 && nodes[i].b == 0) {
			nodes[i].a = 13;
		}
	}
	map<pair<int, int>, int> tab;
	for (int i = 0; i < N; i++) {
		tab[make_pair(nodes[i].a, nodes[i].b)]++;
	}

	pair<int, int> pii(0, 0);
	int res = tab[pii];
	if (tab[pii])
		tab.erase(pii);
	
	vector<Node> vn(tab.size());
	int ind = 0;
	for (auto it = tab.begin(); it != tab.end(); it++) {
		Node node;
		node.a = it->first.first;
		node.b = it->first.second;
		node.cnt = it->second;
		vn[ind++] = node;
	}
	
	

	sort(vn.begin(), vn.end(), cmp);

	for (int i = 0; i < vn.size(); i++) {
		if (vn[i].a == 0 && vn[i].b != 0)
			continue;
		else {
			res += vn[i].cnt;
			break;
		}
	}
	cout << res << endl;

	return 0;
}