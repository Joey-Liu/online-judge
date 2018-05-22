#include <iostream>
#include <stdio.h>
#include <string>
#include <memory.h>

using namespace std;
const int maxn = 10;
int a[maxn], N;

bool is_sort() {
	for (int i = 0; i < N - 1; i++) {
		if (a[i] > a[i + 1])
			return false;
	}
	return true;
}

int cnt_h() {
	int cnt = 0;
	for (int i = 0; i < N - 1; i++) {
		if (a[i] + 1 != a[i + 1])
			cnt++;
	}
	return cnt;
}

bool dfs(int layer, int d) {
	if (d == layer) {
		if (is_sort())
			return true;
		return false;
	}

	if ((layer - d) * 3 < cnt_h())
		return false;

	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			int old_a[maxn], b[maxn], cnt = 0;
			memcpy(old_a, a, sizeof(a));

			for (int k = 0; k < N; k++) {
				if (k < i || k > j)
					b[cnt++] = a[k];
			}

			for (int k = 0; k < cnt; k++) {
				int cnt2 = 0;
				if (k == i)
					continue;
				for (int p = 0; p < k; p++) {
					a[p] = b[cnt2++];
				}
				for (int p = k; p < k + j - i + 1; p++) {
					a[p] = old_a[i + p - k];
				}
				for (int p = k + j - i + 1; p < N; p++) {
					a[p] = b[cnt2++];
				}

				if (dfs(layer, d + 1))
					return true;
				memcpy(a, old_a, sizeof(a));
			}//for int k
		}//for int j
	}//for int i

	return false;
}

int main()
{
	int kase = 0;
	while (cin >> N && N) {
		memset(a, 0, sizeof(a));
		for (int i = 0; i < N; i++) {
			cin >> a[i];
		}

		int res = -1;

		for (int i = 0; i < maxn; i++) {
			if (dfs(i, 0)) {
				res = i;
				break;
			}
		}
		cout << "Case " << ++kase << ": " << res << endl;
	}//while cin >> N
	return 0;
}