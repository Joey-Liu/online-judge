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
#include <unordered_map>

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

	int kasenum;
	cin >> kasenum;
	while (kasenum--) {
		int N;
		cin >> N;
		unordered_map<char, int> tab;
		string str;
		for (int i = 0; i < N; i++) {
			cin >> str;
			for (int j = 0; j < str.size(); j++) {
				tab[str[j]] += 1;
			}
		}

		bool flag = true;
		for (auto it = tab.begin(); it != tab.end(); ++it) {
			int t = it->second;
			if (t % N) {
				flag = false;
				break;
			}
		}
		string res = flag ? "YES" : "NO";
		cout << res << endl;

	}

	return 0;
}