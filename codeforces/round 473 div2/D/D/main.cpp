#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <set>

using namespace std;

const int maxn = 2000000 + 20;
int a[maxn], p[maxn], N, acc[maxn];
vector<int> factor[maxn];
set<int> si;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	p[0] = p[1] = 1;
	for (int i = 2; i < maxn; i++) {
		if (!p[i]) {
			for (int j = i; j < maxn; j += i) {
				factor[j].push_back(i);
				p[j] = 1;
			}//for int j
		}
		si.insert(i);
	}//for int i

	cin >> N;
	int a, eq = 1, cur = -1;
	memset(acc, 1, sizeof(acc));
	for (int i = 0; i < N; i++) {
		cin >> a;
		if (eq) {
			cur = *si.lower_bound(a);
			if (cur != a)
				eq = 0;
		}
		else {
			cur = *si.begin();
		}

		cout << cur << " ";
		for (int x : factor[cur]) {
			for (int j = x; j < maxn; j += x) {
				if (acc[j]) {
					si.erase(j);
					acc[j] = 0;
				}
			}
		}

	}//for int i
	return 0;
}