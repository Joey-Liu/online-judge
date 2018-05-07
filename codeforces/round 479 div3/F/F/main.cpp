#include <iostream>
#include <stdio.h>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 200000 + 10;
int nu[maxn], N;
map<int, int> dp;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> nu[i];
	}

	int maxi = -1, en_nu;
	for (int i = 0; i < N; i++) {
		int x = nu[i];
		dp[x] = dp[x - 1] + 1;
		if (dp[x] > maxi) {
			maxi = dp[x];
			en_nu = x;
		}
	}

	int tmp = en_nu;
	vector<int> vi;
	for (int i = N - 1; i >= 0; i--) {
		if (nu[i] == tmp) {
			vi.push_back(i);
			tmp--;
		}
		if (tmp == maxi - en_nu)
			break;
	}

	cout << maxi << endl;
	cout << vi[vi.size() - 1] + 1;
	for (int i = vi.size() - 2; i >= 0; i--)
		cout << " " << vi[i] + 1;
	cout << endl;

	return 0;
}