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

int work(int x1, int y1, int z1, int x2, int y2, int z2) {
	int res = 0;
	int t = min(z1, y2);
	res += 2 * t;
	z1 -= t;
	y2 -= t; // ÏûºÄ1

	if (z1 > 0) {
		t = min(z1, z2);
		z1 -= t;
		z2 -= t; //ÏûºÄ2

	}
	if (z1 > 0) {
		return res;
	}


	t = min(x1, z2); //ÏûºÄ2
	x1 -= t;
	z2 -= t;
	if (x1 > 0) {
		return res;
	}


	t = min(y1, x2 + y2);
	y1 -= t;
	res -= 2 * (y1);
	return res;

}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int kasenum;
	cin >> kasenum;
	while (kasenum--) {
		int x1, y1, z1;
		int x2, y2, z2;
		cin >> x1 >> y1 >> z1;
		cin >> x2 >> y2 >> z2;

		int t1 = work(x1, y1, z1, x2, y2, z2);
		cout << t1 << endl;


	}

	return 0;
}