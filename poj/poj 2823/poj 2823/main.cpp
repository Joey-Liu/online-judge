#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;
const int maxn = 1000000 + 50;

int N, K;
int nums[maxn];
int ans_min[maxn], ans_max[maxn], ind = 0;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	scanf("%d%d", &N, &K);
	deque<int> min_win, max_win;
	

	for (int i = 0; i < N; i++) {
		scanf("%d", &nums[i]);
	}

	for (int i = 0; i < K; i++) {
		while (!min_win.empty() && nums[i] < nums[min_win.back()])
			min_win.pop_back();
		min_win.push_back(i);

		while (!max_win.empty() && nums[i] > nums[max_win.back()])
			max_win.pop_back();
		max_win.push_back(i);
	}

	for (int i = K; i < N; i++) {
		ans_min[ind] = nums[min_win.front()];
		ans_max[ind++] = nums[max_win.front()];

		if (min_win.front() == i - K)
			min_win.pop_front();
		if (max_win.front() == i - K)
			max_win.pop_front();

		while (!min_win.empty() && nums[min_win.back()] > nums[i])
			min_win.pop_back();
		min_win.push_back(i);

		while (!max_win.empty() && nums[max_win.back()] < nums[i])
			max_win.pop_back();
		max_win.push_back(i);
	}

	ans_min[ind] = nums[min_win.front()];
	ans_max[ind++] = nums[max_win.front()];

	for (int i = 0; i < ind - 1; i++) {
		printf("%d ", ans_min[i]);
	}
	printf("%d\n", ans_min[ind - 1]);

	for (int i = 0; i < ind - 1; i++) {
		printf("%d ", ans_max[i]);
	}
	printf("%d\n", ans_max[ind - 1]);
	
	return 0;
}