#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

const int maxn = 100000 + 10;

struct Node {
	int x;
	int id;
	int flag;
};

Node point[maxn * 4];
int N, M;

bool cmp(const Node & n1, const Node & n2) {
	return n1.x < n2.x;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> N >> M;
	int flag = 0;
	for (int i = 0; i < 2 * N; i++) {
		int x;
		cin >> x;
		point[i].x = x;
		point[i].id = 0;
		point[i].flag = flag;
		flag = 1 - flag;
	}

	for (int i = 2 * N; i < 2 * (N + M); i++) {
		int x;
		cin >> x;
		point[i].x = x;
		point[i].id = 1;
		point[i].flag = flag;
		flag = 1 - flag;
	}

	sort(point, point + 2 * (N + M), cmp);
	int cnt1 = 0, cnt2 = 0, ans = 0;
	for (int i = 0; i < 2 * (N + M) - 1; i++) {
		if (point[i].id == 0) {
			if (point[i].flag == 0) {
				cnt1++;
			}
			else {
				cnt1--;
			}
		}//if point if
		
		if (point[i].id == 1) {
			if (point[i].flag == 0) {
				cnt2++;
			}
			else {
				cnt2--;
			}
		}

		if (cnt1 > 0 && cnt2 == 0) {
			ans += point[i + 1].x - point[i].x;
		}
	}//for int i
	cout << ans << endl;
	return 0;
}