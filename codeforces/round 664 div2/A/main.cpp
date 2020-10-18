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
#include <math.h>
#include <functional>
#include <limits.h>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;

const int maxn = 100000 + 10;
int nums[maxn], t[maxn];

bool work(int arr[]) {
	int t = arr[0] % 2;
	for (int i = 1; i < 4; i++) { 
		if (t != arr[i] % 2) {
			return false;
		}
	}
	return true;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int kasenum;
	cin >> kasenum;
	while (kasenum--) {
		int sum = 0;
		for (int i = 0; i < 4; i++) {
			cin >> nums[i];
			t[i] = nums[i] % 2;
			sum += nums[i];
		}


		if (sum % 2 == 0) {
			if (work(nums)) {
				cout << "Yes" << endl;
			}
			else {
				cout << "No" << endl;
			}
		}
		else {
			int arr[4];
			bool flag = false;
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					arr[j] = nums[j];
				}

				if (arr[i] <= 0) {
					continue;
				}

				arr[i] -= 1;
				if (work(arr)) {
					flag = true;
					break;
				}
			}

			if (t[0] == t[1] && t[1] == t[2] && t[2] != t[3]) {
				flag = true;
			}

			if (flag) {
				cout << "Yes" << endl;
			}
			else {
				cout << "No" << endl;
			}
		}


	}



	return 0;
}