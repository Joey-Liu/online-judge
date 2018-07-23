#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>

using namespace std;
const int maxn = 100 + 50;

int dp[maxn][maxn], N;
string str;

bool match(char c1, char c2) {
	if (c1 == '(' && c2 == ')')
		return true;
	if (c1 == '[' && c2 == ']')
		return true;
	return false;
}

string print(int i, int j) {
	if (i > j)
		return "";
	if (i == j) {
		if (str[i] == '(' || str[i] == ')')
			return "()";
		else
			return "[]";
	}
	
	
	if (match(str[i], str[j]) && dp[i + 1][j - 1] == dp[i][j]) {
		if(str[i] == '[')
			return "[" + print(i + 1, j - 1) + "]";
		return "(" + print(i + 1, j - 1) + ")";
	}

	int a = dp[i][j];
	for (int k = i; k < j; k++) {
		if (dp[i][j] == dp[i][k] + dp[k + 1][j])
			return print(i, k) + print(k + 1, j);
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int kasenum;
	char ch;
	cin >> kasenum;
	cin.get(ch);
	while (kasenum--) {
		cin.get(ch);
		getline(cin, str);
		memset(dp, 0, sizeof(dp));
		N = str.size();

		for (int i = 0; i < N; i++) {
			dp[i][i] = 1;
		}

		for (int len = 2; len <= N; len++) {
			for (int i = 0; i <= N - len; i++) {
				int j = i + len - 1;
				int tmp_min = 0x3f3f3f3f;
				if (match(str[i], str[j])) {
					tmp_min = dp[i + 1][j - 1];
				}
				
				for	(int k = i; k < j; k++) {
					tmp_min = min(tmp_min, dp[i][k] + dp[k + 1][j]);
				}

				dp[i][j] = tmp_min;
			} // for int i
		}//for int len
		if (!N)
			cout << "" << endl;
		else
			cout << print(0, N - 1) << endl;
		if (kasenum)
			cout << endl;

	}
	return 0;
}