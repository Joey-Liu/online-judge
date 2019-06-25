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

const int maxn = 3e5 + 50;
int nums[maxn], N, M;

bool in_range(int x, int a, int b) {
	a = a % M;
	b = b % M;
	if (a > b)
		swap(a, b);
	return (a <= x && x <= b);
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}
	int lp = 0, rp = M;
	while (lp < rp) {
		int mid = lp + (rp - lp) / 2;
		int prev = 0;
		bool flag = true;
		for (int i = 0; i < N; i++) {
			int a = nums[i], b = nums[i] + mid;
			if ((a <= prev && prev <= b) || (a <= prev + M && prev + M <= b)) {
				continue;
			}

			if (prev >= a) {
				flag = false;
				break;
			}
			else {
				prev = a;
			}
		}//for int i

		if (flag) {
			rp = mid;
		}
		else {
			lp = mid + 1;
		}
	}//while 
	cout << lp << endl;
	return 0;
}