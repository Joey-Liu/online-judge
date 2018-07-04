#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

typedef long double LD;
const int maxn = 5000 + 10;

int N, Q;

int work(map<int, int> tab, int b) {
	vector<int> bin;
	while (b) {
		bin.push_back(b % 2);
		b /= 2;
	}
	reverse(bin.begin(), bin.end());

	int len = bin.size(), ans = 0;
	for (int i = 0; i < len; i++) {
		int j = len - 1 - i;
		if (tab[j] >= bin[i]) {
			ans += bin[i];
		}
		else {
			if (i == len - 1)
				return -1;
			bin[i] -= tab[j];
			ans += tab[j];
			bin[i + 1] += bin[i] * 2;
		}
	}

	if (bin[len - 1] > tab[0])
		return -1;
	return ans;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	map<int, int> tab;
	cin >> N >> Q;
	for (int i = 0; i < N; i++) {
		int a, k =0;
		cin >> a;
		while (a) {
			k++;
			a >>= 1;
		}
		tab[k - 1]++;
	}

	for (int i = 0; i < Q; i++) {
		int b;
		cin >> b;
		int ans = work(tab, b);
		cout << ans << endl;
	}

	return 0;
}