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

int cnt[30] = { 0 } , N, K;
string str;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> N >> K >> str;
	for (int i = 0; i < str.size(); i++) {
		cnt[str[i] - 'A']++;
	}

	int res = INT_MAX;
	for (int i = 0; i < K; i++) {
		res = min(res, cnt[i]);
	}

	cout << res * K << endl;

	return 0;
}