#include <iostream>
#include <stdio.h>
#include <map>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <time.h>

using namespace std;

const int maxn = 200000 + 10;
int nu[maxn], N, x;
unordered_map<int, int> dp;

int main()
{
	srand(time(NULL));
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int ra = rand();

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> nu[i];

	int maxi = -1, en_nu;
	for (int i = 0; i < N; i++) {
		int x = nu[i] ^ ra;
		int y = (nu[i] - 1) ^ ra;
		//dp[x] = dp[x - 1] + 1;
		dp[x] = dp[y] + 1;
		if (dp[x] > maxi) {
			maxi = dp[x];
			en_nu = x ^ ra;
		}
	}

	int tmp = en_nu, ind = 0;
	vector<int> vi(maxi);
	for (int i = N - 1; i >= 0; i--) {
		if (nu[i] == tmp) {
			vi[ind++] = i;
			tmp--;
		}
		if (tmp == en_nu - maxi)
			break;
	}

	cout << maxi << endl;
	cout << vi[vi.size() - 1] + 1;
	for (int i = vi.size() - 2; i >= 0; i--)
		cout << " " << vi[i] + 1;
	cout << endl;

	return 0;
}