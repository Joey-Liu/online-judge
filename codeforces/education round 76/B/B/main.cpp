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

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
int nums[maxn];

bool work(int a, int b) {
	int max_num = inf;
	switch (a) {
	case 1:
		max_num = 1;
		break;
	case 2:
	case 3:
		max_num = 3;
		break;
	default:
		max_num = inf;
	}

	return max_num >= b;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int casenum;
	cin >> casenum;
	while (casenum--) {
		int a, b;
		cin >> a >> b;
		if (work(a, b) == false) {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
		}
	}

	return 0;
}