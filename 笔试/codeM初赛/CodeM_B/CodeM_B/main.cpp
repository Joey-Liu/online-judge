#include <iostream>
#include <memory.h>
using namespace std;

const int maxn = 100000 + 100;
typedef long long LL;

LL nums[maxn];
int N;

void work() 
{
	int ind;
	for (ind = N - 1; ind >= 0; ind--) {
		if (nums[ind] > 0)
			break;
	}

	LL ans = 0, cur_n = nums[ind];
	nums[ind] = 0;
	for (int i = ind - 1; i >= 0; i--) {
		ans += cur_n;
		if (nums[i] >= 0) {
			cur_n += nums[i];
			nums[i] = 0;
		}
		else {
			nums[i] += cur_n;
			if (nums[i] <= 0) {
				cur_n = 0;
			}
			else {
				cur_n = nums[i];
				nums[i] = 0;
			}
		}
	}

	for (int i = 1; i < N; i++) {
		ans += cur_n;
		if (nums[i] < 0) {
			cur_n += nums[i];
		}
		if (cur_n == 0)
			break;
	}
	cout << ans << endl;

}

int main() 
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}

	for (int i = 0; i < N; i++) {
		LL t;
		cin >> t;
		nums[i] -= t;
	}

	if (N == 1) {
		cout << 0;
		return 0;
	}
	work();
	return 0;
}