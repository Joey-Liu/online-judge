#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

const int maxn = 100 + 5;
int N, k, A[maxn];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> N >> k;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	int i = 0, j = N - 1, cnt = 0;
	while (i < N && A[i] <= k) {
		i++;
		cnt++;
	}

	while (i < j && A[j] <= k) {
		j--;
		cnt++;
	}

	cout << cnt << endl;
	return 0;
}