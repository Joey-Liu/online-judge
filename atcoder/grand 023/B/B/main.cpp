#include <iostream>
#include <stdio.h>

using namespace std;

const int maxn = 300 + 10;
char tab[maxn][maxn];
char tab2[maxn][maxn];

int N;

bool check(int b) 
{
	for (int i = 0; i < N; i++) {
		for (int ind = 0; ind < N; ind++) {
			int j = (b + ind) % N;
			tab2[i][ind] = tab[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (tab2[i][j] != tab2[j][i])
				return false;
		}
	}
	return true;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		cin >> tab[i];
	}

	for (int i = 0; i < N; i++) {
		if (check(i))
			ans += N;
	}
	cout << ans << endl;
	return 0;
}