#include <iostream>
#include <stdio.h>
#include <string>
#include <memory.h>
#include <algorithm>

using namespace std;

const int maxn = 2e5 + 10;
typedef long long LL;

struct Node {
	LL x;
	int flag;
};

Node point[maxn << 1];
LL N, ans[maxn];

bool cmp(const Node & n1, const Node & n2) {
	return n1.x < n2.x;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;
	int flag = 0;
	for (int i = 0; i < 2 * N; i++) {
		cin >> point[i].x;
		if (flag)
			point[i].x++;
		point[i].flag = flag;
		flag = 1 - flag;
	}

	sort(point, point + 2 * N, cmp);
	int cnt = 0;
	for (int i = 0; i < 2 * N - 1; i++) {
		if (!point[i].flag) {
			cnt++;
		}
		else {
			cnt--;
		}

		if (cnt > 0) {
			ans[cnt] += point[i + 1].x - point[i].x;
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << ans[i] << endl;
	}
	return 0;
}