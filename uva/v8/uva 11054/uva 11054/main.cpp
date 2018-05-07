#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 100000 + 50;
typedef long long LL;
int N;

int main()
{
	while (cin >> N && N) {

		LL res = 0, suff = 0;
		for (int i = 0; i < N; i++) {
			int a;
			cin >> a;
			suff += a;
			res += abs(suff);
		}
		cout << res << endl;
	}
}