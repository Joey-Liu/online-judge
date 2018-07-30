#include <string>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <stack>
#include <string.h>

using namespace std;

class Solution {
public:
	int calculate(string s) {
		int N = s.size();
		int ind = 0, result = 0;
		stack<int> sta;

		int num = 0, sign = 1;
		while (ind < N) {

			if (isdigit(s[ind])) {
				num = num * 10 + s[ind] - '0';
			}
			else if (s[ind] == '+') {
				result += sign * num;
				sign = 1;
				num = 0;
			}
			else if (s[ind] == '-') {
				result += sign * num;
				sign = -1;
				num = 0;
			}
			else if ('(' == s[ind]) {
				sta.push(result);
				sta.push(sign);
				result = 0;
				sign = 1;
			}
			else if (')' == s[ind]) {
				result += sign * num;
				result *= sta.top(); sta.pop();
				result += sta.top(); sta.pop();
				//num = 0;
				//sign = 1;
			}
			ind++;
		}//while
		if (num != 0)
			result += sign * num;
		return result;
	}
};

int main() {
	Solution sol;
	string s = "3-(5-(8)-(2+(9-(0-(8-(2))))-(4))-(4))";
	int a = sol.calculate(s);
	cout << a << endl;
	return 0;
}