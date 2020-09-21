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

const int maxn = 100000 + 10;
int nums[maxn];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, M, x, y;
	cin >> N >> M >> x >> y;
	x -= 1;
	y -= 1;
	set<int> vis;
	vector<PII> res;
	vis.emplace(x * M + y);
	res.emplace_back(make_pair(x, y));
	vis.emplace(y);
	res.emplace_back(make_pair(0, y));

	for (int i = 0; i < N; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < M; j++) {
				int cur = i * M + j;
				if (vis.count(cur)) {
					continue;
				}
				vis.insert(cur);
				res.emplace_back(make_pair(i, j));
			}
		}
		else {
			for (int j = M - 1; j >= 0; j--) {
				int cur = i * M + j;
				if (vis.count(cur)) {
					continue;
				}
				vis.insert(cur);
				res.emplace_back(make_pair(i, j));
			}
		}
	}//for int i

	for (int i = 0; i < res.size(); i++) {
		PII pii = res[i];
		cout << pii.first + 1 << " " << pii.second + 1 << endl;
	}
	

	return 0;
}