#include <iostream>
#include <memory.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 5000 + 50;
int A[maxn], B[maxn], N, tmp[maxn], ori;

void work(int lp, int rp) {
	if (lp >= rp)
		return;
	int mid = (lp + rp) >> 1;
	
	work(lp, mid);
	work(mid + 1, rp);

	int x = lp, y = mid + 1, ind = 0;
	while (x <= mid || y <= rp) {
		if (x > mid || (y <= rp && B[y] < B[x])) {
			tmp[ind++] = B[y++];
			ori += max(0, mid + 1 - x);
		}
		else {
			tmp[ind++] = B[x++];
		}
	}//while

	for (int i = 0; i < ind; i++) {
		B[lp + i] = tmp[i];
	}

}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (cin >> N) {
		memset(A, 0, sizeof(A));
		memset(B, 0, sizeof(B));

		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}
		memcpy(B, A, sizeof(A));
		ori = 0;

		work(0, N - 1);
		int ans = ori, t = ori;
		for (int i = 0; i < N; i++) {
			t = t - A[i] + N - 1 - A[i];
			ans = min(t, ans);
		}
		cout << ans << endl;
	}//while
}