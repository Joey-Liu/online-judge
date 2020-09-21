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
#include <functional>
#include <limits.h>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;

const int maxn = 3000 + 10;
int nums[maxn];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);	
	int kasenum, N;
	cin >> kasenum;
	while (kasenum--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> nums[i];
		}

		map<int, int> tab;
		LL res = 0;

		for (int j = N - 2; j >= 0; j--) {
			int k = j + 1;
			for (int L = k + 1; L < N; L++) {
				int tmp = nums[k] * N + nums[L];
				tab[tmp] += 1;
			}

			for (int i = j - 1; i >= 0; i--) {
				int tmp = nums[i] * N + nums[j];
				res += tab[tmp];
			}
		}//for int j
		cout << res << endl;

	}


	return 0;
}