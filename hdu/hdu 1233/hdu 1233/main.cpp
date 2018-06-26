#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <memory.h>
#include <queue>
#include <functional>
#include <algorithm>

using namespace std;
const int maxn = 150;

int parent[maxn];

int set_find(int p) {
	if (parent[p] == p)
		return p;
	return parent[p] = set_find(parent[p]);
}

void set_join(int p, int q) {
	int x = set_find(p);
	int y = set_find(q);
	if (x != y) {
		parent[x] = y;
	}
}


int tab[maxn][maxn], N;
struct Edge {
	int a, b, c;
};

struct cmp {
	bool operator() (const Edge & e1, const Edge & e2) {
		return e1.c > e2.c;
	}
};


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while (cin >> N && N > 0) {
		priority_queue<Edge, vector<Edge>, cmp> pq;
		Edge tmp;
		for (int i = 0; i < N * (N - 1) / 2; i++) {
			cin >> tmp.a >> tmp.b >> tmp.c;
			pq.push(tmp);
		}

		for (int i = 1; i <= N; i++) {
			parent[i] = i;
		}

		int ind = 0, ans = 0;
		while (ind < N - 1) {
			tmp = pq.top();
			pq.pop();
			int a = tmp.a, b = tmp.b, c = tmp.c;
			if (set_find(a) == set_find(b))
				continue;
			
			set_join(a, b);
			ans += c;
			ind++;
		}//while ind
		cout << ans << endl;
	}
	return 0;
}