#include <iostream>
#include <memory.h>

using namespace std;
const int maxn = 1000 + 5;

bool exist[maxn];
int X;

int quick_exp(int x, int y) {
	int ori = x, res = 1;
	while (y) {
		if (y & 1)
			res *= ori;
		ori *= ori;
		y >>= 1;
	}
	return res;
}

void work(int p) {
	int x = 1, res = 1;
	while (res < maxn) {
		exist[res] = true;
		x++;
		res = quick_exp(x, p);
	}
}

void init()
{
	for (int i = 2; i <= 10; i++) {
		work(i);
	}
}

int main()
{
	
	cin >> X;
	memset(exist, false, sizeof(exist));
	init();
	int res = -1;
	for (int i = X; i >= 0; i--) {
		if (exist[i]) {
			res = i;
			break;
		}
	}
	cout << res << endl;
	cin >> X;
	return 0;
}