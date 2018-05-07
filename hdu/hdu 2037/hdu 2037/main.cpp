#include <iostream>
#include <algorithm>

using namespace std;
const int maxn = 100 + 50;

struct TV {
	int lp, rp;
};

int N;
TV tv[maxn];
bool cmp(TV t1, TV t2) {
	if (t1.rp != t2.rp)
		return t1.rp < t2.rp;
	return t1.lp > t2.lp;
}


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	while (cin >> N && N) {
		memset(tv, 0, sizeof(tv));
		for (int i = 0; i < N; i++) {
			cin >> tv[i].lp >> tv[i].rp;
		}
		sort(tv, tv + N, cmp);
		int cnt = 0, bound = -1;
		for (int i = 0; i < N; i++) {
			if (tv[i].lp >= bound) {
				cnt++;
				bound = tv[i].rp;
			}
		}
		cout << cnt << endl;
	}//while cin>>N
	return 0;
}