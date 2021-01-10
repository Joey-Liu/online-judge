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

const int maxn = 300000 + 10;
int nums[maxn], A[maxn], N;

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
		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}

		int st = 0, ed = 0, ind = 0;
		while (st < N) {
			ed = st;
			while (ed < N && A[ed] == A[st]) {
				ed++;
			}
			nums[ind++] = A[st];
			st = ed;
		}//while

		map<int, int> tab;
		for (int i = 0; i < ind; i++) {
			tab[nums[i]] += 1;
		}

		int ans = N + 1;
		for (int i = 0; i < ind; i++) {
			int tmp = tab[nums[i]] + 1;
			if (nums[i] == nums[0]) {
				tmp -= 1;
			}
			if (nums[i] == nums[ind - 1]) {
				tmp -= 1;
			}
			ans = min(tmp, ans);
		}

		cout << ans << endl;

	}//while

	return 0;
}