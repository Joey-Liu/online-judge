#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;

const int maxn = 10000 + 5;
typedef long long LL;

int N, M, K;
struct Node {
	LL a, b;
	int id;
	LL rate;
};
Node nodes[maxn];

bool cmp(Node n1, Node n2) {
	if (n1.rate != n2.rate)
		return n1.rate > n2.rate;
	return n1.id > n2.id;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		cin >> nodes[i].a >> nodes[i].b;
		nodes[i].id = i;
		nodes[i].rate = nodes[i].a * M + nodes[i].b * (N - M);
	}

	sort(nodes, nodes + K, cmp);
	int ind = nodes[0].id;

	for (int i = 0; i < ind; i++) {
		cout << "0 ";
	}
	cout << N;
	for (int i = ind + 1; i < K; i++) {
		cout << " 0";
	}
	return 0;
}