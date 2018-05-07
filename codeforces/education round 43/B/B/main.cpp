#include <iostream>

using namespace std;

typedef long long LL;
LL row, col, K;

int main()
{
	cin >> row >> col >> K;
	K += 1;

	if (K <= row) {
		cout << K << " " << 1 << endl;
	}
	else {
		K -= row;
		LL r = K / (col - 1);
		LL c = K % (col - 1);
		LL tc = c;

		if (c == 0) {
			r--;
		}
		cout << row - r << " ";
		if (0 == c) {
			if (r % 2)
				cout << 2;
			else
				cout << col;
		}
		else {
			if (r % 2)
				cout << col - c + 1;
			else
				cout << 1 + c;
		}
	}
	cin >> row;
	return 0;
}