#include <iostream>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <queue>

using namespace std;
const int maxn = 100000 + 50;

string str;
set<int> in_que;
bool visited[maxn];
int N, D;

struct Node {
	int x;
	int ind;

	Node(int a, int b) {
		x = a;
		ind = b;
	}
};

struct cmp {
	bool operator() (const Node & n1, const Node & n2) {
		if (n1.x != n2.x) {
			return n1.x < n2.x;
		}
		return n1.ind > n2.ind;
	}

};

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (cin >> N >> D) {
		if (!N && !D)
			break;
		cin >> str;

		memset(visited, false, sizeof(visited));
		priority_queue<Node, vector<Node>, cmp> pq;
		for (int i = 0; i < D + 1; i++) {
			pq.push(Node(str[i] - '0', i));
		}

		int ind = pq.top().ind;
		int prev = ind;
		visited[ind] = true;
		for (int i = D + 1; i < N; i++) {
			pq.push(Node(str[i] - '0', i));
			while (pq.top().ind <= ind)
				pq.pop();
			visited[pq.top().ind] = true;
			ind = pq.top().ind;
		}
		for (int i = 0; i < N; i++) {
			if (visited[i])
				cout << str[i];
		}
		cout << endl;
	}
	return 0;
}