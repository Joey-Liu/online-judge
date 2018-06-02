#include <iostream>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		int n1 = p.size(), n2 = s.size();
		char *ss = new char[n2 + 2];
		char *pp = new char[n1 + 2];

		strcpy(ss + 1, s.c_str());
		strcpy(pp + 1, p.c_str());
		vector<bool *> dp(n1 + 1);
		for (int i = 0; i < dp.size(); i++) {
			dp[i] = new bool[n2 + 1];
		}

		dp[0][0] = true;
		for (int i = 1; i <= n2; i++)
			dp[0][i] = false;
		for (int i = 1; i <= n1; i++) {
			if (dp[i - 1][0] && pp[i] == '*') {
				dp[i][0] = true;
			}
			else {
				dp[i][0] = false;
			}
		}


		for (int i = 1; i <= n1; i++) {
			for (int j = 1; j <= n2; j++) {
				bool flag = false;
				if (dp[i - 1][j - 1]) {
					if (pp[i] == ss[j]) {
						flag = true;
					}
					else if (pp[i] == '?' || pp[i] == '*') {
						flag = true;
					}
				}
				if (dp[i - 1][j] && pp[i] == '*') {
					flag = true;
				}
				if (dp[i][j - 1] && pp[i] == '*') {
					flag = true;
				}
				dp[i][j] = flag;
			}//for int j
		}//for int i

		cout << " " << s << endl << endl;
		for (int i = 0; i <= n1; i++) {
			for (int j = 0; j <= n2; j++) {
				cout << dp[i][j];
			}
			cout << endl;
		}

		return dp[n1][n2];
	}
};

int main()
{
	string s1 = "aaabaaabaabababbabababaababbabbbbaaaaababbaabbbaab";
	string s2 = "*babbbb*aab**b*bb*aa*";

	Solution so;
	cout<<so.isMatch(s1, s2);
	int a;
	cin >> a;
	return 0;
}