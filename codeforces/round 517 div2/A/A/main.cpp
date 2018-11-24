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

int W, H, K;
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> W >> H >> K;
	int res = 0;
	for (int i = 0; i < K; i++) {
		res += W * 2;
		res += H * 2;
		res -= 4;
		W -= 4;
		H -= 4;
	}

	cout << res << endl;

	return 0;
}