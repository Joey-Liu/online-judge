#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

typedef long long LL;
const int maxn = 200000 + 10;

LL A[maxn], K[maxn];
int N, Q;

void work()
{
	LL damage = 0;
	for (int i = 1; i <= Q; i++) {
		damage += K[i];
		int ind = upper_bound(A + 1, A + N + 1, damage) - A - 1;

		if(ind < N)
			cout << N - ind << endl;
		else {
			cout << N << endl;
			damage = 0;
		}
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		A[i] += A[i - 1];
	}

	for (int i = 1; i <= Q; i++) {
		cin >> K[i];
	}
	work();
	return 0;
}