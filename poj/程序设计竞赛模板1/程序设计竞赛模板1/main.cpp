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

const int maxn = 1e6 + 10;
int nums[maxn], tokens[maxn];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}

	memcpy(tokens, nums, sizeof(nums));
	sort(tokens, tokens + N);
	int unique_num = unique(tokens, tokens + N) - tokens;
	int st = 0, ed = 1;
	map<int, int> tab;
	tab[nums[0]]++;
	int res = N;
	while (ed < N) {

		while (ed < N && tab.size() < unique_num) {
			tab[nums[ed++]]++;
		}

		while (tab.size() == unique_num) {
			res = min(res, ed - st);
			tab[nums[st++]]--;
			if (tab[nums[st - 1]] == 0) {
				tab.erase(nums[st - 1]);
			}
		}//while
	}//while
	cout << res << endl;



	return 0;
}