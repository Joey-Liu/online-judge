#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <math.h>
#include <iomanip>
using namespace std;

const int maxn = 20;
const int inf = 0x3f3f3f3f;
int N;
string str;
double dp[1 << maxn];

struct Node {
	double x, y;
};

Node nodes[maxn];

double dist(Node n1, Node n2) {
	return sqrt((n1.x - n2.x) * (n1.x - n2.x) + (n1.y - n2.y) * (n1.y - n2.y));
}

void work() {
	dp[0] = 0;
	for (int s = 1; s < (1 << N); s++) {
		dp[s] = inf;

		int i = 0;
		for (i = 0; i < N; i++) {
			if ((1 << i) & s)
				break;
		}

		int j = i + 1;
		for (; j < N; j++) {
			if ((1 << j) & s)
				dp[s] = min(dp[s], dp[s ^ (1 << i) ^ (1 << j)] + dist(nodes[i], nodes[j]));
		}
	}
}


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int kasenum = 0;
	while (cin >> N && N) {
		N <<= 1;
		for (int i = 0; i < N; i++) {
			cin >> str >> nodes[i].x >> nodes[i].y;
		}

		work();
		cout << "Case " << ++kasenum << ": ";
		cout.setf(ios::fixed);
		cout << setprecision(2);
		cout << dp[(1 << N) - 1] << endl;
	}
	return 0;
}