#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;

const int maxn = 1000 + 50;
struct Mat {
	int a, b;
};
Mat mats[maxn];
int tab[maxn][maxn], N;
int dp[maxn];

bool check(Mat y, Mat x) 
{
	if ((x.a < y.a && x.b < y.b) || (x.a < y.b && x.b < y.a))
		return true;
	return false;
}

int work(int ind) 
{
	if (dp[ind] != -1)
		return dp[ind];

	int ans = 1;
	for (int i = 0; i < N; i++) {
		if (tab[ind][i]) {
			ans = max(ans, 1 + work(i));
		}
	}
	return dp[ind] = ans;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int kasenum;
	cin >> kasenum;
	while (kasenum--) {
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> mats[i].a >> mats[i].b;
		
		memset(tab, 0, sizeof(tab));
		memset(dp, -1, sizeof(dp));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (check(mats[i], mats[j]))
					tab[i][j] = 1;
			}
		}
		
		int ans = -1;
		for (int i = 0; i < N; i++) {
			ans = max(ans, work(i));
		}
		cout << ans << endl;
	}//while kasenum
	return 0;
}