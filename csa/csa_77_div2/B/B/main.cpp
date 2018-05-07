#include <iostream>
#include <iomanip>

using namespace std;
typedef long long LL;


int main() {
	LL a, b, K;
	cin >> a >> b >> K;
	if (a > b)
		swap(a, b);

	LL dis = b - a;
	if (dis >= K)
		a += K;
	else {
		a = b;
		K -= dis;
		a += K / 2;
		b += K / 2;
		if (K % 2)
			a++;
	}
	cout.setf(ios::fixed);
	cout << setprecision(6) << double(a * b)  / 2.0 << endl;
	cin >> a;
	return 0;
}