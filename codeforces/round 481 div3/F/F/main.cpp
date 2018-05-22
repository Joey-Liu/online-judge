#include <iostream>
#include <map>
#include <algorithm>
#include <memory.h>

using namespace std;
const int maxn = 200010;

struct Node {
	int id;
	int ski;
};

bool cmp(Node n1, Node n2) {
	return n1.ski < n2.ski;
}

int N, K;
Node pro[maxn];
int pos[maxn], res[maxn];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> pro[i].ski;
		pro[i].id = i;
	}

	sort(pro, pro + N, cmp);
	for (int i = 0; i < N; i++) {
		pos[pro[i].id] = i;
	}

	memset(res, 0, sizeof(res));
	for (int i = 1; i < N; i++) {
		if (pro[i].ski == pro[i - 1].ski) {
			res[i] = res[i - 1];
		}
		else {
			res[i] = i;
		}
	}

	int a, b;
	for (int i = 0; i < K; i++) {
		cin >> a >> b;
		a = pos[a - 1];
		b = pos[b - 1];
		if (pro[a].ski == pro[b].ski)
			continue;
		else if (pro[a].ski < pro[b].ski) {
			res[b]--;
		}
		else {
			res[a]--;
		}
	}
	
	int ans[maxn];

	for (int i = 0; i < N; i++) {
		ans[i] = res[pos[i]];
	}
	cout << ans[0];
	for (int i = 1; i < N; i++) {
		cout << " " << ans[i];
	}


	return 0;
}