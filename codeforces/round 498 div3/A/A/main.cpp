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
	int N;
	cin >> N;
	vector<int> vi(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> vi[i];
		if (0 == vi[i] % 2) {
			vi[i]--;
		}
	}

	cout << vi[0];
	for (int i = 1; i < N; i++) {
		cout << " " << vi[i];
	}

	return 0;
}