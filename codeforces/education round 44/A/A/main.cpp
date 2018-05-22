#include <iostream>
#include <algorithm>

using namespace std;
const int maxn = 150;

int N;
int nums[maxn], old_n[maxn];
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> N;
	for (int i = 1; i <= N / 2; i++) {
		cin >> nums[i];
	}
	sort(nums + 1, nums + N / 2 + 1);
	int res = 0x3f3f3f3f, t = 0;
	int nu = N;
	for (int i = N / 2; i >= 1; i--) {
		if (nums[i] != nu) {
			t += abs(nu - nums[i]);
		}
		nu -= 2;
	}

	res = min(t, res);
	nu = N - 1;
	t = 0;
	for (int i = N / 2; i >= 1; i--) {
		if (nums[i] != nu) {
			t += abs(nu - nums[i]);
		}
		nu -= 2;
	}
	res = min(t, res);
	cout << res << endl;
	return 0;
}