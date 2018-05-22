#include <iostream>
#include <memory.h>
using namespace std;
typedef long long LL;

struct Mat
{
	LL a[3][3];
	Mat() {
		memset(a, 0, sizeof(a));
	}

}res, ori;

Mat multi(Mat x, Mat y) {
	Mat temp;
	memset(temp.a, 0, sizeof(temp.a));

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				temp.a[i][j] += x.a[i][k] * y.a[k][j];
			}
		}
	}
	return temp;
}

bool mat_exce = false, unfair = false;

Mat quick_exp(Mat x, LL y) {
	Mat ori = x, res;

	for (int i = 0; i < 3; i++) {
		res.a[i][i] = 1;
	}

	while (y) {
		if (1 & y) {
			res = multi(res, ori);
		}
		ori = multi(ori, ori);
		if (ori.a[0][1] >= 1e18 || ori.a[0][1] < 0)
			mat_exce = true;
		y >>= 1;
	}
	return res;
}

LL A, B, C, K;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	cin >> A >> B >> C >> K;
	if (K % 2) {
		cout << B - A << endl;
	}
	else
		cout << A - B << endl;
	return 0;
}