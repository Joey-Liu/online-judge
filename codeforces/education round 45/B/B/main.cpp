#include <iostream>
#include <memory.h>
#include <string>
#include <algorithm>

using namespace std;
const int maxn = 200000 + 200;
int N, K;
int nums[maxn];
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}

	sort(nums, nums + N);
	int st = 0, ed = 0, ans = N;
	while (st < N && ed < N) {
		int x = nums[st], y = nums[st] + K;
		while (ed < N && nums[ed] <= x)
			ed++;
		if (ed >= N)
			break;
		else {
			if (nums[ed] <= y) {
				ans = ans - (ed - st);
				st = ed;
			}
			else {
				st = ed;
			}
		}
	}//while
	cout << ans << endl;
	return 0;
}