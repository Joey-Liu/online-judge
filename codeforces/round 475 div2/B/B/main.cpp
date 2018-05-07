#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;
int N, A, B, C, T;
const int maxn = 1000 + 200;

int t[maxn];
int mylow_bound(int lp, int rp, int target)
{
	int mid = lp + (rp - lp) / 2;
	while (lp < rp) {
		mid = lp + (rp - lp) / 2;
		if (t[mid] <= target)
			lp = mid + 1;
		else
			rp = mid;
	}
	return lp;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	cin >> N >> A >> B >> C >> T;
	for (int i = 0; i < N; i++)
		cin >> t[i];
	sort(t, t + N);
	int LB = mylow_bound(0, N, T);
	LL res = 0;

	if (B >= C) {
		res = LB * A;
	}
	else {
		res = LB * A;
		int k = C - B;
		for (int i = 0; i < LB; i++) {
			res += k * (T - t[i]);
		}
	}
	cout << res << endl;
}