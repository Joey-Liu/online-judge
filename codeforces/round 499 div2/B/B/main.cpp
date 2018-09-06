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

int N, M, tmp;
map<int, int> tab;

bool work(int days) {
	map<int, int> cnt = tab;
	int num = 0;
	
	for (auto it = cnt.begin(); it != cnt.end(); it++) {
		while (it->second >= days) {
			it->second -= days;
			num++;
			if (num >= N)
				return true;
		}
	}
	return false;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> tmp;
		tab[tmp]++;
	}

	int lp = 0, rp = M + 1;
	while (lp < rp) {
		int mid = lp + (rp - lp) / 2;
		if (work(mid)) {
			lp = mid + 1;
		}
		else {
			rp = mid;
		}
	}

	cout << lp - 1 << endl;
	return 0;
}