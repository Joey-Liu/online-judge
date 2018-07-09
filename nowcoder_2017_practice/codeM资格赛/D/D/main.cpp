#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

using namespace std;

const int maxn = 500 + 50;

int N, M, K, C, indr, indc;
double W[10];

struct Node {
	int score[10];
	int id;
	double rate;
};

Node nodes[maxn];
bool cmp(Node n1, Node n2) {
	return n1.rate > n2.rate;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M >> K >> C;
	
	double ws = 0.0;
	for (int i = 0; i < M; i++) {
		cin >> W[i];
		ws += W[i];
	}
	for (int i = 0; i < M; i++) {
		W[i] /= ws;
	}
	
	for (int i = 0; i < N; i++) {
		nodes[i].id = i;
		for (int j = 0; j < M; j++) {
			cin >> nodes[i].score[j];
			nodes[i].rate = 0;
			if (nodes[i].score[j] == -1) {
				indr = i;
				indc = j;
			}
		}
	}

	for (int j = 0; j < M; j++) {
		if (j == indc)
			continue;
		int maxi = nodes[0].score[j];
		for (int i = 0; i < N; i++) {
			maxi = max(maxi, nodes[i].score[j]);
		}

		if (0 == maxi)
			continue;
		for (int i = 0; i < N; i++) {
			nodes[i].rate += (1.0 * nodes[i].score[j] * W[j] / maxi);
		}
	}

	int ans[maxn];
	memset(ans, 0, sizeof(ans));
	if (K >= N)
	{
		for (int i = 0; i < N; i++)
			cout << 1 << endl;
		return 0;
	}


	Node tmp[maxn];
	for (int k = 0; k <= C; k++) {
		memcpy(tmp, nodes, sizeof(nodes));
		tmp[indr].score[indc] = k;
		int maxi = tmp[0].score[indc];
		for (int i = 0; i < N; i++) {
			maxi = max(maxi, tmp[i].score[indc]);
		}//for int i

		if (maxi != 0) {
			for (int i = 0; i < N; i++) {
				tmp[i].rate += (1.0 * tmp[i].score[indc] * W[indc] / maxi);
			}
		}

		sort(tmp, tmp + N, cmp);
		double li = tmp[K].rate;
		for (int i = 0; i < N; i++) {
			if (ans[tmp[i].id] == 3)
				continue;

			if (i < K && tmp[i].rate > li) {
				if (ans[tmp[i].id] == 2)
					ans[tmp[i].id] = 3;
				else
					ans[tmp[i].id] = 1;
			}
			else if (i < K && tmp[i].rate == li) {
				ans[tmp[i].id] = 3;
			}
			else if(i >= K && tmp[i].rate == tmp[K - 1].rate){
				ans[tmp[i].id] = 3;
			}
			else {
				if (ans[tmp[i].id] == 1)
					ans[tmp[i].id] = 3;
				else
					ans[tmp[i].id] = 2;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		cout << ans[i] << endl;
	}
	return 0;
}