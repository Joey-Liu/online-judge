#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int maxn = 100000 + 50;
int A[maxn], B[maxn];
int N;


int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	int d1 = A[1] - A[0], d2 = A[N - 1] - A[N - 2];
	int st = 0, ed = N - 2;
	if (d1 > d2)
		st += 1;
	else
		ed -= 1;

	int max_dis = -1, ind = -1;
	for (int i = st; i <= ed; i++) {
		int t = A[i + 1] - A[i];
		if (t > max_dis) {
			max_dis = t;
			ind = i;
		}
	}

	int ans = -1;
	for (int i = st; i <= ed; i++) {
		int t = A[i + 1] - A[i];
		if (i == ind) {
			if (t % 2)
				t = t / 2 + 1;
			else
				t /= 2;
		}
		ans = max(ans, t);
	}
	cout << ans << endl;
	return 0;
}