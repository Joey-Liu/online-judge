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

const int maxn = 100 + 10;
int nums[maxn] = { 0 };

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, a, b, x, y;
	cin >> N >> a >> x >> b >> y;
	a--; x--;
	b--; y--;
	memset(nums, -1, sizeof(nums));

	int ind = 0;
	int i = a;
	while (i != x % N) {
		nums[i] = ind++;
		i = (i + 1) % N;
	}
	nums[x % N] = ind;

	int j = b;
	ind = 0;
	bool flag = false;
	while (j != y % N) {
		if (ind == nums[j]) {
			flag = true;
			break;
		}
		nums[j] = ind++;
		j = (j + N - 1) % N;
	}
	if (nums[y % N] == ind) {
		flag = true;
	}


	if (flag)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}