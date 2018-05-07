#include <iostream>

using namespace std;
typedef long long LL;

int K, A, B;

LL quick_exp(int x, int y)
{
	LL res = 1, ori = x;
	while (y) {
		if (y & 1)
			res *= ori;
		ori *= ori;
		y >>= 1;
	}
	return res;
}

LL work(int k ,int i) 
{
	if (i > quick_exp(2, k))
		return 0;
	if (k == 0)
		return 1;
	if (i > quick_exp(2, k - 1)) {
		return work(k - 1, i - quick_exp(2, k - 1));
	}
	else
	{
		return quick_exp(3, k - 1) + 2 * work(k - 1, i);
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int kasenum, ind = 0;
	cin >> kasenum;
	while (ind < kasenum) {
		cin >> K >> A >> B;
		LL a = work(K, A);
		LL b = work(K, B + 1);
		cout <<"Case "<<++ind<<": "<< a - b << endl;
	}
	return 0;
}