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

const int maxn = 9;
string sudo[maxn + 1];

void work() {

	for (int i = 0; i < 3; i++) {
		int base_row = i * 3;
		int base_col = i;
		for (int j = 0; j < 3; j++) {
			int row = base_row + j;
			int col = base_col + 3 * j;
			if (row != col || row != 4) {
				int r = i * 3 + 1;
				int c = j * 3 + 1;
				sudo[row][col] = sudo[r][c];
			}
			else {
				sudo[row][col] = sudo[row + 1][col];
			}

		}//for int j
	}// for int i
}


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int kasenum;
	cin >> kasenum;
	while (kasenum--) {
		for (int i = 0; i < 9; i++) {
			cin >> sudo[i];
		}
		work();
		
		for (int i = 0; i < 9; i++) {
			cout << sudo[i] << endl;
		}
	}//while

	return 0;
}