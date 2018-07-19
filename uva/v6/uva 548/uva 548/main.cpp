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
#include <sstream>


using namespace std;
const int maxn = 10000 + 50;

vector<int> post_order, in_order;

int lch[maxn], rch[maxn];
string str;
int N, sum_ans, prev_ans;

int work(int in_lp, int in_rp, int post_lp, int post_rp) {
	if (in_lp == in_rp) {
		return in_order[in_lp];
	}
	else if (in_lp > in_rp) {
		return -1;
	}

	int root = post_order[post_rp];
	int ind = in_lp;
	for (; ind <= in_rp; ind++) {
		if (in_order[ind] == root)
			break;
	}
	
	int le_len = ind - in_lp;
	int ri_len = in_rp - ind;
	int lson = work(in_lp, ind - 1, post_lp, post_lp + le_len - 1);
	int rson = work(ind + 1, in_rp, post_lp + le_len, post_rp - 1);

	lch[root] = lson;
	rch[root] = rson;
	return root;
}


void dfs(int cur, int sum) {

	if (lch[cur] == -1 && rch[cur] == -1) {
		int t = sum + cur;
		if (t < sum_ans || (t == sum_ans && cur < prev_ans)) {
			sum_ans = t;
			prev_ans = cur;
		}
		return;
	}

	if (lch[cur] > 0) {
		dfs(lch[cur], sum + cur);
	}
	if (rch[cur] > 0) {
		dfs(rch[cur], sum + cur);
	}

}


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	while (getline(cin, str)) {
		stringstream ss(str);
		in_order.clear();
		post_order.clear();
		int a;
		while (ss >> a) {
			in_order.push_back(a);
		}

		for (int i = 0; i < in_order.size(); i++) {
			cin >> a;
			post_order.push_back(a);
		}
		int N = post_order.size();

		memset(lch, -1, sizeof(lch));
		memset(rch, -1, sizeof(rch));

		int root = work(0, N - 1, 0, N - 1);
		sum_ans = 0x7fffffff;
		prev_ans = 0x7fffffff;

		dfs(root, 0);
		cout << prev_ans << endl;
		getchar();
	}


	return 0;
}