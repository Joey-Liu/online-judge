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
#include <iomanip>

typedef long double LD;

const int maxn = 1000 + 20;
using namespace std;

int N;
LD M, A[maxn], B[maxn], pay;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> A[i] >> B[i];
	}

	pay = M;
	for (int i = N - 1; i >= 0; i--) {
		if (B[i] <= 1 || A[i] <= 1) {
			cout << -1 << endl;
			return 0;
		}

		LD x2 = M / (B[i] - 1);
		LD x1 = (M + x2) / (A[i] - 1);
		M = M + x1 + x2;
	}
	cout.setf(ios::fixed);
	cout << setprecision(10)<< M - pay << endl;
	return 0;
}