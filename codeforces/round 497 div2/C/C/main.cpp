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
	int N, tmp;
	cin >> N;
	vector<int> num(N, 0);

	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	sort(num.begin(), num.end());

	int i = 0, j = 0;
	while (j < N && num[j] == num[i])
		j++;

	if (j == N) {
		cout << 0 << endl;
		return 0;
	}

	int ans = 0;
	while (j < N) {
		if (num[i] < num[j]) {
			ans++;
			i++;
			j++;
		}
		else
			j++;
	}
	cout << ans << endl;
	return 0;
}