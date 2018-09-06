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

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	string str;
	int N, K;
	cin >> N >> K >> str;

	sort(str.begin(), str.end());
	int res = 0, flag = false;

	int ind = 0, cnt = 0;
	char prev = 0;
	while (ind < N && cnt < K) {
		res += (str[ind] - 'a' + 1);
		prev = str[ind];
		ind++;
		cnt++;
		while (ind < N && str[ind] - prev <= 1) {
			ind++;
		}
	}
	if (cnt == K)
		cout << res << endl;
	else
		cout << -1 << endl;

	return 0;
}