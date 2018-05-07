#include <iostream>
using namespace std;

const int maxn = 100000 + 5;
int N;
int p[maxn], q[maxn];

int work()
{
	int ind = 0, st = 0, oil = 0, cnt = 0;
	while (true) {
		if (cnt >= N)
			break;
		oil += p[ind % N];
		oil -= q[ind % N];
		if (oil < 0) {
			oil = 0;
			cnt = 0;
			ind = (ind + 1) % N;
			st = ind;
		}
		else {
			cnt += 1;
			ind = (1 + ind) % N;
		}
	}//whiles
	return st;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int kasenum, indcase = 0;
	cin >> kasenum;
	while (indcase < kasenum) {
		cin >> N;
		long long tot = 0;
		for (int i = 0; i < N; i++) {
			cin >> p[i];
			tot += p[i];
		}
		for (int i = 0; i < N; i++) {
			cin >> q[i];
			tot -= q[i];
		}

		if (tot < 0)
			cout <<"Case " <<++indcase<< ": Not possible" << endl;
		else {
			int res = work();
			cout << "Case " << ++indcase << ": Possible from station " << res + 1 << endl;
		}
	}
	return 0;
}