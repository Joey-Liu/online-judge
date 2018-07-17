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

struct Node {
	int val, ind;
};

bool cmp(Node n1, Node n2) {
	return n1.val > n2.val;
}

const int maxn = 2000 + 50;
int N, K;
int nums[maxn];
Node nodes[maxn];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
		nodes[i].val = nums[i];
		nodes[i].ind = i;
	}

	sort(nodes, nodes + N, cmp);
	int ans = 0;
	set<int> si;
	for (int i = 0; i < K; i++) {
		ans += nodes[i].val;
		si.insert(nodes[i].ind);
	}
	
	int prev = 0;
	vector<int> vi;
	cout << ans << endl;
	for (int i = 0; i < N; i++) {
		if (si.count(i)) {
			vi.push_back(i - prev + 1);
			prev = i + 1;
		}
	}

	if (vi.size() == 1) {
		cout << N << endl;
		return 0;
	} 
	
	int tmp = 0;
	for (int i = 0; i < vi.size() - 1; i++) {
		tmp += vi[i];
	}

	vi[vi.size() - 1] = N - tmp;

	cout << vi[0];
	for (int i = 1; i < vi.size(); i++) {
		cout << " " << vi[i];
	}

	return 0;
}