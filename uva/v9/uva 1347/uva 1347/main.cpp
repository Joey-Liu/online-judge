#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <memory.h>

using namespace std;

const int maxn = 10000 + 10;
double dist[maxn][maxn];
double dp[maxn][maxn];

int x[maxn], y[maxn];
int N;


double get_dist(int x1, int y1, int x2, int y2) 
{
	return sqrt(abs(x1 - x2) * abs(x1 - x2) + abs(y2 - y1) * abs(y2 - y1));
}

void work()
{
	for (int j = 0; j < N - 1; j++) {
		dp[N - 1][j] = dist[j][N - 1];
	}

	for (int i = N - 2; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			dp[i][j] = min(dp[i + 1][j] + dist[i][i + 1], dp[i + 1][i] + dist[j][i + 1]);
		}
	}

}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	while (cin >> N) {
		for (int i = 0; i < N; i++)
			cin >> x[i] >> y[i];

		//memset(dist, 0, sizeof(dist));
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				dist[i][j] = get_dist(x[i], y[i], x[j], y[j]);
				dist[j][i] = dist[i][j];
			}
		}

		work();
		double ans = dp[1][0] + dist[0][1];
		cout.setf(ios::fixed);
		cout <<setprecision(2)<< ans << endl;
	}
	return 0;
}