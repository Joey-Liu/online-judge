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


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int nums[3] = { 0 };
	for (int i = 0; i < 3; i++) {
		cin >> nums[i];
	}

	sort(nums, nums + 3);
	if (nums[0] + nums[1] > nums[2]) {
		cout << "0" << endl;
	}
	else {
		cout << nums[2] - nums[1] - nums[0] + 1 << endl;
	}

	return 0;
}