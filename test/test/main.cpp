#include <iostream>
using namespace std;


const int mode = 1e9 + 7;
int power_func(int a, int b) {
	int res = 1, cur = 1, multi = a;
	while (b != 0) {
		if (b & 1) {
			res *= multi;
			res %= mode;
		}
		multi *= multi;
		multi %= mode;

		b >>= 1;
	}
	return res;
}

int main() {
	int a = power_func(2, 10);
	cout << a << endl;
}