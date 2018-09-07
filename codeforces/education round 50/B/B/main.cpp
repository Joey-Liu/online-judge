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

using namespace std;

typedef long long LL;


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	LL kasenum, K, N, M;
	cin >> kasenum;
	while (kasenum--) {
		cin >> N >> M >> K;
		LL t = min(N, M), res = 0;
		if (N < M)
			swap(N, M);

		res += t;
		K -= t;
		if (K < N - M) {
			cout << -1 << endl;
		}
		else {
			int shengyu = N - M;
			if (shengyu == 0) {
				res -= 2;
				K += 2;
				shengyu = 2;
			}
			if (shengyu % 2) {
				res += (shengyu - 1);
				K -= (shengyu - 1);
				if (K % 2) {
					res += (K - 1);
				}
				else {
					res += ((K - 1));
				}
			}
			else {
				res += (shengyu - 1);
				K -= (shengyu - 1);
				if (K % 2) {
					res += K;
				}
				else {
					res += K - 2;
				}
			}
			cout<<res<<endl;
		}
		
	}//while

	return 0;
}