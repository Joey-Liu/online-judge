#include <iostream>
#include <memory.h>
#include <string>
#include <string.h>
#include <algorithm>


using namespace std;
const int maxn = 100000 + 10;
struct Node {
	int x, y, z;
	double t;
};

Node nodes[maxn];
int N, M, K;

bool cmp(Node n1, Node n2) {
	return n1.t < n2.t;
}

int meets[510][510];
int ans[510][510];

void work() {
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			ans[i][j] = meets[i][j];
		}
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		cin >> nodes[i].x >> nodes[i].y >> nodes[i].z;
		int hour, minu;
		double seconds;
		char c;
		cin >> hour >> c >> minu;
		cin >> c >> seconds;
		nodes[i].t = 3600.0 * hour + minu * 60.0 + seconds;
	}

	sort(nodes, nodes + K, cmp);
	int cnt = 0, maxi = 0;
	for (int i = 0; i < K; i++) {
		int r = nodes[i].x;
		int c = nodes[i].y;
		if (nodes[i].z == 0) {
			if (!meets[r][c])
				cnt++;
			meets[r][c]++;	
		}
		else {
			meets[r][c]--;
			if (!meets[r][c])
				cnt--;
		}
		if (cnt >= maxi) {
			maxi = cnt;
			work();
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (ans[i][j])
				cout << 1;
			else
				cout << 0;
		}
		cout << endl;
	}

	return 0;
}