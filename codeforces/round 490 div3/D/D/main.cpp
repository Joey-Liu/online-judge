#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

const int maxn = 200000 + 10;

int N, M, a[maxn], need;

int main() 
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	need = N / M;
	vector<vector<int> > vvi(M);

	for (int i = 0; i < N; i++) {
		cin >> a[i];
		vvi[a[i] % M].push_back(i);
	}


	stack<pair<int, int> > sp;
	long long  ans = 0;
	for (int i = 0; i < 2 * M; i++) {
		int cur = i % M;
		while (vvi[cur].size() > need) {
			int ind = vvi[cur].back();
			vvi[cur].pop_back();
			sp.push(make_pair(cur, ind));
		}

		while (vvi[cur].size() < need && !sp.empty()) {
			pair<int, int> pii = sp.top(); sp.pop();
			int incre = (cur - pii.first + M) % M;
			int ind = pii.second;
			ans += incre;
			vvi[cur].push_back(ind);
			a[ind] += incre;
		}
	}

	cout << ans << endl;
	for (int i = 0; i < N; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;

}