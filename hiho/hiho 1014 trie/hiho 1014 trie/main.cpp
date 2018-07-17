#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <string>
#include <string.h>

using namespace std;

const int maxn = 26;

struct Node {
	int cnt;
	Node * nxt[maxn];

	Node() {
		cnt = 0;
		for (int i = 0; i < maxn; i++) {
			nxt[i] = NULL;
		}
	}
};


void insert(Node * head, const string & str) {
	Node * p = head;
	for (int i = 0; i < str.size(); i++) {
		int ind = str[i] - 'a';
		if (p->nxt[ind] == NULL) {
			p->nxt[ind] = new Node();
		}
		p->cnt++;
		p = p->nxt[ind];
	}
	p->cnt++;
}

int search(Node * head, const string & str) {
	Node * p = head;
	for (int i = 0; i < str.size(); i++) {
		int ind = str[i] - 'a';
		if (p->nxt[ind] == NULL)
			return 0;
		p = p->nxt[ind];
	}
	return p->cnt;
}

int N, M;
int main() 
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	Node * head = new Node();
	cin >> N;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		insert(head, str);
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		string str;
		cin >> str;
		cout << search(head, str) << endl;
	}
	return 0;
}