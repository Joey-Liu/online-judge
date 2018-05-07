#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 200 + 10;
const int msn = 50 + 10;

int dp[maxn][msn];
int t[msn];
int has_train[maxn][msn][2]; //0 for right, 1 for left;

int N, T, M1, M2;

void init()
{
	cin >> T;
	for (int i = 0; i < N - 1; i++)
		cin >> t[i];

	memset(has_train, 0, sizeof(has_train));
	cin >> M1;
	for (int i = 0; i < M1; i++) {
		int tmp;
		cin >> tmp;
		has_train[tmp][0][0] = 1;
		for (int j = 0; j < N - 1; j++) {
			tmp += t[j];
			if (tmp <= T)
				has_train[tmp][j + 1][0] = 1;
		}
	}

	cin >> M2;
	for (int i = 0; i < M2; i++) {
		int tmp;
		cin >> tmp;
		has_train[tmp][N - 1][1] = 1;
		for (int j = N - 1; j >= 1; j--) {
			tmp += t[j - 1];
			if (tmp <= T) {
				has_train[tmp][j - 1][1] = 1;
			}
		}
	}

}

void work()
{
	for (int i = 0; i < N; i++)
		dp[T][i] = INF;
	dp[T][N - 1] = 0;

	for (int i = T - 1; i >= 0; i--) {
		for (int j = 0; j < N; j++) {
			dp[i][j] = dp[i + 1][j] + 1;
			if (has_train[i][j][0] && j < N - 1 && i + t[j] <= T) {
				dp[i][j] = min(dp[i][j], dp[i + t[j]][j + 1]);
			}
			if (has_train[i][j][1] && j > 0 && i + t[j - 1] <= T) {
				dp[i][j] = min(dp[i][j], dp[i + t[j - 1]][j - 1]);
			}
		}
	}
}


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int kase = 0;
	while (cin >> N && N) {
		init();
		work();
		cout << "Case Number " << ++kase << ": ";
		if (dp[0][0] >= INF)
			cout << "impossible" << endl;
		else
			cout << dp[0][0] << endl;
	}//while cin>>N
	return 0;
}