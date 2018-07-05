#include <iostream>
#include <algorithm>

using namespace std;
const int maxn = 100000 + 20;
int nums[maxn];

bool cmp(int a, int b) {
	return a > b;
}

int main() 
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int kasenum;
	cin >> kasenum;
	while (kasenum--) {
		int N, len;
		cin >> N >> len;
		for (int i = 0; i < N; i++) {
			cin >> nums[i];
		}
		sort(nums, nums + N, cmp);
		int i = 0, j = N - 1, ans = 0;
		while (i < j) {
			ans++;
			if (nums[i] + nums[j] <= len)
				j--;
			i++;
		}
		if(i == j)
			ans++;

		cout << ans << endl;
		if (kasenum)
			cout << endl;
	}

	return 0;
}