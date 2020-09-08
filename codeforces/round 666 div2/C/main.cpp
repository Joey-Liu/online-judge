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
LL nums[maxn];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	LL N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}
	if (N == 1) {
		cout << 1 << " " << 1 << endl;
		cout << nums[0] << endl;
		cout << 1 << " " << 1 << endl;
		cout << nums[0] << endl;
		cout << 1 << " " << 1 << endl;
		cout << -3 * nums[0] << endl;
	}
	else {
		cout << 1 << " " << 1 << endl;
		cout << nums[0] * LL(N - 1) << endl;
		cout << 2 << " " << N << endl;
		for (int i = 1; i < N; i++) {
			cout << LL(N - 1) * nums[i] << " ";
		}
		cout << endl;
		cout << 1 << " " << N << endl;
		for (int i = 0; i < N; i++) {
			cout << -N * nums[i] << " ";
		}
		cout << endl;
	}


	return 0;
}