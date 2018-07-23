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
const double inf = 0x3f3f3f3f;
int N;
double x[maxn], y[maxn], dp[20][1000000];
string str;



double dist(double a, double b, double m, double n) {
	return sqrt((a - m) * (a - m) + (b - n) * (b - n));
}


void work() {
	for (int i = 0; i < N; i++) {

		for (int s = 0; s < 1 << (i + 1); s++) {
			if (s == 0) {
				dp[i][s] = 0;
				continue;
			}

			dp[i][s] = inf;
			if (s & (1 << i)) {
				for (int j = 0; j < i; j++) {
					if (s & (1 << j)) {
						dp[i][s] = min(dp[i][s], dist(x[i], y[i], x[j], y[j]) + dp[i - 1][s ^ (1 << j) ^ (1 << i)]);
					}
				}
			}
			else if(i > 0){
				dp[i][s] = dp[i - 1][s];
			}

		}
	}//for int i
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int kasenum = 0;
	while (cin >> N && N) {
		N <<= 1;
		for (int i = 0; i < N; i++) {
			cin >> str >> x[i] >> y[i];
		}
		work();
		cout << "Case " << ++kasenum << ": ";
		cout.setf(ios::fixed);
		cout << setprecision(2);
		cout << dp[N - 1][(1 << N) - 1] << endl;
	}

	return 0;
}