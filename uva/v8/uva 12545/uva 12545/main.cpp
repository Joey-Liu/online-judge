#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

string s1, s2;
int N, one_zero, zero_one, q, q_one, q_zero;
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int kasenum, ind = 0;
	cin >> kasenum;
	while (kasenum--) {
		cin >> s1 >> s2;
		N = s1.size();
		one_zero = zero_one = q = q_one = q_zero = 0;

		for (int i = 0; i < N; i++) {
			if (s1[i] == '?') {
				q++;
				if (s2[i] == '1')
					q_one++;
				else
					q_zero++;
			}
			else if (s1[i] - s2[i] == 1) {
				one_zero++;
			}
			else if (s1[i] - s2[i] == -1) {
				zero_one++;
			}
		}

		int ans = 0, she = 0;
		ans += min(one_zero, zero_one);
		she = abs(one_zero - zero_one);
		ans += (she + q);

		if (one_zero > zero_one) {
			one_zero -= zero_one;
			if (q_one < one_zero)
				ans = -1;
		}

		cout << "Case " << ++ind << ": " << ans << endl;
	}
	return 0;
}