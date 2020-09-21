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
int A[maxn], B[maxn];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int kasenum;
	cin >> kasenum;
	while (kasenum--) {
		int N, amn = 0x3f3f3f3f;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> A[i];
			B[i] = A[i];
			amn = min(amn, A[i]);
		}

		sort(A, A + N);
		bool flag = true;
		for (int i = 0; i < N; i++) {
			if (A[i] == B[i]) {
				continue;
			}
			if (B[i] % amn) {
				flag = false;
				break;
			}

		}
		cout << (flag ? "YES" : "NO") << endl;


	}


	return 0;
}