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
#include <math.h>
#include <functional>
#include <limits.h>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;

const int maxn = 1000 + 5;
int cnt[maxn], N;
int mat[20 + 5][20 + 5];
bool flag = false;

int valid_4() {
	for (int i = 1; i < maxn; i++) {
		if (cnt[i] >= 4)
			return i;
	}
	return -1;
}

int valid_2() {
	for (int i = 1; i < maxn; i++) {
		if (cnt[i] >= 2)
			return i;
	}
	return -1;
}

	
void work() {
	for (int i = 0; i < N / 2; i++) {
		for (int j = 0; j < N / 2; j++) {
			int c = valid_4();
			if (c < 0)
				return;
			mat[i][j] = c; mat[i][N - 1 - j] = c;
			mat[N - 1 - i][j] = c; mat[N - 1 - i][N - 1 - j] = c;
			cnt[c] -= 4;
		}//for int j
	}//for int i
	if (N % 2) {
		for (int i = 0; i < N / 2; i++) {
			int c = valid_2();
			if (c < 0)
				return;
			mat[i][N / 2] = c;
			mat[N - 1 - i][N / 2] = c;
			cnt[c] -= 2;
		}//for int i

		for (int j = 0; j < N / 2; j++) {
			int c = valid_2();
			if (c < 0)
				return;
			mat[N / 2][j] = c;
			mat[N / 2][N - 1 - j] = c;
			cnt[c] -= 2;
		}

		for (int k = 0; k < maxn; k++) {
			if(cnt[k]) {
				mat[N / 2][N / 2] = k;
				break;
			}
		}
	}
	flag = true;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N * N; i++) {
		int tmp; cin >> tmp;
		++cnt[tmp];
	}
	work();
	if (!flag) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N - 1; j++) {
				cout << mat[i][j] << " ";
			}//for int j
			cout << mat[i][N - 1] << endl;
		}//for int i
	}
	

	return 0;
}