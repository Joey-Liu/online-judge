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
int nums[maxn];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int kasenum, x;
	cin >> kasenum;
	while (kasenum--) {
		string str;
		cin >> str;
		cin >> x;
		
		int N = str.size();
		memset(nums, -1, sizeof(nums));
		for (int i = 0; i < N; i++) {
			if (str[i] != '0') {
				continue;
			}

			if (i + x < N) {
				nums[i + x] = 0;
			}
			if (i - x >= 0) {
				nums[i - x] = 0;
			}
		}

		bool flag = true;
		for (int i = 0; i < N; i++) {
			if (str[i] == '0') {
				continue;
			}
			
			bool flag1 = ((i + x < N) && nums[i + x] != 0);
			bool flag2 = ((i - x >= 0) && nums[i - x] != 0);
			if (!flag1 && !flag2) {
				flag = false;
				break;
			}

			if (flag1) {
				nums[i + x] = 1;
			}
			if (flag2) {
				nums[i - x] = 1;
			}
		}

		if (!flag) {
			cout << -1 << endl;
			continue;
		}

		string res = "";
		for (int i = 0; i < N; i++) {
			if (nums[i] == -1) {
				nums[i] = 1;
			}
			res += to_string(nums[i]);
		}
		cout << res << endl;
	
	}//while


	return 0;
}