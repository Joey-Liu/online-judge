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

const int maxn = 200000 + 50;
int N;
LL nums[maxn];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}

	LL ans = 0;
	int i = 0, j = N - 1;
	LL le_sum = nums[0], ri_sum = nums[N - 1];

	while (i < j) {
		if (le_sum == ri_sum) {
			ans = le_sum;
			i++; j--;
			if (i < j) {
				le_sum += nums[i];
				ri_sum += nums[j];
			}
		}
		else if (le_sum < ri_sum) {
			i++;
			le_sum += nums[i];
		}
		else {
			j--;
			ri_sum += nums[j];
		}
	}
	cout << ans << endl;
	return 0;
}