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
typedef long long LL;

const int maxn = 100000 + 20;
LL A[maxn], B[maxn];
int N;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	for (int i = 0; i < N; i++)
		cin >> B[i];

	sort(A, A + N);
	sort(B, B + N);

	int x = N - 1, y = N - 1;
	LL s1 = 0, s2 = 0;
	bool flag = true;

	while (x >= 0 || y >= 0) {
		if (flag) {
			if ((x >= 0 && y >= 0 && A[x] >= B[y]) || (x >= 0 && y < 0)) {
				s1 += A[x--];
			}
			else {
				y--;
			}
		}
		else {
			if ((y >= 0 && x >= 0 && A[x] <= B[y]) || (y >= 0 && x < 0)) {
				s2 += B[y--];
			}
			else {
				x--;
			}
		}

		flag = !flag;
	}//while
	cout << s1 - s2 << endl;
	return 0;
}