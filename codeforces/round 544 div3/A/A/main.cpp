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

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int h1, h2, m1, m2;
	char ch;
	cin >> h1 >> ch >> m1;
	cin >> h2 >> ch >> m2;

	int a = h1 * 60 + m1;
	int b = h2 * 60 + m2;

	int c = (b + a) / 2;
	int hour = c / 60, minute = c % 60;
	if (hour < 10)
		cout << "0";
	cout << hour << ":";
	if (minute < 10)
		cout << "0";
	cout << minute << endl;

	return 0;
}