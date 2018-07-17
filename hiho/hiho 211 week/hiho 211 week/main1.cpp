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
const int maxn = 100000 + 20;

typedef long long LL;
int nums[maxn], N;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	isdigit

	cin >> N;
	for (int i = 0; i < maxn; i++) {
		cin >> nums[i];
	}

	LL res = 0;
	for (int i = 0; i < 32; i++) {
		int state = (1 << i);
		LL a = 0, b = 0;
		for (int j = 0; j < N; j++) {
			if (state & nums[j])
				a++;
			else
				b++;
		}

		res += a * b;

	}
	cout << res << endl;
	return 0;
}