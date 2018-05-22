#include <iostream>
#include <set>
#include <map>
#include <string>
#include <memory.h>

using namespace std;
const int maxn = 2000 + 10;
set<int> si[maxn];

int nums[maxn], N, M;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < M; j++) {
			if (str[j] == '1') {
				si[i].insert(j);
				nums[j]++;
			}
		}
	}

	bool flag = false;
	for (int i = 1; i <= N; i++) {
		int tm[maxn];
		memcpy(tm, nums, sizeof(nums));
		for (auto it = si[i].begin(); it != si[i].end(); it++) {
			nums[*it]--;
		}

		bool ok = true;
		for (int j = 0; j < M; j++) {
			if (nums[j] == 0) {
				ok = false;
				break;
			}
		}
		if (ok) {
			flag = true;
			break;
		}
		memcpy(nums, tm, sizeof(nums));
	}
	if (flag) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}