#include <iostream>
#include <stdio.h>

using namespace std;

typedef long long LL;
const LL mod7 = 1e+9 + 7;

int main()
{
	LL N, P;
	cin >> N >> P;

	LL res = 1;
	for (int i = 1; i <= N; i++) {
		res = res * (P - i) % mod7;
	}
	cout << res << endl;
}