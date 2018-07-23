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

using namespace std;
const int maxn = 100000 + 50;

int N;
double T;
vector<int> sons[maxn];

int work(int cur) {
	if (sons[cur].size() == 0)
		return 1;

	vector<int> vi;
	for (int i = 0; i < sons[cur].size(); i++) {
		vi.push_back(work(sons[cur][i]));
	}
	
	sort(vi.begin(), vi.end());
	int K = int(ceil(T * sons[cur].size()));
	int ans = 0;
	for (int i = 0; i < K; i++) {
		ans += vi[i];
	}

	return ans;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	while (cin >> N >> T && (N && T)) {
		T /= 100;
		for (int i = 0; i < maxn; i++)
			sons[i].clear();

		for (int i = 1; i <= N; i++) {
			int a;
			cin >> a;
			sons[a].push_back(i);
		}

		int ans = work(0);
		cout << ans << endl;
	}//while cin

	return 0;
}