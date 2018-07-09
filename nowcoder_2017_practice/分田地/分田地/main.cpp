#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <memory.h>

using namespace std;

const int maxn = 75 + 50;

int tab[maxn][maxn], sum[maxn][maxn];
int N, M;
char str[maxn];

int get_area(int x1, int y1, int x2, int y2) {
	return sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1];
}

bool work(int tar) {
	for (int i = 1; i <= M - 3; i++) {
		for (int j = i + 1; j <= M - 2; j++) {
			for (int k = j + 1; k <= M - 1; k++) {

				int prev = 0, cnt = 0;
				for (int p = 1; p <= N; p++) {
					int a1 = get_area(prev + 1, 1, p, i);
					int a2 = get_area(prev + 1, i + 1, p, j);
					int a3 = get_area(prev + 1, j + 1, p, k);
					int a4 = get_area(prev + 1, k + 1, p, M);

					if (a1 >= tar && a2 >= tar && a3 >= tar && a4 >= tar) {
						cnt++;
						int tmp = prev;
						prev = p;

						if (cnt >= 4)
							return true;
					}
				}


			}
		}
	}
	return false;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	while (cin >> N >> M) {

		memset(tab, 0, sizeof(tab));
		memset(sum, 0, sizeof(sum));

		for (int i = 1; i <= N; i++) {
			cin >> str + 1;
			for (int j = 1; j <= M; j++) {
				tab[i][j] = str[j] - '0';
			}
		}//for int i

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				sum[i][j] = sum[i - 1][j] + sum[i][j - 1] + tab[i][j] - sum[i - 1][j - 1];
			}
		}

		int lp = 0, rp = sum[N][M] + 1;
		while (lp < rp) {
			int mid = (lp + rp) / 2;
			if (work(mid))
				lp = mid + 1;
			else
				rp = mid;
		}
		cout << lp - 1 << endl;
	}//while cin
	return 0;
}
