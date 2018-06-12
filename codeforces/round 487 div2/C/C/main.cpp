#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

struct Node {
	int id;
	int cnt;
};

Node nodes[4];
const int maxn = 50;
char tab[31][maxn];

bool cmp(Node n1, Node n2) {
	return n1.cnt > n2.cnt;
}

void work(int x, int y) {
	for (int i = (y - 1) * 10; i < y * 10; i++) {
		for (int j = 0; j < maxn; j++) {
			tab[i][j] = nodes[y].id + 'A';
		}
	}

	bool done = false; 
	for (int i = y * 10 - 1; i >= (y - 1) * 10; i -= 2) {
		for (int j = 0; j < maxn; j += 2) {
			if (nodes[x].cnt <= 0)
			{
				done = true;
				break;
			}
			tab[i][j] = nodes[x].id + 'A';
			nodes[x].cnt--;
		}
		if (done)
			break;
	}//for int i
	nodes[y].cnt--;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	for (int i = 0; i < 4; i++) {
		cin >> nodes[i].cnt;
		nodes[i].id = i;
	}
	sort(nodes, nodes + 4, cmp);
	work(0, 1);
	work(1, 2);
	work(2, 3);

	bool done = false;
	for (int i = 8; i >= 0; i -= 2) {
		for (int j = 0; j < maxn; j += 2) {
			if (nodes[3].cnt <= 0) {
				done = true;
				break;
			}
			tab[i][j] = nodes[3].id + 'A';
			nodes[3].cnt--;
		}
		if (done)
			break;
	}

	cout << "30 " << maxn << endl;
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < maxn; j++) {
			cout << tab[i][j];
		}
		cout << endl;
	}

	return 0;
}