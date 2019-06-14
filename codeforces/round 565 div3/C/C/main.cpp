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

map<int, int> mii;


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	mii[4] = 0; mii[8] = 1; mii[15] = 2;
	mii[16] = 3; mii[23] = 4; mii[42] = 5;
	
	vector<int> pos[6];

	int N, tmp, ind[6] = { 0 };
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> tmp;
		pos[mii[tmp]].push_back(i);
	}

	int cnt = 0;
	while (true) {
		if (ind[0] >= pos[0].size())
			break;

		bool flag = true;
		for (int i = 1; i < 6; i++) {
			int next_ind = upper_bound(pos[i].begin() + ind[i], pos[i].end(), pos[i - 1][ind[i - 1]]) - pos[i].begin();
			if (next_ind >= pos[i].size()) {
				flag = false;
				break;
			}

			ind[i] = next_ind;
		}//for int i

		if (!flag)
			break;
		cnt += 6;
		for (int i = 1; i < 6; i++) {
			ind[i]++;
		} 
		if (ind[5] >= pos[5].size()) {
			break;
		}
		ind[0]++;
	}//while
	cout << N - cnt << endl;
	return 0;
}