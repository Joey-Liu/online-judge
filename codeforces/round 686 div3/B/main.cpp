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

const int maxn = 200000 + 10;
int nums[maxn], cnt[maxn], N;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int kasenum;
	cin >> kasenum;
	while (kasenum--) {
		cin >> N;
		memset(cnt, 0, sizeof(cnt));

		for (int i = 1; i <= N; i++) {
			cin >> nums[i];
			cnt[nums[i]]++;
		}

		int ans = 0x3f3f3f3f, ind = -1;
		for (int i = 1; i <= N; i++) {
			int a = nums[i];
			if (cnt[a] != 1) {
				continue;
			}
			if (ans > a) {
				ans = a;
				ind = i;
			}
		}

		cout << ind << endl;
	}

	return 0;
}