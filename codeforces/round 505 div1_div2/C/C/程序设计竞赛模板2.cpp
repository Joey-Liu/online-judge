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

int work(string str) {
	int N = str.size(), res = 1, cur = 1;
	for (int i = 1; i < N; i++) {
		if (str[i] != str[i - 1]) {
			cur++;
		}
		else {
			res = max(res, cur);
			cur = 1;
		}
	}

	res = max(res, cur);
	return res;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string str;
	cin >> str;
	int res = work(str);
	int N = str.size();
	if (res == N) {
		cout << res << endl;
	}
	else {
		string s2 = str + str;
		res = max(res, work(s2));
		cout << res << endl;
	}

	return 0;
}