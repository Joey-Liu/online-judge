#include <iostream>
#include <string>

using namespace std;

typedef long long LL;
const LL mod = 1e+9 + 9;


LL quick_exp(LL x, LL y) {
	LL ori = x, res = 1;
	while (y) {
		if (y & 1)
			res = res * ori % mod;
		ori = ori * ori % mod;
		y >>= 1;
	}
	return res;
}


int N, a, b, K;
string str;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	cin >> N >> a >> b >> K;
	cin >> str;

	LL ak = quick_exp(a, K);
	LL ak_inv = quick_exp(ak, mod - 2);
	LL bk = quick_exp(b, K);
	LL ak_inv_bk = ak_inv * bk % mod;

	LL ele = 0, res = 0;
	for (int i = 0; i < K; i++) {
		LL ta = quick_exp(a, N - i);
		LL tb = quick_exp(b, i);
		LL tt = ta * tb % mod;
		if (str[i] == '-')
			tt = -tt;
		ele = (ele + tt + mod) % mod;
	}

	int ka = (N + 1) / K;
	if (1 == ak_inv_bk) {
		res = ka * ele % mod;
	} else {
		LL e_ra = (1 - quick_exp(ak_inv_bk, ka) + mod) % mod;
		LL e_ar = quick_exp(1 - ak_inv_bk, mod - 2);
		res = e_ra * e_ar % mod;
		res = (res * ele % mod + mod) % mod;
	}
	cout << res << endl;
	return 0;
}