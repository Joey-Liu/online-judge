#include <iostream>
#include <iomanip>
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

const int maxn = 200 + 50;
int N;

struct Node {
	double x1, x2;
	double y1, y2;
};

Node nodes[maxn];
double X[maxn << 1], Y[maxn << 1];
int x_nums, y_nums;
bool overlaped[maxn][maxn];



bool work(int i, int j) {
	double left_x, left_y, right_x, right_y;
	left_x = X[i]; left_y = Y[j];
	right_x = X[i + 1]; right_y = Y[j + 1];

	for (int k = 0; k < N; k++) {
		if (left_x >= nodes[k].x1 && right_x <= nodes[k].x2 && left_y >= nodes[k].y1 && right_y <= nodes[k].y2)
			return true;
	}
	return false;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int kasenum = 0;

	while (cin >> N && N) {
		x_nums = 0;
		y_nums = 0;
		memset(overlaped, false, sizeof(overlaped));

		for (int i = 0; i < N; i++) {
			cin >> nodes[i].x1 >> nodes[i].y1 >> nodes[i].x2 >> nodes[i].y2;
			X[x_nums++] = nodes[i].x1;
			X[x_nums++] = nodes[i].x2;
			Y[y_nums++] = nodes[i].y1;
			Y[y_nums++] = nodes[i].y2;
		}//for int i

		sort(X, X + x_nums);
		sort(Y, Y + y_nums);
		
		int xx_nums = unique(X, X + x_nums) - X;
		int yy_nums = unique(Y, Y + y_nums) - Y;
		
		double res = 0;
		for (int i = 0; i < xx_nums - 1; i++) {
			for (int j = 0; j < yy_nums - 1; j++) {
				overlaped[i][j] = work(i, j);
				if(overlaped[i][j])
					res += (X[i + 1] - X[i]) * (Y[j + 1] - Y[j]);
			}
		}

		
		if (kasenum)
			cout << endl;
		cout << "Test case #" << ++kasenum << endl;
		cout.setf(ios::fixed);
		cout << setprecision(2);
		cout << "Total explored area: " << res << endl;
	}//while

	return 0;
}