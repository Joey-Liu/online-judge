#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

const int maxn = 100000 + 50;

int nums[maxn], N;
map<int, int> tab;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	while (cin >> N) {
		
		tab.clear();
		bool flag = false;
		for (int i = 0; i < N; i++) {
			int t;
			cin >> t;
			tab[t]++;
			if (tab[t] > 1)
				flag = true;
		}

		if (N <= 2) {
			cout << "1 1" << endl;
			continue;
		}

		int ans_2 = ((tab.begin())->second)  * ((tab.rbegin())->second);
		if (tab.begin()->first == tab.rbegin()->first) {
			int t = (tab.begin()->second);
			ans_2 = t * (t - 1) / 2;
		}

		int ans_1 = 0;
		if (flag) {
			for (auto it = tab.begin(); it != tab.end(); it++) {
				if (it->second > 0) {
					ans_1 += it->first * (it->first - 1) / 2;
				}
			}
		}
		else {
			for
		}


	}//while
}