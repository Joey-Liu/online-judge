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

typedef long long LL;
using namespace std;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	LL N;
	cin >> N;
	LL res = N * (N + 1) / 2;

	for (LL i = 2; i * i <= res; i++) {
		if (res % i == 0) {
			cout << "Yes" << endl;
			cout << 1 << " " << i << endl;
			cout << N - 1;
			for (int j = 1; j <= N; j++) {
				if (j == i)
					continue;
				cout << " " << j;
			}
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}