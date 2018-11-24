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

const int maxn = 1e5 + 10;
int A[maxn], B[maxn], N, T[maxn] = { 0 };
bool has_found = false;
bool uncertain[2], t0[2], t1[2];

void work() {
	bool flag = true;
	for (int i = 1; i < N - 1; i++) {
		for (int j = 0; j < 2; j++) {
			if ( ((1 << j) & T[i]) && ((1 << j) & B[i]) ) {
				T[i + 1] |= (1 << j);
			} 
			if ( !((1 << j) & T[i]) && ((1 << j) & A[i])) {
				T[i + 1] |= (1 << j);
			}

			if (((1 << j) & T[i]) && !((1 << j) & A[i])) {
				flag = false;
				break;
			}
			if ( !((1 << j) & T[i]) && ((1 << j) & B[i])) {
				flag = false;
				break;
			}
		}
		if (!flag)
			break;
	}
	if (flag) {
		has_found = true;
	}
}

void dfs(int cur) {
	if (cur == 2) {
		memset(T, 0, sizeof(T));
		int k0 = 0, k1 = 0;
		for (int i = 0; i < 2; i++) {
			if (t1[i])
				k1 += (1 << i);
			if (t0[i])
				k0 += (1 << i);
		}
		T[0] = k0; T[1] = k1;
		work();
		return;
	}

	if (!uncertain[cur])
		dfs(cur + 1);
	else {
		for (int i = 0; i <= 1; i++) {

			t0[cur] = i;
			t1[cur] = 1 - i;
			dfs(cur + 1);
			if (has_found)
				return;
		}
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N - 1; i++) {
		cin >> B[i];
	}

	
	memset(uncertain, true , sizeof(uncertain));


	for (int i = 0; i < 2; i++) {
		if (!((1 << i) & A[0])) {
			uncertain[i] = false;
			t0[i] = t1[i] = 0;
		}

		if ((1 << i) & B[0]) {
			uncertain[i] = false;
			t0[i] = t1[i] = 1;
		}

		if (((1 << i) & B[0]) && !((1 << i) & A[0]))
		{
			cout << "NO" << endl;
			return 0;
		}
	}
	dfs(0);
	if (!has_found)
		cout << "NO" << endl;
	else {
		cout << "YES" << endl;
		for (int i = 0; i < N; i++) {
			cout << T[i] << " ";
		}
		cout << endl;
	}


	return 0;
}