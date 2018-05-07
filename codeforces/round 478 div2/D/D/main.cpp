#include <iostream>
#include <map>

typedef long long LL;

using namespace std;

int main()
{
	int N, A, B;
	cin >> N >> A >> B;
	map<LL, LL> mii;
	map<pair<LL, LL>, LL> mpi;

	LL ans = 0;
	for (int i = 0; i < N; i++) {
		LL x, vx, vy;
		cin >> x >> vx >> vy;
		ans += (mii[A * vx - vy] - mpi[{vx, vy}]);
		mii[A * vx - vy]++;
		mpi[{vx, vy}]++;
	}
	cout << 2 * ans << endl;
	return 0;
}