#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
	int ind;
	int lp;
	int rp;
};

const int maxn = 3 * 100000 + 50;
Node nodes[maxn];
int N;

bool cmp(Node n1, Node n2) {
	if (n1.lp != n2.lp)
		return n1.lp < n2.lp;
	return n1.rp > n2.rp;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> N;
	for (int i = 0; i < N; i++) {
		nodes[i].ind = i + 1;
		cin >> nodes[i].lp >> nodes[i].rp;
	}

	sort(nodes, nodes + N, cmp);
	int a = -1, b = -1;
	for (int i = 0; i < N - 1; i++) {
		if (nodes[i].lp <= nodes[i + 1].lp && nodes[i].rp >= nodes[i + 1].rp) {
			a = nodes[i].ind;
			b = nodes[i + 1].ind;
			break;
		}
	}
	cout << b << " " << a << endl;
	return 0;
}