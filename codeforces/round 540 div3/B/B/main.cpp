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

const int maxn = 2e+5 + 10;
int num[maxn] = { 0 };
int forw_even[maxn], back_even[maxn], forw_odd[maxn], back_odd[maxn];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	if (N == 1) {
		cout << 1 << endl;
		return 0;
	}

	forw_even[0] = num[0];
	for (int i = 1; i < N; i++) {
		forw_even[i] = forw_even[i - 1];
		forw_odd[i] = forw_odd[i - 1];
		if (0 == i % 2) {
			forw_even[i] += num[i];
		}
		else {
			forw_odd[i] += num[i];
		}
	}

	if ((N - 1) % 2) {
		back_odd[N - 1] = num[N - 1];
	}
	else {
		back_even[N - 1] = num[N - 1];
	}
	for (int i = N - 2; i >= 0; i--) {
		back_even[i] = back_even[i + 1];
		back_odd[i] = back_odd[i + 1];
		if (i % 2) {
			back_odd[i] += num[i];
		}
		else {
			back_even[i] += num[i];
		}
	}

	int res = 0;
	for (int i = 1; i < N - 1; i++) {
		if (forw_odd[i - 1] + back_even[i + 1] == forw_even[i - 1] + back_odd[i + 1])
			res++;
	}
	if (back_odd[1] == back_even[1]) {
		res++;
	}
	if (forw_odd[N - 2] == forw_even[N - 2]) {
		res++;
	}
	cout << res << endl;

	return 0;
}