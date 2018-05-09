#include <iostream>
#include <memory.h>

using namespace std;

const int maxn = 99 + 10;
bool tab[4][maxn];
int N, K;

void work()
{
	memset(tab, false, sizeof(tab));
	if (K % 2) {
		tab[1][N / 2] = true;
		K--;
	}

	for (int i = 1; (N / 2 - i >= 1) && K > 0; i++) {
		int a = N / 2 - i, b = N / 2 + i;
		tab[1][a] = true; tab[1][b] = true;
		K -= 2;
	}

	for (int i = 1; (N / 2 - i >= 1) && K > 0; i++) {
		int a = N / 2 - i, b = N / 2 + i;
		tab[2][a] = true; tab[2][b] = true;
		K -= 2;
	}
	if (K) {
		K--;
		tab[1][N / 2] = true;
		tab[2][N / 2] = true;
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> N >> K;
	work();
	cout << "YES" << endl;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < N; j++) {
			if (tab[i][j])
				cout << "#";
			else
				cout << ".";
		}
		cout << endl;
	}
	return 0;
}