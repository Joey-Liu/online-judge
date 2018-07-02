#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 200000 + 50;

struct Node {
	int x;
	Node * nxt[2];

	Node() {
		x = 0;
		nxt[0] = nxt[1] = NULL;
	}
};

Node *head;
int N, A[maxn];


void add_node(int a) {
	int b = a;
	vector<int> v(31, 0);
	for (int i = 30; i >= 0; i--) {
		v[i] = a % 2;
		a /= 2;
	}

	Node * p = head;
	for (int i = 0; i < 31; i++) {
		int k = v[i];
		if (p->nxt[k] == NULL) {
			p->nxt[k] = new Node();
		}
		p = p->nxt[k];
	}
	p->x = b;
}

int work(int a) {
	int b = a;
	vector<int> v(31, 0);
	for (int i = 30; i >= 0; i--) {
		v[i] = a % 2;
		a /= 2;
	}

	Node *p = head;
	for (int i = 0; i < 31; i++) {
		int k = v[i];
		if (p->nxt[1 - k] != NULL) {
			p = p->nxt[1 - k];
		}
		else {
			p = p->nxt[k];
		}
	}

	return b ^ (p->x);
}


void delete_node(Node * p) {
	if (!p)
		return;
	delete_node(p->nxt[0]);
	delete_node(p->nxt[1]);

	delete p;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while(cin>>N) {
		head = new Node();
		for (int i = 0; i < N; i++) {
			cin >> A[i];
			add_node(A[i]);
		}

		int ans = 0;
		for (int i = 0; i < N; i++) {
			ans = max(ans, work(A[i]));
		}
		cout << ans << endl;
		delete_node(head);
	}
	return 0;
}