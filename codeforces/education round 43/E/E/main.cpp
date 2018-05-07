#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>

using namespace std;

const int maxn = 200000 + 10;
typedef long long LL;

int N, A, B;
struct Node {
	LL hp;
	LL damage;
	LL chi;
};

Node nodes[maxn];
LL ans = 0;

bool cmp(Node n1, Node n2) 
{
	return n1.chi > n2.chi;
}


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> A >> B;
	for (int i = 0; i < N; i++) {
		cin >> nodes[i].hp >> nodes[i].damage;
		nodes[i].chi = max(0LL, nodes[i].hp - nodes[i].damage);
	}
	B = min(B, N);
	sort(nodes, nodes + N, cmp);
	LL ans = 0;
	for (int i = 0; i < N; i++) {
		ans += nodes[i].damage;
	}
	if (B == 0) {
		cout << ans << endl;
	}
	else {
		for (int i = 0; i < B; i++) {
			ans += nodes[i].chi;
		}
/*
		LL res = ans;
		for (int i = 0; i < N; i++) {
			if (i < B) {
				res = max(res, ans - nodes[i].chi + (nodes[i].hp << A) - nodes[i].damage);
			}
			else {
				res = max(res, ans - nodes[B - 1].chi + (nodes[i].hp << A) - nodes[i].damage);
			}
		}
		cout << res << endl;
		*/
		
		int ind = -1;
		LL inc = 0;
		for (int i = 0; i < N; i++) {
			LL t = (nodes[i].hp << A) - nodes[i].damage;
			if (i < B) 
				t -= nodes[i].chi;
			else
				t -= nodes[B - 1].chi;
			if (t > inc) {
				inc = t;
				ind = i;
			}
		}
		ans += inc;
		cout << ans << endl;
	}

	return 0;
}