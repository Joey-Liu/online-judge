#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 200000 + 100;
int nums[maxn], K, N;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}

	sort(nums, nums + N);
	if (0 == K) {
		if (nums[0] == 1)
			cout << -1 << endl;
		else
			cout << 1 << endl;
	}
	else if (N == K) {
		cout << nums[N - 1] << endl;
	}
	else {
		if (nums[K] == nums[K - 1]) {
			cout << -1 << endl;
		}
		else {
			cout << nums[K - 1] << endl;
		}
	}
	return 0;
}