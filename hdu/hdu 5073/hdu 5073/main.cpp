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
#include <limits>

using namespace std;

const int maxn = 50000 + 50;
double pos[maxn];
double pre_sum[maxn], pre_squ_sum[maxn];
int N, K;

int main() 
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int kasenum = 0;
	cin >> kasenum;
	while (kasenum--) {
		
		cin >> N >> K;
		for (int i = 1; i <= N; i++) {
			cin >> pos[i];
		}

		sort(pos + 1, pos + 1 + N);

		if (K >= N) {
			cout << "0" << endl;
		}
		else {
			double ans = 1e100;
			double p_xi_squ = 0.0, p_xi_sum = 0.0;
			int M = N - K;
			for (int i = 1; i < M; i++) {
				p_xi_squ += pos[i] * pos[i];
				p_xi_sum += pos[i];
			}

			for (int i = M; i <= N; i++) {
				p_xi_squ += pos[i] * pos[i];
				p_xi_sum += pos[i];
				double mean = p_xi_sum / M;
				double tmp = p_xi_squ + M * mean * mean - 2 * mean * p_xi_sum;
				if (ans < 0)
					ans = tmp;
				ans = min(ans, tmp);
				p_xi_sum -= pos[i - M + 1];
				p_xi_squ -= pos[i - M + 1] * pos[i - M + 1];
			}
			printf("%.12lf\n", ans);
		}
	}//while


	return 0;
}