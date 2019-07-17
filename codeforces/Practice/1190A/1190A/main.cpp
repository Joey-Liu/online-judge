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

const int maxn = 100000 + 10;
int nums[maxn];
LL N, M, K;


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		cin >> nums[i];
		nums[i]--;
	}

	int sum = 0, ind = 0, res = 0;
	while (ind < M) {
		int t = 0, kase = (nums[ind] + sum) / K;
		while ((nums[ind] + sum) / K == kase) {
			ind++;
			t++;
		}

		res++;
		sum += t;
	}
	cout << res << endl;
	return 0;
}