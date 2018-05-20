#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <memory.h>
using namespace std;


const int maxn = 1e+6 + 10;
int f[maxn];
int N, M;
int c[maxn], v[maxn], prefix[maxn];


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int kasenum = 0;
	cin >> kasenum;
	while (kasenum--) {
		memset(f, 0, sizeof(f));
		memset(prefix, 0, sizeof(prefix));
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			cin >> c[i] >> v[i];
		}//for int i

		for (int i = N - 1; i >= 0; i--) {
			prefix[i] = c[i] + prefix[i + 1];
		}
		
		for (int i = 0; i < N; i++) {
			int vv = max(M - prefix[i + 1], c[i]);
			for (int j = M; j >= vv; j--) {
				f[j] = max(f[j], f[j - c[i]] + v[i]);
			}
		}


		cout << "Max experience: " << f[M] << endl;
	}
	return 0;
}