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

const int maxn = 150;
int nums[maxn], tmp[maxn], perm[maxn];
int N, K, mis, ans;
bool vis[maxn];

void check() {
	memcpy(perm, nums, sizeof(perm));
	int ind = 1;
	for (int i = 0; i < mis; i++) {
		while (perm[ind] != 0)
			ind++;
		perm[ind] = tmp[i];
	}

	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			if (perm[i] < perm[j])
				cnt++;
		}
	}

	if (cnt == K)
		ans++;
}

void dfs(int cur) {
	if (cur == mis) {
		check();
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (!vis[i]) {
			tmp[cur] = i;
			vis[i] = true;
			dfs(cur + 1);
			vis[i] = false;
		}
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);


	cin >> N >> K;
	memset(vis, false, sizeof(vis));
	for (int i = 1; i <= N; i++) {
		cin >> nums[i];
		if (nums[i]) {
			vis[nums[i]] = true;
		}
		else {
			mis++;
		}
	}
	
	dfs(0);
	cout << ans << endl;

	return 0;
}