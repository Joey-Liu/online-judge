#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

const int maxn = 100000 + 20;
int item[maxn], len, N;
bool visited[maxn];


bool cmp(int a, int b) {
	return a > b;
}

struct Node {
	int x, id;
	Node(int a, int b) {
		x = a;
		id = b;
	}
};

struct cmp_node {
	bool operator() (Node & n1, Node & n2) {
		return n1.x > n2.x;
	}
};

int main() 
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int kasenum;
	cin >> kasenum;

	while (kasenum--) {
		cin >> N >> len;
		priority_queue<Node, vector<Node>, cmp_node> pq;

		memset(visited, false, sizeof(visited));
		for (int i = 0; i < N; i++) {
			cin >> item[i];
		}
		sort(item, item + N, cmp);
		for (int i = 0; i < N; i++) {
			pq.push(Node(item[i], i));
		}

		int ans = 0;
		for (int i = 0; i < N; i++) {
			if (visited[i])
				continue;
			ans++;
			visited[i] = true;

			while (!pq.empty() && visited[pq.top().id])
				pq.pop();

			if (!pq.empty()) {
				int ind = pq.top().id;
				if (item[i] + item[ind] <= len) {
					visited[ind] = true;
					pq.pop();
				}
			}
		}
		cout << ans << endl;
		if (kasenum)
			cout << endl;
	}

	return 0;
}