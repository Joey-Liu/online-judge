#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>

using namespace std;
typedef long long LL;

const int maxn = 500000 + 2;

LL nums[maxn], N;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}

	if (N == 1) {
		cout << nums[0] << endl;
		return 0;
	}
	else if (N == 2) {
		cout << min(nums[1], nums[0]) - min(nums[1], nums[0]) << endl;
		return 0;
	}

	LL maxi = nums[0], maxi_ind = 0;
	for (int i = 1; i < N; i++) {
		if (nums[i] > maxi) {
			maxi = nums[i];
			maxi_ind = i;
		}
	}

	LL left_mini = INT_MAX, left_ind = -1;
	for (int i = 0; i < maxi_ind; i++) {
		if (left_mini > nums[i]) {
			left_mini = nums[i];
			left_ind = i;
		}
	}

	LL right_mini = INT_MAX, right_ind = N;
	for (int i = N - 1; i > maxi_ind; i--) {
		if (right_mini > nums[i]) {
			right_mini = nums[i];
			right_ind = i;
		}
	}

	int res = 0;
	if (left_ind == -1) {
		for (int i = 1; i < N; i++) {
			if (i != right_ind) 
				res -= nums[i];
			else
				res += nums[i];
		}
		cout << maxi - res << endl;
		return 0;
	}
	else if (right_ind == N) {
		for (int i = 0; i < N - 1; i++) {
			if (i != left_ind)
				res -= nums[i];
			else
				res += nums[i];
		}
		cout << maxi - res << endl;
		return 0;
	}
	else if (maxi_ind <= 1) {
		for (int i = maxi_ind + 1; i < N; i++) {
			if (i != right_ind)
				res -= nums[i];
			else
				res += nums[i];
		}
		res -= maxi;
		cout << left_mini - res << endl;
		return 0;
	}
	else {
		for (int i = 0; i < N - 1; i++) {
			if (i == left_ind) {
				res += nums[i];
			}
			else {
				res -= nums[i];
			}
		}
		cout << nums[N - 1] - res << endl;
	}

	return 0;
}