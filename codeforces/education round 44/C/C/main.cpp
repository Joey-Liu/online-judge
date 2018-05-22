#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;
const int maxn = 100010;
typedef long long LL;

LL N, K, L, nk;
LL sta[maxn];


int main() 
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> K >> L;
	nk = N * K;
	for (LL i = 0; i < nk; i++) {
		cin >> sta[i];
	}
	sort(sta, sta + nk);


	if (sta[N - 1] - sta[0] > L) {
		cout << "0" << endl;
	}
	else {
		LL rp_s = sta[0] + L;
		LL ind;
		for (ind = nk - 1; ind >= 0; ind--) {
			if (sta[ind] <= rp_s)
				break;
		}

		LL res = 0;
		while (nk - ind + 1 < K)
			ind--;
		LL she = nk - ind - 1;
		while (she > 0) {
			if (she < K - 1)
				break;
			res += sta[ind];
			she -= (K - 1);
			ind--;
		}//while she

		if (she > 0 && she < K - 1) {
			ind = ind - (K - she) + 1;
			res += sta[ind];
		}
		else
			ind++;

		while (ind >= 0 && ind - K >=0) {
			res += sta[ind - K];
			ind -= K;
		}
		cout << res << endl;
	}//else
	return 0;
}