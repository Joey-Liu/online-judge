#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

const int maxn = 200000 + 20;

struct Node {
	int x[3];
};

bool cmp(int a, int b) {
	return a > b;
}

Node nodes[maxn];
int N;

int main() 
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> nodes[i].x[j];
		}
		sort(nodes[i].x, nodes[i].x + 3, cmp);
	}

	int se_max = 0, th_max = 0;
	for (int i = 0; i < N; i++) {
		se_max = max(nodes[i].x[1], se_max);
		th_max = max(nodes[i].x[2], th_max);
	}

	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (nodes[i].x[0] > se_max && nodes[i].x[1] > th_max)
			ans++;
	}
	cout << ans << endl;
	return 0;

}